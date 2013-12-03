#Raspi-pen Makefile#
#By Arthur Macêdo#

all: raspipen

raspipen: App.o Gyroscope/Gyroscope.o Gyroscope/I2Cdev.o Gyroscope/MPU6050.o DataProcessing/ProcessGyroscopeData.o DataProcessing/Physics/Physics.o DataProcessing/Physics/Rotation.o
	g++ -o rppen App.o Gyroscope/Gyroscope.o Gyroscope/I2Cdev.o Gyroscope/MPU6050.o DataProcessing/ProcessGyroscopeData.o DataProcessing/Physics/Physics.o DataProcessing/Physics/Rotation.o  -lpthread -pedantic

App.o: App.cpp
	g++ -o App.o -c App.cpp -I Gyroscope/ -I DataProcessing/ -lpthread -pedantic
##########Gyroscope######################
Gyroscope/Gyroscope.o: Gyroscope/Gyroscope.cpp
	g++ -o Gyroscope/Gyroscope.o -c Gyroscope/Gyroscope.cpp -lpthread -pedantic

Gyroscope/I2Cdev.o: Gyroscope/I2Cdev.cpp
	g++ -o Gyroscope/I2Cdev.o -c Gyroscope/I2Cdev.cpp -lpthread -pedantic

Gyroscope/MPU6050.o: Gyroscope/MPU6050.cpp
	g++ -o Gyroscope/MPU6050.o -c Gyroscope/MPU6050.cpp -lpthread -pedantic


#########Data Processing#################
DataProcessing/ProcessGyroscopeData.o:
	g++ -o DataProcessing/ProcessGyroscopeData.o -c DataProcessing/ProcessGyroscopeData.cpp -I Gyroscope -lpthread -pedantic

DataProcessing/Physics/Physics.o:
	g++ -o DataProcessing/Physics/Physics.o -c DataProcessing/Physics/Physics.cpp

DataProcessing/Physics/Rotation.o:
	g++ -o DataProcessing/Physics/Rotation.o -c DataProcessing/Physics/Rotation.cpp
########Clean up########################
clean:
	rm -rf *.o
	rm -rf Gyroscope/*.o
	rm -rf DataProcessing/*.o
mrproper: clean
	rm -rf rppen


