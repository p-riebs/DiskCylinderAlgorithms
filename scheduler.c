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
#include "scheduler.h"

int main(int argc, char **argv) {

    FILE * file = NULL;
    char line[MAX_INPUT_LINE];
    int i;
    char * filename = NULL;
    int current_head_pos = -1;
    int current_direction = -1;
    int num_cylinder = 0;
    int num_cylinder_req = 0;
    int * cylinder_req;

    // Keeps track of seek times for algorthims.
    int FCFS = 0;
    int SSTF = 0;
    int SCAN = 0;
    int CSCAN = 0;
    int LOOK = 0;
    int CLOOK = 0;

    // Process out of order parameters
    for (i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-h") == 0 && argc > i + 1 
            && !isalpha(argv[i + 1][0]) && strcmp(argv[i+1], "-d") != 0)
        {
            current_head_pos = atoi(argv[i + 1]);
            i++;
        }
        else if (strcmp(argv[i], "-d") == 0 && argc > i + 1 && isdigit(argv[i +1][0]))
        {
            current_direction = atoi(argv[i + 1]);
            i++;
        }
        // Show error messages for incorrect arguments.
        else if (strcmp(argv[i], "-h") == 0)
        {
            printf("Error: Must supply an integer argument greater than 0 for the -h option.\n");
            exit(0);
        }
        else if (strcmp(argv[i], "-d") == 0)
        {
            printf("Error: Must supply a direction of travel.\n");
            exit(0);
        }
        else
        {
            filename = argv[i];
        }
    }

    // Argument error check.
    if (filename == NULL)
    {
        printf("Error: Did not supply a scheduler file.\n");
        exit(0);
    }
    else if (current_direction == -1 && current_head_pos == -1)
    {
        printf("Error: Must supply the -h and -d options.\n");
        exit(0);
    }
    else if (current_head_pos == -1)
    {
        printf("Error: Must supply the -h option.\n");
        exit(0);
    }
    else if (current_direction == -1)
    {
        printf("Error: Must supply the -d option.\n");
        exit(0);
    }

    if (current_direction != 0 && current_direction != 1)
    {
        printf("Error: The current direction of the disk head must be 0 or 1.\n");
        exit(0);
    }

    // Open the file to be read.
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: Unable to open file %s\n", filename);
        exit(0);
    }

    fgets(line, MAX_INPUT_LINE, file);
    // Get the number of cylinders
    num_cylinder = atoi(line);
    fgets(line, MAX_INPUT_LINE, file);
    // Get the number of cylinder requests.
    num_cylinder_req = atoi(line);

    // More error messages for incorrect arguments.
    if (current_head_pos > num_cylinder || current_head_pos < 0)
    {
        printf("Error: Must supply an integer argument greater than 0 and less than the number of cylinders on the disk for the -h option. This disk has %d cylinders", num_cylinder);
        exit(0);
    }

    // Add cylinder requests from file to array.
    cylinder_req = malloc(num_cylinder_req * sizeof(int));
    for (i = 0; i < num_cylinder_req; i++)
    {
        fgets(line, MAX_INPUT_LINE, file);
        cylinder_req[i] = atoi(line);
    }

    // Print cylinder information.
    printf("#-------------------------------\n");
    printf("# Queue File          : %s\n", filename);
    printf("# Num. Disk Cylinders : %2d\n", num_cylinder);
    printf("# Head Position       : %2d\n", current_head_pos);
    if (current_direction == 0)
    {
        printf("# Head Direction      : Toward 0\n");
    }
    else
    {
        printf("# Head Direction      : Toward last cylinder\n");
    }
    printf("#-------------------------------\n");

    // Go through each algorithm and get seek time from each.
    FCFS = first_come_first_serve(current_head_pos, cylinder_req, num_cylinder_req);
    SSTF = shortest_seek_time_first(current_head_pos, num_cylinder, cylinder_req, num_cylinder_req);
    SCAN = scan_elevator(current_direction, current_head_pos, num_cylinder, cylinder_req, num_cylinder_req);
    CSCAN = c_scan_elevator(current_direction, current_head_pos, num_cylinder, cylinder_req, num_cylinder_req);
    LOOK = look_algorithm(current_direction, current_head_pos, num_cylinder, cylinder_req, num_cylinder_req);
    CLOOK = clook_algorithm(current_direction, current_head_pos, num_cylinder, cylinder_req, num_cylinder_req);

    // Output seek times
    printf("#   %5d      FCFS\n", FCFS);
    printf("#   %5d      SSTF\n", SSTF);
    printf("#   %5d      SCAN\n", SCAN);
    printf("#   %5d      C-SCAN\n", CSCAN);
    printf("#   %5d      LOOK\n", LOOK);
    printf("#   %5d      C-LOOK\n", CLOOK);

    // Clean up
    free(cylinder_req);
    cylinder_req = NULL;

    return 0;
}

