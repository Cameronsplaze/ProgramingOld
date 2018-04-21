#!/bin/bash

iptables -F
iptables -X

iptables -P FORWARD ACCEPT
iptables -P OUTPUT ACCEPT
iptables -P INPUT ACCEPT

