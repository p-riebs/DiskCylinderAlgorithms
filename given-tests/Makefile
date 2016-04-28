#
# Josh Hursey
# CS 441/541: Project 6 Given Tests
#

check: scheduler banner_help \
	check-level-1 check-level-2 check-level-3 check-level-4 check-level-5

banner_help:
	@echo "By default check will run all levels."
	@echo "You can run an individual level by using one of the following:"
	@echo "   check-level-1"
	@echo "   check-level-2"
	@echo "   check-level-3"
	@echo "   check-level-4"
	@echo "   check-level-5"
	@echo ""
	@sleep 1


###############################################
# Tests - Level 1
###############################################
LEVEL_1_INPUT=given-tests/level1.txt
check-level-1: scheduler banner_1 \
	check-level-1-e-0 check-level-1-e-1 check-level-1-e-2 check-level-1-e-3 check-level-1-e-4 \
	check-level-1-e-5 check-level-1-e-6 check-level-1-e-7 check-level-1-e-8 check-level-1-e-9
	@sleep 1

banner_1:
	@echo ""
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
	@echo "mmmmmmmmm Level 1 Tests mmmmmmmmmmm"
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
	@sleep 1

LEVEL_1_EXP_0=given-tests/level1_exp_0.txt
check-level-1-e-0: scheduler
	@given-tests/check.pl 53 0 $(LEVEL_1_INPUT) $(LEVEL_1_EXP_0)

LEVEL_1_EXP_1=given-tests/level1_exp_1.txt
check-level-1-e-1: scheduler
	@given-tests/check.pl 53 1 $(LEVEL_1_INPUT) $(LEVEL_1_EXP_1)

LEVEL_1_EXP_2=given-tests/level1_exp_2.txt
check-level-1-e-2: scheduler
	@given-tests/check.pl 0 0 $(LEVEL_1_INPUT) $(LEVEL_1_EXP_2)

LEVEL_1_EXP_3=given-tests/level1_exp_3.txt
check-level-1-e-3: scheduler
	@given-tests/check.pl 0 1 $(LEVEL_1_INPUT) $(LEVEL_1_EXP_3)

LEVEL_1_EXP_4=given-tests/level1_exp_4.txt
check-level-1-e-4: scheduler
	@given-tests/check.pl 5 0 $(LEVEL_1_INPUT) $(LEVEL_1_EXP_4)

LEVEL_1_EXP_5=given-tests/level1_exp_5.txt
check-level-1-e-5: scheduler
	@given-tests/check.pl 5 1 $(LEVEL_1_INPUT) $(LEVEL_1_EXP_5)

LEVEL_1_EXP_6=given-tests/level1_exp_6.txt
check-level-1-e-6: scheduler
	@given-tests/check.pl 199 0 $(LEVEL_1_INPUT) $(LEVEL_1_EXP_6)

LEVEL_1_EXP_7=given-tests/level1_exp_7.txt
check-level-1-e-7: scheduler
	@given-tests/check.pl 199 1 $(LEVEL_1_INPUT) $(LEVEL_1_EXP_7)

LEVEL_1_EXP_8=given-tests/level1_exp_8.txt
check-level-1-e-8: scheduler
	@given-tests/check.pl 99 0 $(LEVEL_1_INPUT) $(LEVEL_1_EXP_8)

LEVEL_1_EXP_9=given-tests/level1_exp_9.txt
check-level-1-e-9: scheduler
	@given-tests/check.pl 99 0 $(LEVEL_1_INPUT) $(LEVEL_1_EXP_9)


###############################################
# Tests - Level 2
###############################################
LEVEL_2_INPUT=given-tests/level2.txt
check-level-2: scheduler banner_2 \
	check-level-2-e-0 check-level-2-e-1 check-level-2-e-2 check-level-2-e-3 check-level-2-e-4 \
	check-level-2-e-5 check-level-2-e-6 check-level-2-e-7 check-level-2-e-8 check-level-2-e-9
	@sleep 1

banner_2:
	@echo ""
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
	@echo "mmmmmmmmm Level 2 Tests mmmmmmmmmmm"
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
	@sleep 1

LEVEL_2_EXP_0=given-tests/level2_exp_0.txt
check-level-2-e-0: scheduler
	@given-tests/check.pl 23 0 $(LEVEL_2_INPUT) $(LEVEL_2_EXP_0)

LEVEL_2_EXP_1=given-tests/level2_exp_1.txt
check-level-2-e-1: scheduler
	@given-tests/check.pl 23 1 $(LEVEL_2_INPUT) $(LEVEL_2_EXP_1)

LEVEL_2_EXP_2=given-tests/level2_exp_2.txt
check-level-2-e-2: scheduler
	@given-tests/check.pl 0 0 $(LEVEL_2_INPUT) $(LEVEL_2_EXP_2)

LEVEL_2_EXP_3=given-tests/level2_exp_3.txt
check-level-2-e-3: scheduler
	@given-tests/check.pl 0 1 $(LEVEL_2_INPUT) $(LEVEL_2_EXP_3)

