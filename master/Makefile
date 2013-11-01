CC=g++
CFLAGS=-I.
DEPS = test.h
OBJ = maintest.o test.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

raspipen: (OBJ)
	$(CC) -o maintest.exe maintest.cpp test.cpp -I.



http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
