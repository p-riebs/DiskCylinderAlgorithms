#!/usr/bin/perl

#
# A little script to run the project and check it against the
# expected result trace.
#

use strict;

my $binary = "./scheduler";

###########################################
# Parse Command Line Arguments
# [HEAD] [DIR] [INPUT FILE] [EXPECTED FILE]
###########################################
if( scalar(@ARGV) < 4 ) {
    print "ERROR: Not enough arguments\n";
    exit -1;
}

my $head_cyl   = int($ARGV[0]);
my $direction  = int($ARGV[1]);
my $input_file = $ARGV[2];
my $exp_file   = $ARGV[3];
my $cmd;

if( !(-e $input_file) ) {
    print "Error: Input file does not exist ($input_file)\n";
    exit -1;
}

if( !(-e $exp_file) ) {
    print "Error: Expected file does not exist ($exp_file)\n";
    exit -2;
}


###########################################
# Diagnostics
###########################################
print "-"x70 . "\n";
print "Running the command:\n";

$cmd = "$binary -h $head_cyl -d $direction $input_file";

print "\tshell\$ $cmd\n";
print "\t# Expected output shown in: $exp_file\n";


###########################################
# Run the command and gather all output
###########################################
my @output;
@output = `$cmd 2>&1`;


###########################################
# Extract the values from the live run
###########################################
my @per_results = ();
my @header_results = ();

foreach my $line (@output) {
    chomp($line);

    if( $line =~ /# /i ) {
        $line =~ s/#\s+//;
        if( $line =~ /^\s*\d+/ ) {
            push(@per_results, $line);
        }
        else {
            push(@header_results, $line);
        }
    }
}

if( scalar(@per_results) == 0 ) {
    printf("Error: No algorithm results found. Make sure the final\n");
    printf("       algorithm results are prefixed with a # symbol.\n");
    display_result(1);
    exit 0;
}

if( scalar(@per_results) != 6 ) {
    printf("Error: Did not find exactly 6 lines of algorithm results. You displayed %2d.\n", scalar(@per_results));
    printf("       Make sure all algorithms are represented in the output.\n");
    display_result(1);
    exit 0;
}

if( scalar(@header_results) == 0 ) {
    printf("Error: No header found. Make sure the parsed command line arguments\n");
    printf("       are displayed in the header prefixed with a # symbol.\n");
    display_result(1);
    exit 0;
}

if( scalar(@header_results) != 4 ) {
    printf("Error: Did not find exactly 4 lines of header information. You displayed %2d.\n", scalar(@header_results));
    printf("       Make sure the parsed command line arguments\n");
    printf("       are displayed in the header prefixed with a # symbol.\n");
    display_result(1);
    exit 0;
}

###########################################
# Extract the expected values from the trace
###########################################
my @exp_results = ();
my @exp_header = ();

@output = `cat $exp_file`;

foreach my $line (@output) {
    chomp($line);

    if( $line =~ /# /i ) {
        $line =~ s/#\s+//;
        if( $line =~ /^\s*\d+/ ) {
            push(@exp_results, $line);
        }
        else {
            push(@exp_header, $line);
        }
    }
}

###########################################
# Check the values against expected
###########################################
my $total_errors = 0;

foreach my $pr (@exp_results) {
    #print "DEBUG: <".$pr.">\n";
    if( 0 != compare_exp_to_per($pr) ) {
        ++$total_errors;
    }
}

if( $total_errors == 0 ) {
    foreach my $pr (@per_results) {
        #print "DEBUG: <".$pr.">\n";
        if( 0 != compare_per_to_exp($pr) ) {
            ++$total_errors;
        }
    }
}

###########################################
# Determine pass/fail
###########################################
display_result($total_errors);

exit 0;

#
# Display the result of the test
#
sub display_result() {
    my $num_errors = shift(@_);

    if( 0 == $num_errors ) {
        print "Passed!\n";
    }
    else {
        print "*"x5 . " Failed 1 test! " . "*"x5 . "\n";
    }

    return $num_errors;
}

#
# Given an 'actual' per process line, find the corresponding 'expected' line
# and compare the two results.
#
sub compare_per_to_exp() {
    my $orig = shift(@_);
    my @values = split(/\s+/, $orig);
    my @exp_values = ();
    my $was_found = 0;
    my $was_found_alg = 0;

    #
    # Find the match for this process in the expected set
    #
    foreach my $exp_orig (@exp_results) {
        @exp_values = split(/\s+/, $exp_orig);

        #
        # Find the algorithm
        #
        if( !($values[1] eq $exp_values[1]) ) {
            next;
        }
        $was_found_alg = 1;

        #
        # Check number of tokens in the output
        #
        if( scalar(@exp_values) != scalar(@values) ) {
            printf("Error: Final does not contain exactly one number for the algorithm %s\n", $values[1]);
            printf("       Expected: %s\n", scalar(@exp_values));
            printf("       Actual  : %s\n", scalar(@values));
            return -99;
        }


        #
        # Match the result
        #
        if( $exp_values[0] != $values[0] ) {
            printf("Error: Final total does not match expected output for the algorithm %s\n", $exp_values[1]);
            printf("       Expected: %s\n", $exp_values[0]);
            printf("       Actual  : %s\n", $values[0]);
            return -99;
        }
        else {
            last;
        }
    }

    if( 1 != $was_found_alg ) {
        printf("Error: Unknown algorithm %s\n", $values[1]);
        printf("       Check your spelling.\n");
        return -98;
    }

    return 0;
}

#
# Given an 'expected' per process line, find the corresponding 'actual' line
# and compare the two results.
#
sub compare_exp_to_per() {
    my $orig = shift(@_);
    my @values = split(/\s+/, $orig);
    my @exp_values = ();
    my $was_found = 0;
    my $was_found_alg = 0;

    #
    # Find the match for this process in the expected set
    #
    foreach my $exp_orig (@per_results) {
        @exp_values = split(/\s+/, $exp_orig);

        #
        # Find the algorithm
        #
        if( !($values[1] eq $exp_values[1]) ) {
            next;
        }
        $was_found_alg = 1;

        #
        # Check number of tokens in the output
        #
        if( scalar(@exp_values) != scalar(@values) ) {
            printf("Error: Final does not contain exactly one number for the algorithm %s\n", $values[1]);
            printf("       Expected: %s\n", scalar(@values));
            printf("       Actual  : %s\n", scalar(@exp_values));
            return -99;
        }


        #
        # Match the result
        #
        if( $exp_values[0] != $values[0] ) {
            printf("Error: Final total does not match expected output for the algorithm %s\n", $exp_values[1]);
            printf("       Expected: %s\n", $values[0]);
            printf("       Actual  : %s\n", $exp_values[0]);
            return -99;
        }
        else {
            last;
        }
    }

    if( 1 != $was_found_alg ) {
        printf("Error: Did not find the following algorithm in the output: %s\n", $values[1]);
        printf("       Check your spelling and that you are only displaying one number\n");
        printf("       on the same line as the algorithm name.\n");
        return -98;
    }

    return 0;
}
