CC     = gcc
CFLAGS = -Wall -Wextra -Werror

problem_rp:
	$(CC) $(CFLAGS) -o problem_rp ProblemRP/UpperLowerBound.c -lm

test_problem_rp:
	bash ProblemRP/run_tests.sh

problem_ex:
	$(CC) $(CFLAGS) -o problem_ex ProblemEX/FloatingPointBits.c

test_problem_ex:
	bash ProblemEX/run_tests.sh

clean:
	rm -f problem_*