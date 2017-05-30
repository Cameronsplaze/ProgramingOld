# Exercise 19
def cheese_and_crackers(cheese_count, boxes_of_crackers):
	print "you have %d cheeses!" % (cheese_count)
	print "you have %d boxes of crackers!\n" % (boxes_of_crackers)

def printTwoVariablesWtihList(*args):
	arg1, arg2 = args
	print "first arg: %s\nsecond arg: %s" % (arg1, arg2)
	




print "passing 20 and 30 directly"
cheese_and_crackers(20, 30)

print "passing variables with bad names"
var1 = 20
var2 = 30
cheese_and_crackers(var1, var2)

print "combining the two, should be 120, 130"
cheese_and_crackers(var1 + 100, var2 +100)

print "testing printing list"
printTwoVariablesWtihList("icecream", "pizza")
