# CS441/541 Project 6

## Author(s):

Parker Riebs

## Date:

5/10/2015

## Description:

Takes the number of disk cylinders in the disk, the head position of a
hard drive, and a list of harddisk requests as inputs. Then, runs different 
algorithms, timing how long each takes to move across the platter of the 
hard drive.
Algorithms: "First-come, first served (FCFS)", Shortest-seek-time-first (SSTF),
            SCAN, C-SCAN, LOOK, C-LOOK

## How to build the software

Run "make" while in the scheduler.c directory.

## How to use the software

The software requires supplying a file of starting with the number of cylinders,
then the next line is the number of requests. Next, newline seperated cylinder 
requests are placed after.
The required command of "-h" is given which has the current position of the head.
The required command of "-d" is given which has the direction of the head. The 
head direction can be with 0 or 1. 0 having the head toward 0, and 1 having the
head toward the end of the cylinder.
For Example,
$ ./scheduler -h 53 -d 0 given-tests/level1.txt

## How the software was tested

The software was tested through debugging with test case files, and an overall
understanding of how harddrives find information on cylinders.

## Test Suite

test1.txt : Tests how the program calculates simple decrementing requests.
test2.txt : Tests if program only does cylinder requests with in the specified
			number in the file.
test3.txt : Tests very distant cylinder requests.
test4.txt : Tests a large amount of cylinder requests.
test5.txt : Tests if cylinder requests are all the same.

## Known bugs and problem areas

None that I know of.

