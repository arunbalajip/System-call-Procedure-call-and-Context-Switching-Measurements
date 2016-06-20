#include "header.h"
/*
	NAME : CALCULATESYSTEMCALL()
	DESCRIPTION : This functions calculates the amount of time required for a system call(getpid())
*/
void calculateSystemCall()
{
	int i;
	long sum = 0;
	long sum1 = 0;
	long array_gettimeofday[MAX_SIZE];
	long array_clockgettime[MAX_SIZE];
	getpid();
	/****** USING gettimeofday() TIMER ***********/
	{
		struct timeval intial,final;
		for(i=0;i<MAX_SIZE;i++)
		{
			long int temp,temp1;
			gettimeofday(&intial, NULL);
			getpid();
			gettimeofday(&final, NULL);
			temp = SECONDSTOMICROSECONDS(final.tv_sec)+final.tv_usec;
			temp1 = SECONDSTOMICROSECONDS(intial.tv_sec)+intial.tv_usec;
			array_gettimeofday[i] = temp-temp1;
			sum = sum + array_gettimeofday[i];
		}
	}
	/******* USING clock_gettime() TIMER *******/
	{
		struct timespec intial, final;
			for(i=0;i<MAX_SIZE;i++)
			{
				long int temp,temp1;
				clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &intial);
				getpid();
				clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &final);
				temp = SECONDSTONANOSECONDS(final.tv_sec)+final.tv_nsec;
				temp1 = SECONDSTONANOSECONDS(intial.tv_sec)+intial.tv_nsec;
				array_clockgettime[i] = temp-temp1;
				sum1 = sum1 + array_clockgettime[i]; 
			}
	}
	printf("\n***SYSTEM CALL***:");
	/******* Print the values of gettimeofday() and clock_gettime() fn *******/
	{
		printf("\nThe cost of the getpid() is calculated using two timers gettimeofday() and clock_gettime() as follows:\n\n");
		printf("SystemCall\tIteration\tgettimeofday()\tclock_gettime()\n");
		printf("\t\t\t\t[microseconds]\t[microseconds]\n");
		for(i=0;i<MAX_SIZE;i++)
		{
			printf(" getpid\t\t%d\t\t%ld\t\t%.3f\n",(i+1),array_gettimeofday[i],CONVERSIONFROMNANOTOMICRO*(array_clockgettime[i]));
		}
		printf("\nAverage time(System Call)\t%.3f\t\t%.3f\n",(double)sum/MAX_SIZE,CONVERSIONFROMNANOTOMICRO*(double)(sum1/4));
	}
}

