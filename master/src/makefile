#Raspi-pen Makefile#
#By Arthur Macêdo#

all: raspipen

raspipen: App.o Gyroscope.o
	g++ -o rppen App.o Gyroscope.o -lpthread

App.o: App.cpp
	g++ -o App.o -c App.cpp -lpthread

Gyroscope.o: Gyroscope.cpp
	g++ -o Gyroscope.o -c Gyroscope.cpp -lpthread

clean:
	rm -rf *.o

mrproper: clean
	rm -rf rppen
