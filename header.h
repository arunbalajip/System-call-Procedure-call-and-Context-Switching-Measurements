#ifndef HEADER_H
	#define HEADER_H
	#define _GNU_SOURCE             
/* Include files */
	#include <sched.h>
	#include <sys/wait.h>
	#include<stdio.h>
	#include<unistd.h>
	#include <stdlib.h>
	#include<sys/time.h>
	#include<time.h>
/* Macro declaration */
	#define MAX_SIZE 4
	#define CONVERSIONFROMNANOTOMICRO 0.001
	#define SECONDSTOMICROSECONDS(x) x*1000000
	#define SECONDSTONANOSECONDS(x) x*1000000000
/* Function declaration */
	int sumOfTwoNumbers (int , int );
	void calculateProcedureCall();
	void calcualteSystemCall();
	void calculateContextSwitch();
#endif 

