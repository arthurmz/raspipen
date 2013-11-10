all: app


app: App.o ../DataSource/MPU6050-Pi-Demo/demo_dmp.o
#	g++ App.cpp -o application
#	g++ App.cpp ../DataSource/MPU6050-Pi-Demo/I2Cdev.cpp ../DataSource/MPU6050-Pi-Demo/MPU6050.cpp
	g++ App.cpp ../DataSource/MPU6050-Pi-Demo/demo_dmp.cpp ../DataSource/MPU6050-Pi-Demo/I2Cdev.cpp ../DataSource/MPU6050-Pi-Demo/MPU6050.cpp  -o application

#	$(MAKE) -C ../DataSource/MPU6050-Pi-Demo/