int first_come_first_serve(int current_head_pos, int * cylinder_req, int num_cylinder_req)
{
    int fcfs_total = 0;
    int head_pos = current_head_pos;
    int i;

    // Go through each cylinder request and add them to seek time.
    for (i = 0; i < num_cylinder_req; i++)
    {
        fcfs_total += abs(head_pos - cylinder_req[i]);
        head_pos = cylinder_req[i];
    }

    return fcfs_total;
}

int shortest_seek_time_first(int current_head_pos, int num_cylinder, int * cylinder_req, int num_cylinder_req)
{
    int i = 0;
    int j = 0;
    int * sstf_request_order = malloc(sizeof(int) * num_cylinder_req);
    int head_pos = current_head_pos;
    int closest_pos = num_cylinder;
    int closest_idx = 0;
    int sstf_total = 0;

    // Make copy of cylinder requests, so the copy can be changed.
    memcpy(sstf_request_order, cylinder_req, sizeof(int) * num_cylinder_req);

    // Go through each cylinder request, and find the closest cylinder request
    // from the current request.
    for (i = 0; i < num_cylinder_req; i++)
    {
        for (j = 0; j < num_cylinder_req; j++)
        {
            // If the cylinder request has already be calculated don't use.
            if (sstf_request_order[j] != -1)
            {
                if (closest_pos > abs(head_pos - sstf_request_order[j]))
                {
                    closest_idx = j;
                    closest_pos = abs(head_pos - sstf_request_order[j]);
                }
            }
        }

        // Found the closest request, add it to seek time, move to next
        // request.
        head_pos = sstf_request_order[closest_idx];
        sstf_request_order[closest_idx] = -1;
        sstf_total += closest_pos;

        closest_pos = num_cylinder;
    }

    // Clean up
    free(sstf_request_order);
    sstf_request_order = NULL;

    return sstf_total;
}

int scan_elevator(int current_direction, int current_head_pos, int num_cylinder, int * cylinder_req, int num_cylinder_req)
{
    int i = 0;
    int * scan_request_order = malloc(sizeof(int) * num_cylinder_req);
    int scan_direction = current_direction;
    int head_pos = current_head_pos;
    int difference_total = num_cylinder;
    int next_idx = -1;
    int reqs_finished = 0;
    int scan_total = 0;

    // Make copy of cylinder requests, so the copy can be changed.
    memcpy(scan_request_order, cylinder_req, sizeof(int) * num_cylinder_req);

    // Make sure all the cylinder requests have been sought after
    while (reqs_finished < num_cylinder_req)
    {
        next_idx = -1;
        difference_total = num_cylinder;
        for (i = 0; i < num_cylinder_req; i++)
        {
            // Don't process requests that are already used.
            if (scan_request_order[i] != -1)
            {
                // If seeking is going towards 0, and is the closest to the 
                // current point, and is positive number, this could possibly
                // be the next request.
                if (   scan_direction == 0
                    && difference_total > abs(head_pos - scan_request_order[i])
                    && head_pos - scan_request_order[i] >= 0)
                {
                    next_idx = i;
                    difference_total = abs(head_pos - scan_request_order[i]);
                }
                else if 
                (
                       scan_direction == 1
                    && difference_total > abs(head_pos - scan_request_order[i])
                    && head_pos - scan_request_order[i] <= 0
                )
                {
                    next_idx = i;
                    difference_total = abs(head_pos - scan_request_order[i]);
                }
            }
        }

        // If there was no next request, move in the opposite direction, and
        // move the current head position.
        if (next_idx == -1)
        {
            if (scan_direction == 0)
            {
                scan_total += head_pos;
                head_pos = 0;
                scan_direction = 1;
            }
            else if (scan_direction == 1)
            {
                scan_total += abs(head_pos - (num_cylinder - 1));
                head_pos = num_cylinder - 1;
                scan_direction = 0;
            }
        }
        // Found next request, add to seek time.
        else
        {
            scan_total += difference_total;
            head_pos = scan_request_order[next_idx];
            scan_request_order[next_idx] = -1;
            reqs_finished++;
        }
    }

    // Clean up
    free(scan_request_order);
    scan_request_order = NULL;

    return scan_total;
}