LEVEL_2_EXP_4=given-tests/level2_exp_4.txt
check-level-2-e-4: scheduler
	@given-tests/check.pl 5 0 $(LEVEL_2_INPUT) $(LEVEL_2_EXP_4)

LEVEL_2_EXP_5=given-tests/level2_exp_5.txt
check-level-2-e-5: scheduler
	@given-tests/check.pl 5 1 $(LEVEL_2_INPUT) $(LEVEL_2_EXP_5)

LEVEL_2_EXP_6=given-tests/level2_exp_6.txt
check-level-2-e-6: scheduler
	@given-tests/check.pl 49 0 $(LEVEL_2_INPUT) $(LEVEL_2_EXP_6)

LEVEL_2_EXP_7=given-tests/level2_exp_7.txt
check-level-2-e-7: scheduler
	@given-tests/check.pl 49 1 $(LEVEL_2_INPUT) $(LEVEL_2_EXP_7)

LEVEL_2_EXP_8=given-tests/level2_exp_8.txt
check-level-2-e-8: scheduler
	@given-tests/check.pl 7 0 $(LEVEL_2_INPUT) $(LEVEL_2_EXP_8)

LEVEL_2_EXP_9=given-tests/level2_exp_9.txt
check-level-2-e-9: scheduler
	@given-tests/check.pl 7 0 $(LEVEL_2_INPUT) $(LEVEL_2_EXP_9)


###############################################
# Tests - Level 3
###############################################
LEVEL_3_INPUT=given-tests/level3.txt
check-level-3: scheduler banner_3 \
	check-level-3-e-0 check-level-3-e-1 check-level-3-e-2 check-level-3-e-3 check-level-3-e-4 \
	check-level-3-e-5 check-level-3-e-6 check-level-3-e-7 check-level-3-e-8 check-level-3-e-9
	@sleep 1

banner_3:
	@echo ""
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
	@echo "mmmmmmmmm Level 3 Tests mmmmmmmmmmm"
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
	@sleep 1

LEVEL_3_EXP_0=given-tests/level3_exp_0.txt
check-level-3-e-0: scheduler
	@given-tests/check.pl 4 0 $(LEVEL_3_INPUT) $(LEVEL_3_EXP_0)

LEVEL_3_EXP_1=given-tests/level3_exp_1.txt
check-level-3-e-1: scheduler
	@given-tests/check.pl 4 1 $(LEVEL_3_INPUT) $(LEVEL_3_EXP_1)

LEVEL_3_EXP_2=given-tests/level3_exp_2.txt
check-level-3-e-2: scheduler
	@given-tests/check.pl 0 0 $(LEVEL_3_INPUT) $(LEVEL_3_EXP_2)

LEVEL_3_EXP_3=given-tests/level3_exp_3.txt
check-level-3-e-3: scheduler
	@given-tests/check.pl 0 1 $(LEVEL_3_INPUT) $(LEVEL_3_EXP_3)

LEVEL_3_EXP_4=given-tests/level3_exp_4.txt
check-level-3-e-4: scheduler
	@given-tests/check.pl 1 0 $(LEVEL_3_INPUT) $(LEVEL_3_EXP_4)

LEVEL_3_EXP_5=given-tests/level3_exp_5.txt
check-level-3-e-5: scheduler
	@given-tests/check.pl 1 1 $(LEVEL_3_INPUT) $(LEVEL_3_EXP_5)

LEVEL_3_EXP_6=given-tests/level3_exp_6.txt
check-level-3-e-6: scheduler
	@given-tests/check.pl 8 0 $(LEVEL_3_INPUT) $(LEVEL_3_EXP_6)

LEVEL_3_EXP_7=given-tests/level3_exp_7.txt
check-level-3-e-7: scheduler
	@given-tests/check.pl 8 1 $(LEVEL_3_INPUT) $(LEVEL_3_EXP_7)

LEVEL_3_EXP_8=given-tests/level3_exp_8.txt
check-level-3-e-8: scheduler
	@given-tests/check.pl 7 0 $(LEVEL_3_INPUT) $(LEVEL_3_EXP_8)

LEVEL_3_EXP_9=given-tests/level3_exp_9.txt
check-level-3-e-9: scheduler
	@given-tests/check.pl 7 0 $(LEVEL_3_INPUT) $(LEVEL_3_EXP_9)



###############################################
# Tests - Level 4
###############################################
LEVEL_4_INPUT=given-tests/level4.txt
check-level-4: scheduler banner_4 \
	check-level-4-e-0 check-level-4-e-1 check-level-4-e-2 check-level-4-e-3 check-level-4-e-4 \
	check-level-4-e-5 check-level-4-e-6 check-level-4-e-7 check-level-4-e-8 check-level-4-e-9
	@sleep 1

banner_4:
	@echo ""
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
	@echo "mmmmmmmmm Level 4 Tests mmmmmmmmmmm"
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
	@sleep 1

LEVEL_4_EXP_0=given-tests/level4_exp_0.txt
check-level-4-e-0: scheduler
	@given-tests/check.pl 57 0 $(LEVEL_4_INPUT) $(LEVEL_4_EXP_0)

