#!/bin/bash

iptables -F
iptables -X

## Drop all existing rules
iptables -P FORWARD DROP
iptables -P OUTPUT DROP
iptables -P INPUT DROP

# Allow ping
iptables -A OUTPUT -p icmp -m state --state NEW,ESTABLISHED,RELATED -j ACCEPT
iptables -A INPUT -p icmp -m state --state NEW,ESTABLISHED,RELATED -j ACCEPT

# Allow port 53 (DNS)
iptables -A OUTPUT -p udp --dport 53 -j ACCEPT
iptables -A INPUT -p udp --sport 53 -j ACCEPT

#===========================================================================

# Because iptables works on EVERYTHING
# -you normally wouldn't have to do this
iptables -A INPUT -i dns0 -j ACCEPT
iptables -A FORWARD -i dns0 -j ACCEPT

iptables -A INPUT -i lo -j ACCEPT
iptables -A FORWARD -i lo -j ACCEPT

iptables -A OUTPUT -j ACCEPT
