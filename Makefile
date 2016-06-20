#defining variables
COMPILE=gcc -c
EXECUTE=gcc -lrt

#this target will run the code
all: output
output: main.o calculateContextSwitch.o calculateSystemCall.o calculateProcedureCall.o
	$(EXECUTE) main.o calculateContextSwitch.o calculateSystemCall.o calculateProcedureCall.o -o output
main.o: main.c
	$(COMPILE) main.c
calculateContextSwitch.o: calculateContextSwitch.c
	$(COMPILE) calculateContextSwitch.c
calculateSystemCall.o: calculateSystemCall.c
	$(COMPILE) calculateSystemCall.c
calculateProcedureCall.o: calculateProcedureCall.c
	$(COMPILE) calculateProcedureCall.c
clean:
	rm -rf *.o output

	
