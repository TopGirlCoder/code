# This makefile is used as follows to regenerate files for the poly program:
#   make poly.o   --  Regenerates poly.o by compiling
#   make polytest.o   --  Regenerates polytest.o by compiling
#   make polytest --  Regenerates the executable polytest file by compiling
#   make              --  Same as "make polytest" (since polytest is 
#                     --  the 1st target)
#   make polyexam.o   --  Regenerates polyexam.o by compiling
#   make polyexam --  Regenerates the executable polyexam file by compiling
#   make              --  Same as "make polyexam" (since polyexam is 
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
EXPENDABLES = poly.o polytest.o polytest polyexam.o polyexam

# make all is listed first, which lets you type "make" to recompile 
# anything that has changed in either your class, your test code, 
# or my test code.
all:
	@make $(EXPENDABLES)

# this compiles your test program and your poly class together
polytest: polytest.o poly.o
	g++ -Wall -g poly.o polytest.o -lm -o polytest 

# this compiles your test program and your poly class together
polyexam: polyexam.o poly.o
	g++ -Wall -g poly.o polyexam.o -lm -o polyexam 

# this compiles your poly class, which isn't executable (no main)
poly.o: poly.h poly.cxx
	g++ -Wall -g -c poly.cxx -o poly.o

# this compiles your test program, which is executable
polytest.o: poly.h polytest.cxx
	g++ -Wall -g -c polytest.cxx -o polytest.o

# this compiles your test program, which is executable
polyexam.o: poly.h polyexam.cxx
	g++ -Wall -g -c polyexam.cxx -o polyexam.o

# this deletes all the output files
clean:
	rm $(EXPENDABLES)
