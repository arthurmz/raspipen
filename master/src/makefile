#Raspi-pen Makefile#
#By Arthur Macêdo#

all: raspipen

raspipen: App.o Gyroscope/Gyroscope.o Gyroscope/I2Cdev.o Gyroscope/MPU6050.o Gyroscope/ProcessGyroscopeData.o
	g++ -o rppen App.o Gyroscope/Gyroscope.o Gyroscope/I2Cdev.o Gyroscope/MPU6050.o Gyroscope/ProcessGyroscopeData.o -lpthread -std=c++11 -pedantic

App.o: App.cpp
	g++ -o App.o -c App.cpp -I Gyroscope/ -lpthread -std=c++11 -pedantic

Gyroscope/Gyroscope.o: Gyroscope/Gyroscope.cpp
	g++ -o Gyroscope/Gyroscope.o -c Gyroscope/Gyroscope.cpp -lpthread -std=c++11 -pedantic

Gyroscope/I2Cdev.o: Gyroscope/I2Cdev.cpp
	g++ -o Gyroscope/I2Cdev.o -c Gyroscope/I2Cdev.cpp -lpthread -std=c++11 -pedantic

Gyroscope/MPU6050.o: Gyroscope/MPU6050.cpp
	g++ -o Gyroscope/MPU6050.o -c Gyroscope/MPU6050.cpp -lpthread -std=c++11 -pedantic

Gyroscope/ProcessGyroscopeData.o:
	g++ -o Gyroscope/ProcessGyroscopeData.o -c Gyroscope/ProcessGyroscopeData.cpp -lpthread -std=c++11 -pedantic

clean:
	rm -rf *.o
	rm -rf Gyroscope/*.o
mrproper: clean
	rm -rf rppen


