#Raspi-pen Makefile#
#By Arthur Macêdo#

all: raspipen

raspipen: App.o Gyroscope/Gyroscope.o
	g++ -o rppen App.o Gyroscope/Gyroscope.o -lpthread

App.o: App.cpp
	g++ -o App.o -c App.cpp -lpthread

Gyroscope.o: Gyroscope/Gyroscope.cpp
	g++ -o Gyroscope/Gyroscope.o -c Gyroscope/Gyroscope.cpp -lpthread

clean:
	rm -rf *.o
	rm -rf Gyroscope/*.o
mrproper: clean
	rm -rf rppen
