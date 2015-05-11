#include <SoftwareSerial.h>
//SoftwareSerial XBee(0, 1);//RX,TX;
void setup(){
//  XBee.begin(9600);
  Serial.begin(9600);
}
void loop(){

  char mydata = 'a';
  Serial.print(mydata);
  
 // XBee.write(mydata);
 // XBee.write(32);
  mydata = 'a';
//  XBee.write(mydata);
//  Serial.print(mydata);
//  Serial.print("\n");
 // Serial.write(XBee.available());
 // Serial.write("\n");
  //XBee.flush();
  delay(1000);
  
}
