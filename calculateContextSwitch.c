#include "header.h"
/*
	NAME : CALCULATECONTEXTSWITCH()
	DESCRIPTION : This functions calculates the amount of time required for a process to do context switching. 
*/
void calculateContextSwitch()
{
	int i;
	pid_t pid;
	/****** SETTING the Process to a single Processor ***********/
	cpu_set_t mask;
	CPU_ZERO(&mask);
	CPU_SET(1,&mask);
	size_t len = sizeof(mask);
	if (sched_setaffinity(getpid(), len, &mask) < 0)
	{
		perror("Failure in sched_setaffinity");
	}
	/******* USING clock_gettime() TIMER *******/
	{
		struct timespec intial, final;
		pid = fork();
		if (pid == -1) {
			perror("Failure in fork");
			exit(EXIT_FAILURE);
		}
		if (pid == 0) {
			// Do nothing
		} else {
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &intial);
			wait(0);   //Waits for the child process to execute
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &final);
			long int temp = SECONDSTONANOSECONDS(final.tv_sec)+final.tv_nsec;
			long int temp1 = SECONDSTONANOSECONDS(intial.tv_sec)+intial.tv_nsec;
			printf("\n***CONTEXT SWITCH***:");
			printf("\nThe cost of the Context switching is calculated using clock_gettime() fn : %.3lf[microseconds]\n",0.001*(double)(temp-temp1));
		}
			
	}
}