LEVEL_4_EXP_1=given-tests/level4_exp_1.txt
check-level-4-e-1: scheduler
	@given-tests/check.pl 57 1 $(LEVEL_4_INPUT) $(LEVEL_4_EXP_1)

LEVEL_4_EXP_2=given-tests/level4_exp_2.txt
check-level-4-e-2: scheduler
	@given-tests/check.pl 0 0 $(LEVEL_4_INPUT) $(LEVEL_4_EXP_2)

LEVEL_4_EXP_3=given-tests/level4_exp_3.txt
check-level-4-e-3: scheduler
	@given-tests/check.pl 0 1 $(LEVEL_4_INPUT) $(LEVEL_4_EXP_3)

LEVEL_4_EXP_4=given-tests/level4_exp_4.txt
check-level-4-e-4: scheduler
	@given-tests/check.pl 1 0 $(LEVEL_4_INPUT) $(LEVEL_4_EXP_4)

LEVEL_4_EXP_5=given-tests/level4_exp_5.txt
check-level-4-e-5: scheduler
	@given-tests/check.pl 1 1 $(LEVEL_4_INPUT) $(LEVEL_4_EXP_5)

LEVEL_4_EXP_6=given-tests/level4_exp_6.txt
check-level-4-e-6: scheduler
	@given-tests/check.pl 4999 0 $(LEVEL_4_INPUT) $(LEVEL_4_EXP_6)

LEVEL_4_EXP_7=given-tests/level4_exp_7.txt
check-level-4-e-7: scheduler
	@given-tests/check.pl 4999 1 $(LEVEL_4_INPUT) $(LEVEL_4_EXP_7)

LEVEL_4_EXP_8=given-tests/level4_exp_8.txt
check-level-4-e-8: scheduler
	@given-tests/check.pl 1404 0 $(LEVEL_4_INPUT) $(LEVEL_4_EXP_8)

LEVEL_4_EXP_9=given-tests/level4_exp_9.txt
check-level-4-e-9: scheduler
	@given-tests/check.pl 1404 0 $(LEVEL_4_INPUT) $(LEVEL_4_EXP_9)


###############################################
# Tests - Level 5
###############################################
LEVEL_5_INPUT=given-tests/level5.txt
check-level-5: scheduler banner_5 \
	check-level-5-e-0 check-level-5-e-1 check-level-5-e-2 check-level-5-e-3 check-level-5-e-4 \
	check-level-5-e-5 check-level-5-e-6 check-level-5-e-7 check-level-5-e-8 check-level-5-e-9
	@sleep 1

banner_5:
	@echo ""
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
	@echo "mmmmmmmmm Level 5 Tests mmmmmmmmmmm"
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
	@sleep 1

LEVEL_5_EXP_0=given-tests/level5_exp_0.txt
check-level-5-e-0: scheduler
	@given-tests/check.pl 57 0 $(LEVEL_5_INPUT) $(LEVEL_5_EXP_0)

LEVEL_5_EXP_1=given-tests/level5_exp_1.txt
check-level-5-e-1: scheduler
	@given-tests/check.pl 57 1 $(LEVEL_5_INPUT) $(LEVEL_5_EXP_1)

LEVEL_5_EXP_2=given-tests/level5_exp_2.txt
check-level-5-e-2: scheduler
	@given-tests/check.pl 0 0 $(LEVEL_5_INPUT) $(LEVEL_5_EXP_2)

LEVEL_5_EXP_3=given-tests/level5_exp_3.txt
check-level-5-e-3: scheduler
	@given-tests/check.pl 0 1 $(LEVEL_5_INPUT) $(LEVEL_5_EXP_3)

LEVEL_5_EXP_4=given-tests/level5_exp_4.txt
check-level-5-e-4: scheduler
	@given-tests/check.pl 1 0 $(LEVEL_5_INPUT) $(LEVEL_5_EXP_4)

LEVEL_5_EXP_5=given-tests/level5_exp_5.txt
check-level-5-e-5: scheduler
	@given-tests/check.pl 1 1 $(LEVEL_5_INPUT) $(LEVEL_5_EXP_5)

LEVEL_5_EXP_6=given-tests/level5_exp_6.txt
check-level-5-e-6: scheduler
	@given-tests/check.pl 4999 0 $(LEVEL_5_INPUT) $(LEVEL_5_EXP_6)

LEVEL_5_EXP_7=given-tests/level5_exp_7.txt
check-level-5-e-7: scheduler
	@given-tests/check.pl 4999 1 $(LEVEL_5_INPUT) $(LEVEL_5_EXP_7)

LEVEL_5_EXP_8=given-tests/level5_exp_8.txt
check-level-5-e-8: scheduler
	@given-tests/check.pl 1404 0 $(LEVEL_5_INPUT) $(LEVEL_5_EXP_8)

LEVEL_5_EXP_9=given-tests/level5_exp_9.txt
check-level-5-e-9: scheduler
	@given-tests/check.pl 1404 0 $(LEVEL_5_INPUT) $(LEVEL_5_EXP_9)
