void setup() {
  Serial.begin(9600);
}
int offset[3] = {331,350,300};
 
void loop() {
  for (int i = 0; i <= 2; i++) {
    int sensorReading = analogRead(i);
    Serial.print(sensorReading - offset[i], DEC);
    if (i < 2) {
      Serial.print(",");
    }
  }
  Serial.println();
}
