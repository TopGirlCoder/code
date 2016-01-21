# This makefile is used as follows to regenerate files for the BSTreeBag program:
#   make BSTreeBag.o   --  Regenerates BSTreeBag.o by compiling
#   make BSTreeBagTest.o   --  Regenerates BSTreeBagTest.o by compiling
#   make BSTreeBagTest --  Regenerates the executable BSTreeBagTest file by compiling
#   make              --  Same as "make BSTreeBagTest" (since BSTreeBagTest is 
#                     --  the 1st target)
#   make BSTreeBagExam.o   --  Regenerates BSTreeBagExam.o by compiling
#   make BSTreeBagExam --  Regenerates the executable BSTreeBagExam file by compiling
#   make              --  Same as "make BSTreeBagExam" (since BSTreeBagExam is 
#                     --  the 1st target)
#
# Two special targets may also be used with this makefile:
#   make all          --  Regenerates all files listed above
#   make clean        --  Erases all files listed above
#
# All compilations occur with -Wall to print warnings, and -g to allow gdb debugging.
# The clean command uses rm to remove all expendable files (rm is part of
# the cs1300 compiler tools from www.cs.colorado.edu/~main/cs1300/README.html).

# define the different outputs of all g++ commands
# on Ubuntu, the .exe suffix disappears
EXPENDABLES = BSTreeBagTest.o BSTreeBagTest BSTreeBagExam.o BSTreeBagExam

# make all is listed first, which lets you type "make" to recompile 
# anything that has changed in either your class, your test code, 
# or my test code.
all:
	@make $(EXPENDABLES)

# this compiles your test program and your BSTreeBag class together
BSTreeBagTest: BSTreeBagTest.o 
	g++ -Wall -g BSTreeBagTest.o -lm -o BSTreeBagTest 

# this compiles your test program and your BSTreeBag class together
BSTreeBagExam: BSTreeBagExam.o 
	g++ -Wall -g BSTreeBagExam.o -lm -o BSTreeBagExam 

# this compiles your test program, which is executable
BSTreeBagTest.o: BSTreeBag.h BSTreeBag.cxx BSTreeBagTest.cxx bintree.h bintree.cxx 
	g++ -Wall -g -c BSTreeBagTest.cxx -o BSTreeBagTest.o

# this compiles your test program, which is executable
BSTreeBagExam.o: BSTreeBag.h BSTreeBag.cxx BSTreeBagExam.cxx bintree.h bintree.cxx 
	g++ -Wall -g -c BSTreeBagExam.cxx -o BSTreeBagExam.o

# this deletes all the output files
clean:
	rm $(EXPENDABLES)