int c_scan_elevator(int current_direction, int current_head_pos, int num_cylinder, int * cylinder_req, int num_cylinder_req)
{
    int i = 0;
    int difference_total = num_cylinder;
    int next_idx = -1;
    int reqs_finished = 0;
    int cscan_total = 0;
    int head_pos = current_head_pos;
    int cscan_direction = current_direction;
    int * cscan_request_order = malloc(sizeof(int) * num_cylinder_req);

    // Make copy of cylinder requests, so the copy can be changed.
    memcpy(cscan_request_order, cylinder_req, sizeof(int) * num_cylinder_req);

    // Make sure all the cylinder requests have been sought after
    while (reqs_finished < num_cylinder_req)
    {
        next_idx = -1;
        difference_total = num_cylinder;
        for (i = 0; i < num_cylinder_req; i++)
        {
            // Don't process requests that are already used.
            if (cscan_request_order[i] != -1)
            {
                // If seeking is going towards 0, and is the closest to the 
                // current point, and is positive number, this could possibly
                // be the next request.
                if (cscan_direction == 0
                    && difference_total > abs(head_pos - cscan_request_order[i])
                    &&  head_pos - cscan_request_order[i] >= 0)
                {
                    next_idx = i;
                    difference_total = abs(head_pos - cscan_request_order[i]);
                }
                else if (cscan_direction == 1
                    && difference_total > abs(head_pos - cscan_request_order[i])
                    && head_pos - cscan_request_order[i] <= 0)
                {
                    next_idx = i;
                    difference_total = abs(head_pos - cscan_request_order[i]);
                }
            }
        }

        // If there was no next request, move the current head position.
        if (next_idx == -1)
        {
            cscan_total += num_cylinder - 1;
            if (cscan_direction == 0)
            {
                cscan_total += head_pos;
                head_pos = num_cylinder - 1;
            }
            else
            {
                cscan_total += abs(head_pos - (num_cylinder - 1));
                head_pos = 0;
            }
        }
        // Found next request, add to seek time.
        else
        {
            cscan_total += difference_total;
            head_pos = cscan_request_order[next_idx];
            cscan_request_order[next_idx] = -1;
            reqs_finished++;
        }

    }

    // Clean up
    free(cscan_request_order);
    cscan_request_order = NULL;

    return cscan_total;
}

