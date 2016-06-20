# System-call-Procedure-call-and-Context-Switching-Measurements
Measuring the cost of the system call, procedure call and context switching are explained with experimental results. To measure, different timers are used and the differences are compared. To avoid difficulties in context switching, the process is bind to a particular processor.


  1. Minimun System Requirement
  2. Included files
  3. Execute & Clean

1. Minimun System Requirement
-------------------------
	Unix OS with gcc compiler

2. Included files
------------------
  calculateSystemCall.c      - Source file logics to measure System call.

  calculateProcedureCall.c   - Source file logics to measure Procedure call.
  
  calculateContextSwitch.c   - Source file logics to measure Context switching.
  
  main.c		     - Main file to run the program
  
  header.h 		     - Header file
  
  Makefile                   - Makefile providing 'executable' and 'clean' targets


3. Execute & Clean
------------------

To compile and generate the executable file run:

  make all

To run the program

  ./output

To remove the executable and object files

   make clean



