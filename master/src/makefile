#Raspi-pen Makefile#
#By Arthur Macêdo#

all: raspipen

raspipen: App.o
	g++ -o rppen App.o

App.o: App.cpp
	g++ -o App.o -c App.cpp -W -Wall -ansi -pedantic

clean:
	rm -rf *.o

mrproper: clean
	rm -rf rppen
