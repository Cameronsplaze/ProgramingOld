# exercise 20

from sys import argv

script, input_file = argv

def print_all(f):
	print f.read()

def rewind(f):
	f.seek(0)

#prints an int, then calls readline normally
def print_a_line(line_count, f):
	print line_count, f.readline()

def multTwoNumbers(num1, num2):
	print "multing %d and %d: " % (num1, num2)
	return num1 * num2

#using PythonReadFile.txt
current_file = open(input_file)

print "->printing whole file<-"
print_all(current_file)

print "->rewinding, printing few lines<-"
rewind(current_file)

current_line = 0

current_line += 1
print_a_line(current_line, current_file)

current_line += 1
print_a_line(current_line, current_file)

current_line += 1
print_a_line(current_line, current_file)

pruduct_sum = multTwoNumbers(6, 6)
print "\nproduct: %d" % pruduct_sum