int look_algorithm(int current_direction, int current_head_pos, int num_cylinder, int * cylinder_req, int num_cylinder_req)
{
    int i = 0;
    int difference_total = num_cylinder;
    int next_idx = -1;
    int reqs_finished = 0;
    int look_total = 0;
    int head_pos = current_head_pos;
    int look_direction = current_direction;
    int * look_request_order = malloc(sizeof(int) * num_cylinder_req);

    // Make copy of cylinder requests, so the copy can be changed.
    memcpy(look_request_order, cylinder_req, sizeof(int) * num_cylinder_req);

    // Make sure all the cylinder requests have been sought after
    while (reqs_finished < num_cylinder_req)
    {
        next_idx = -1;
        difference_total = num_cylinder;

        for (i = 0; i < num_cylinder_req; i++)
        {
            // Don't process requests that are already used.
            if (look_request_order[i] != -1)
            {
                // If seeking is going towards 0, and is the closest to the 
                // current point, and is positive number, this could possibly
                // be the next request.
                if (
                    look_direction == 0
                    && difference_total > abs(head_pos - look_request_order[i])
                    && head_pos - look_request_order[i] >= 0)
                {
                    next_idx = i;
                    difference_total = abs(head_pos - look_request_order[i]);
                }
                else if (
                    look_direction == 1
                    && difference_total > abs(head_pos - look_request_order[i])
                    && head_pos - look_request_order[i] <= 0)
                {
                    next_idx = i;
                    difference_total = abs(head_pos - look_request_order[i]);
                }
            }
        }

        // If there was no next request, move in the opposite direction.
        if (next_idx == -1)
        {
            if (look_direction == 0)
            {
                look_direction = 1;
            }
            else if (look_direction == 1)
            {
                look_direction = 0;
            }
        }
        // Found next request, add to seek time.
        else
        {
            look_total += difference_total;
            head_pos = look_request_order[next_idx];
            look_request_order[next_idx] = -1;
            reqs_finished++;
        }
    }

    // Clean up
    free(look_request_order);
    look_request_order = NULL;

    return look_total;
}

int clook_algorithm(int current_direction, int current_head_pos, int num_cylinder, int * cylinder_req, int num_cylinder_req)
{
    int i = 0;
    int difference_total = num_cylinder;
    int next_idx = -1;
    int reqs_finished = 0;
    int clook_total = 0;
    int head_pos = current_head_pos;
    int clook_direction = current_direction;
    int * clook_request_order = malloc(sizeof(int) * num_cylinder_req);

    // Make copy of cylinder requests, so the copy can be changed.
    memcpy(clook_request_order, cylinder_req, sizeof(int) * num_cylinder_req);

    // Make sure all the cylinder requests have been sought after
    while (reqs_finished < num_cylinder_req)
    {
        next_idx = -1;
        difference_total = num_cylinder;
        // Exception case, when looking for the furthest away request.
        if (clook_direction == 2)
        {
            difference_total = 0;
        }

        for (i = 0; i < num_cylinder_req; i++)
        {
            // Don't process requests that are already used.
            if (clook_request_order[i] != -1)
            {
                // Exception case of clook_direction when looking for the
                // furthest node away, to start at the other end of the 
                // cylinder.
                if (clook_direction == 2
                    && difference_total < abs(head_pos - clook_request_order[i]))
                {
                    next_idx = i;
                    difference_total = abs(head_pos - clook_request_order[i]);
                }
                // If seeking is going towards 0, and is the closest to the 
                // current point, and is positive number, this could possibly
                // be the next request.
                else if (
                           clook_direction == 0
                        && difference_total > abs(head_pos - clook_request_order[i])
                        && head_pos - clook_request_order[i] >= 0)
                {
                    next_idx = i;
                    difference_total = abs(head_pos - clook_request_order[i]);
                }
                else if (
                        clook_direction == 1
                        && difference_total > abs(head_pos - clook_request_order[i])
                        && head_pos - clook_request_order[i] <= 0)
                {
                    next_idx = i;
                    difference_total = abs(head_pos - clook_request_order[i]);
                }
            }
        }

        // No request was found, go to exception case, to find furthest away
        // node.
        if (next_idx == -1)
        {
            clook_direction = 2;
        }
        // Found next request add to seek time.
        else
        {
            // Request was found from furthest away node, restore previous
            // direction.
            if (clook_direction == 2)
            {
                clook_direction = current_direction;
            }
            clook_total += difference_total;
            head_pos = clook_request_order[next_idx];
            clook_request_order[next_idx] = -1;
            reqs_finished++;
        }
    }

    // Clean up
    free(clook_request_order);
    clook_request_order = NULL;

    return clook_total;
}