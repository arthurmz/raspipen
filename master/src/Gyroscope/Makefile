# You need to "sudo apt-get install libgtkmm-3.0-dev" to build the demo_3d binary

all: demo_dmp

HDRS = I2Cdev.h MPU6050_6Axis_MotionApps20.h MPU6050.h
CMN_OBJS = I2Cdev.o MPU6050.o
DMP_OBJS = demo_dmp.o

$(CMN_OBJS) $(DMP_OBJS) : $(HDRS)


demo_dmp: $(CMN_OBJS) $(DMP_OBJS)
	$(CXX) -o $@ $^ -lm


clean:	
	rm -f $(CMN_OBJS) $(DMP_OBJS) demo_dmp

