#-------------------EXERCISE 13+-------------------
print "\n\nExercise 13+"

from sys import argv

script, user_name = argv
prompt = "-> "

print "Hi %s, Thanks for running %s!" % (user_name, script)
print "How are you liking me so far?: ",
likes = raw_input(prompt)

print "Where about do you live?: ",
lives = raw_input(prompt)

print "And... What type of computer do you have?: ",
computer = raw_input(prompt)

print """
You said %s about liking me. You also live at
%s, and you have a %s for a computer.
""" %(likes, lives, computer)

#-------------------EXERCISE 15+-------------------
print "\n\nExercise 15+"
#use PythonTesting.txt in examples
script, filename = argv

# close() -> cloeses the file
# read() -> reads the whole file
# readline() -> reads a single line of the file
# truncate() -> deletes teh contents of a file
# write(stuff) -> writes stuff to a file

# 'w' -> open file in Write mode
# 'r' -> open file in Read mode
# 'a' -> something about append mode
# 'X+' -> replace X with one above, makes read and write. 
#			there are differences with chars, but no idea what
#File opened in read only by default -> open(filename)
txt = open(filename, 'r+')
print txt.read()
txt.truncate()

fileContents = """
	This is the first line
	this is another line
	this one to make sure it worked
	lots of new lines after this one


	and Last line here
"""
txt.write(fileContents)

txt.close()
