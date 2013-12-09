#Raspi-pen Makefile#
#By Arthur Macêdo#

all: raspipen

raspipen: App.o Gyroscope/Gyroscope.o Gyroscope/I2Cdev.o Gyroscope/MPU6050.o DataProcessing/ProcessGyroscopeData.o DataProcessing/Physics/Physics.o  DataProcessing/Physics/Rotation.o EasyBMP/EasyBMP.o DataProcessing/ImageGenerator.o DataProcessing/Filters/ConverteAceleracaoReal.o DataProcessing/Filters/RemoveGravidade.o DataProcessing/Filters/AceleracaoParaDistancia.o
	g++ -o rppen App.o Gyroscope/Gyroscope.o Gyroscope/I2Cdev.o Gyroscope/MPU6050.o DataProcessing/ProcessGyroscopeData.o DataProcessing/Physics/Physics.o DataProcessing/Physics/Rotation.o EasyBMP/EasyBMP.o DataProcessing/ImageGenerator.o DataProcessing/Filters/ConverteAceleracaoReal.o DataProcessing/Filters/RemoveGravidade.o DataProcessing/Filters/AceleracaoParaDistancia.o -lpthread -pedantic

App.o: App.cpp
	g++ -o App.o -c App.cpp -I Gyroscope/ -I DataProcessing/ -I DataProcessing/Filters/ -I EasyBMP/ -I UserInput/ -lpthread -pedantic

##########Gyroscope######################
Gyroscope/Gyroscope.o: Gyroscope/Gyroscope.cpp
	g++ -o Gyroscope/Gyroscope.o -c Gyroscope/Gyroscope.cpp -lpthread -pedantic

Gyroscope/I2Cdev.o: Gyroscope/I2Cdev.cpp
	g++ -o Gyroscope/I2Cdev.o -c Gyroscope/I2Cdev.cpp -lpthread -pedantic

Gyroscope/MPU6050.o: Gyroscope/MPU6050.cpp
	g++ -o Gyroscope/MPU6050.o -c Gyroscope/MPU6050.cpp -lpthread -pedantic


#########Data Processing#################
DataProcessing/ProcessGyroscopeData.o:
	g++ -o DataProcessing/ProcessGyroscopeData.o -c DataProcessing/ProcessGyroscopeData.cpp -I Gyroscope/ -I DataProcessing/Filters/ -I DataProcessing/Physics/ -I Gyroscope/ -lpthread -pedantic

DataProcessing/Physics/Physics.o:
	g++ -o DataProcessing/Physics/Physics.o -c DataProcessing/Physics/Physics.cpp

DataProcessing/Physics/Rotation.o:
	g++ -o DataProcessing/Physics/Rotation.o -c DataProcessing/Physics/Rotation.cpp

DataProcessing/ImageGenerator.o:
	g++ -o DataProcessing/ImageGenerator.o -c DataProcessing/ImageGenerator.cpp -I EasyBMP/ -I Gyroscope/

DataProcessing/Filters/ConverteAceleracaoReal.o:
	g++ -o DataProcessing/Filters/ConverteAceleracaoReal.o -c DataProcessing/Filters/ConverteAceleracaoReal.cpp -I Gyroscope/ -I DataProcessing/Physics/

DataProcessing/Filters/RemoveGravidade.o:
	g++ -o DataProcessing/Filters/RemoveGravidade.o -c DataProcessing/Filters/RemoveGravidade.cpp -I Gyroscope/ -I DataProcessing/Physics/

DataProcessing/Filters/AceleracaoParaDistancia.o:
	g++ -o DataProcessing/Filters/AceleracaoParaDistancia.o -c DataProcessing/Filters/AceleracaoParaDistancia.cpp -I Gyroscope/ -I DataProcessing/Physics/
########EasyBMP#########################
EasyBMP/EasyBMP.o:
	g++ -o EasyBMP/EasyBMP.o -c EasyBMP/EasyBMP.cpp

########Clean up########################
clean:
	rm -rf *.o
	rm -rf Gyroscope/*.o
	rm -rf DataProcessing/*.o
	rm -rf DataProcessing/Physics/*.o
	rm -rf DataProcessing/Filters/*.o

mrproper: clean
	rm -rf rppen
	rm -rf test.bmp

