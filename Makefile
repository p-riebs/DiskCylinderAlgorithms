#
# Josh Hursey
# CS 441/541: Project 5
#
#####################################################################
#
# Type "make" to compile your code
# 
# Type "make clean" to remove the executable (and any object files)
#
#####################################################################
CC=gcc
CFLAGS=-Wall -g -O0
LDFLAGS=

#
# List all of the binary programs you want to build here
# Separate each program with a single space
#
all: scheduler

#
# Disk schedule
#
scheduler: scheduler.c scheduler.h
	$(CC) -o scheduler $(CFLAGS) scheduler.c

#
# Cleanup the files that we have created
#
clean:
	$(RM) scheduler
	$(RM) -rf *.dSYM

#
# Tests
#
include given-tests/Makefile
