#basic printing for python


#-------------------EXERCISE 6-------------------
print "\n\nExercise 6"
x = "there are %d types of people." % 10
binary = "binary"
do_not = "don't"
y = "Those who know %s and those who %s" % (binary, do_not)


print x
print y

# %r -> print raw data, for debugging
# %s -> print string, use instead of r for programs
# %d -> some type of print number?
print "I said: %r" % x
print "I also said: %s" % y

hilarious = False
joke_evaluation = "Wasn't that funny?! %r"
print joke_evaluation % hilarious

print """
string block here\n
and here, can also use '''
"""

#-------------------EXERCISE 7, 8-------------------
print "\n\nExercise 7, 8"

print "." * 10 #print 10 dots in a row '..........'
print "This will be on",
print "the same line.",
print "And apperently \nthe comma adds a space automatically..."

formatter = "%r %r %r %r"
print formatter % (1, 2, 3, 4)
print formatter % ("one", "two", "three", "four")
print formatter % (True, False, True, True)
print formatter % (formatter, formatter, formatter, formatter)
print formatter % (
		"this will be single quotes",#tried \n and didnt work. because its in ()?
		"and this will be single",
		"but this won't",
		"beause a single quote is in that string"
	)

#-------------------Escape List-------------------
# all normal ones from c++ ( \\ \n \t \" \' \f )
# \a 	bell
# \v	vertical tab
# page 39 in the book, or google it if you need more


#-------------------EXERCISE 11-------------------
print "\n\nExercise 11"

age = raw_input("How old are you?: ")
height = raw_input("And your height?: ")
weight = raw_input("and your weight?: ")

print "You're %r year(s) old, %r tall, and weight %r whatever units." % (
	age, height, weight)






