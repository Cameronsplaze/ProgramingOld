from sys import exit

def gold_room():
	print "This room is full of gold. How much do you take?"

	next = raw_input("-> ")
	if next.isdigit():
		how_much = int(next)
	else:
		dead("You lost. Type a real number next time.")

	if how_much < 22:
		print "Nice, not too greedy. You Win!"
		exit(0)
	else:
		dead("You Died, greedy bastard!")

def bear_room():
	print """
		There is a bear in here.
		The bear has a bunch of honey.
		The fat bear is in front of another door.
		How are you going to move the bear?
		(take honey, taunt bear, open door)
	"""
	bear_moved = False;

	while True:
		next = raw_input("-> ")
		if next == "take honey":
			dead("The bear looks at you then slaps your face off.")
		elif next == "taunt bear" and not bear_moved:
			print "The bear moved, you can go through if you want."
			bear_moved = True
		elif next == "taunt bear" and bear_moved:
			dead("You piss off the bear and it chews your leg off.")
		elif next == "open door" and not bear_moved:
			dead("The bear is in front if it. You dead biatch!")
		elif next == "open door" and bear_moved:
			gold_room()
		else:
			print "No idea what that is. Try again"

def cthulhu_room():
	print """
		Here you see the great master Cthulhu.
		He, she, it, whatever stares at you and you go insane.
		Do you flee for your life or eat your head?
	"""

	next = raw_input("-> ")
	if "flee" in next:
		start()
		exit(0)
	elif "head" in next:
		dead("That was more tasty than expected!")
	else:
		cthulhu_room()
		exit(0)

def dead(why):
	print why, "good job!"
	exit(0)

def start():
	print """
		You anre in a dark room with two doors.
		One to your left, one to the right.
		Which do you take?
	"""
	next = raw_input("-> ")
	if "left" in next:
		bear_room()
	elif "right" in next:
		cthulhu_room()
	else:
		dead("Direction not found. You stumble around until you die of starvation")


start()
