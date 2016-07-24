# Prints all files under a given directory recursively
import sys, getopt, os
i=0
def print_dir(sPath):
    global i
    for sChild in os.listdir(sPath):
	   sChildPath = os.path.join(sPath, sChild)
	   if os.path.isdir(sChildPath):
	     print_dir(sChildPath)
	   else:
	     print i, " ", sChildPath
	     i += 1

# Note argv[0] has file name init 
def main(argv) :
   try:
	argv
	print_dir(argv[1])
   except getopt.GetoptError:
	print 'Enter Directory Name'
	sys.exit(2)

#This will help someone else can import print_dir.py, but do not call main()
# as __name__ will not evaluate to main
if __name__ == "__main__":
    sys.exit(main(sys.argv))
