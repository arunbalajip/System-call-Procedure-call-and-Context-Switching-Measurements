#include "header.h"
/*
	NAME : CALCULATEPROCEDURECALL()
	DESCRIPTION : This functions calculates the amount of time required to do a procedure call
*/
void calculateProcedureCall()
{
	int i;
	long sum=0;
	long sum1=0;
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
			sumOfTwoNumbers(5,10);
			gettimeofday(&final, NULL);
			temp = SECONDSTOMICROSECONDS(final.tv_sec)+final.tv_usec;
			temp1 = SECONDSTOMICROSECONDS(intial.tv_sec)+intial.tv_usec;
			array_gettimeofday[i] = temp-temp1;
			sum= sum + array_gettimeofday[i];
		}
	}
	/******* USING clock_gettime() TIMER *******/
	{
		struct timespec intial, final;
			for(i=0;i<MAX_SIZE;i++)
			{
				long int temp,temp1;
				clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &intial);
				sumOfTwoNumbers(5,10);
				clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &final);
				temp = SECONDSTONANOSECONDS(final.tv_sec)+final.tv_nsec;
				temp1 = SECONDSTONANOSECONDS(intial.tv_sec)+intial.tv_nsec;
				array_clockgettime[i] = temp-temp1;
				sum1 = sum1 + array_clockgettime[i]; 
			}
	}
	printf("\n***PROCEDURE CALL***:");
	/******* Print the values of gettimeofday() and clock_gettime() fn *******/
	{
		printf("\nThe cost of the sumoftwonumbers() is calculated using two timers gettimeofday() and clock_gettime() as follows\n\n");
		printf("ProcedureCall\tIteration\tgettimeofday()\tclock_gettime()\n");
		printf("\t\t\t\t[microseconds]\t[microseconds]\n");
		for(i=0;i<MAX_SIZE;i++)
		{
			printf("Sumoftwonumbers\t%d\t\t%ld\t\t%.3f\n",(i+1),array_gettimeofday[i],CONVERSIONFROMNANOTOMICRO*(array_clockgettime[i]));
		}
		printf("\nAverage time(Procedure call)\t%.3f\t\t%.3f\n",(double)sum/4,CONVERSIONFROMNANOTOMICRO*(double)(sum1/4));
	}
}

/*
	NAME : SUMOFTWONUMBERS()
	DESCRIPTION : This functions returns the sum of two numbers
*/
int sumOfTwoNumbers(int a, int b)
{
	return a+b;
}

