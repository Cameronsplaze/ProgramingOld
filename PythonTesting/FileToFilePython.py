#exercise 17
#used File1.txt and File2.txt in example

from sys import argv
from os.path import exists

script, from_file, to_file = argv

print "Coping from %s to %s" % (from_file, to_file)

indata = open(from_file).read()

out_file = open(to_file, 'w')
out_file.write(indata)
print "All Done!"

#figure what to close later