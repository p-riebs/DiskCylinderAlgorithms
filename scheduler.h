/*
 * Parker Riebs
 * 5/10/2015
 *
 * Takes the number of disk cylinders in the disk, the head position of a
 * hard drive, and a list of harddisk requests as inputs. Then, runs different
 * algorithms, timing how long each takes to move across the platter of the
 * hard drive.
 * Algorithms: "First-come, first served (FCFS)", Shortest-seek-time-first (SSTF),
 *             SCAN, C-SCAN, LOOK, C-LOOK
 *
 * CS 441/541: Disk Algorithm Simulator (Project 6)
 */
#include <stdio.h>
/* For atoi */
#include <stdlib.h>
/* For String operations - strlen */
#include <string.h>
/* For isdigit */
#include <ctype.h>
/* For bool type */
#include <stdbool.h>


/******************************
 * Defines
 ******************************/
// Maximum per-line length from the files
#define MAX_INPUT_LINE 1024


/******************************
 * Structures
 ******************************/


/******************************
 * Global Variables
 ******************************/


/******************************
 * Function declarations
 ******************************/
 /*
 *  Runs the First-Come-First-Serve algorithm for cylinder requests to find the
 *  seek time for the algorthithm based off a head position.
 *
 *  Parameters:
 *   current_head_pos: The current position of the head on the cylinder.
 *   cylinder_req: The cylinder requests for the head to go to.
 *   num_cylinder_req: The number of cylinder requests.
 */
int first_come_first_serve(int current_head_pos, int * cylinder_req, int num_cylinder_req);

/*
*  Runs the Shortest-Seek-Time-First algorithm for cylinder requests to find 
*  the seek time for the algorthithm based off a head position.
*
*  Parameters:
*   current_head_pos: The current position of the head on the cylinder.
*   num_cylinder: The number of disk cylinders.
*   cylinder_req: The cylinder requests for the head to go to.
*   num_cylinder_req: The number of cylinder requests.
*/
int shortest_seek_time_first(int current_head_pos, int num_cylinder, int * cylinder_req, int num_cylinder_req);

/*
*  Runs the SCAN (Elevator) algorithm for cylinder requests to find the seek 
*  time for the algorthithm based off a head position.
*
*  Parameters:
*   current_direction: The current direction of the head.
*   current_head_pos: The current position of the head on the cylinder.
*   num_cylinder: The number of disk cylinders.
*   cylinder_req: The cylinder requests for the head to go to.
*   num_cylinder_req: The number of cylinder requests.
*/
int scan_elevator(int current_direction, int current_head_pos, int num_cylinder, int * cylinder_req, int num_cylinder_req);

/*
*  Runs the CSCAN algorithm for cylinder requests to find the seek time for the
*  algorthithm based off a head position.
*
*  Parameters:
*   current_direction: The current direction of the head.
*   current_head_pos: The current position of the head on the cylinder.
*   num_cylinder: The number of disk cylinders.
*   cylinder_req: The cylinder requests for the head to go to.
*   num_cylinder_req: The number of cylinder requests.
*/
int c_scan_elevator(int current_direction, int current_head_pos, int num_cylinder, int * cylinder_req, int num_cylinder_req);

/*
*  Runs the LOOK algorithm for cylinder requests to find the seek time for the 
*  algorthithm based off a head position.
*
*  Parameters:
*   current_direction: The current direction of the head.
*   current_head_pos: The current position of the head on the cylinder.
*   num_cylinder: The number of disk cylinders.
*   cylinder_req: The cylinder requests for the head to go to.
*   num_cylinder_req: The number of cylinder requests.
*/
int look_algorithm(int current_direction, int current_head_pos, int num_cylinder, int * cylinder_req, int num_cylinder_req);

/*
*  Runs the CLOOK algorithm for cylinder requests to find the seek time for the
*  algorthithm based off a head position.
*
*  Parameters:
*   current_direction: The current direction of the head.
*   current_head_pos: The current position of the head on the cylinder.
*   num_cylinder: The number of disk cylinders.
*   cylinder_req: The cylinder requests for the head to go to.
*   num_cylinder_req: The number of cylinder requests.
*/
int clook_algorithm(int current_direction, int current_head_pos, int num_cylinder, int * cylinder_req, int num_cylinder_req);