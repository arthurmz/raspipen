import processing.serial.*;
Serial myPort;
int xpos = 400; 
int ypos = 300;
PFont myFont; 
int maxNumberOfSensors = 6;       
boolean fontInitialized = false;                  
float[] previousValue = new float[maxNumberOfSensors];                    

void setup () {
  size(800, 600);//tamanho da janela     
  println(Serial.list());

  String portName = Serial.list()[2];

  myPort = new Serial(this, portName, 9600);
  myPort.clear();
  myPort.bufferUntil('\n');
  myFont = createFont(PFont.list()[30], 18);
  textFont(myFont);
  fontInitialized = true;
  background(0);
  smooth();
}
 
void draw () {
}
 
void serialEvent (Serial myPort) {
  String inString = myPort.readStringUntil('\n');
 
  if (inString != null) {
    
    inString = trim(inString);
    
    int incomingValues[] = int(split(inString, ","));
    
    if (incomingValues.length <= maxNumberOfSensors && incomingValues.length > 0) {
      for (int i = 0; i < incomingValues.length; i++) {
         if (fontInitialized) {
         text("Valor "+i+": "+incomingValues[i]+"",10+(i*30),10);
         }
      }
    }
  }
}
