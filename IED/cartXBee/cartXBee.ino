//reciever 
/*
DC Motor connections, 6,7,8,9,10, 11, 12, 13
Ultrasound sensor , 4=trigPin, 5=echoPin
Ultrasound sensor , 2=trigPin, 3=echoPin

LED, 7
*/
//#include <SoftwareSerial.h>
//SoftwareSerial XBee(0, 1);//RX,TX;

#define trigPin 2
#define echoPin 3
#define trigPin2 4
#define echoPin2 5

void setup(){ 
  Serial.begin(9600);
  //XBee.begin(9600);
  pinMode(A0, OUTPUT);//LED
  pinMode(A1,OUTPUT);//ground
  pinMode(6, OUTPUT);//M2
  pinMode(7, OUTPUT);//M2
  pinMode(8, OUTPUT);//M1
  pinMode(9, OUTPUT);//M1
  pinMode(10, OUTPUT);//M2
  pinMode(11, OUTPUT);//M2
  pinMode(12, OUTPUT);//M1
  pinMode(13, OUTPUT);//M1

 pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
   pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  //pinMode(4, OUTPUT);//for ultrasonic 
  //pinMode(5, INPUT); //for ultrasonic
  //pinMode(2, OUTPUT);//for ultrasonic 
  //pinMode(3, INPUT); //for ultrasonic

}
void loop(){
  analogWrite(A1, LOW);
  char mydata;
  long duration, distance,duration2,distance2;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;


  digitalWrite(trigPin2, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin2, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2/2) / 29.1;
//  Serial.print("Dist");
//Serial.println(distance2);

//  Serial.print("Dist ");
//  Serial.println(distance);
//  Serial.print("Dist 2 ");
//  Serial.println(distance2);
  //&& (distance>20 && distance2>20)
  if(Serial.available()>0 ){
    Serial.println("lasllafsfkanfkajhfak");    
    mydata = Serial.read();
    if(distance < 20 || distance2 < 20)
    {
       mydata='z';
       analogWrite(A0, 1023);
      Serial.println("Obstacle detected"); 
    }
      Serial.println(mydata);
      Serial.print(distance);
      Serial.print(" ");
      Serial.println(distance2);
//      Serial.write("blablabla");
//uncomment when Ultrasonic is connected
        
 //     else{
        /*
        analogWrite(A0, LOW);
        analogWrite(A0, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
      //  delay(100);
      */
      Serial.println(mydata);
        if(mydata=='a'){
          //"left"
          
          analogWrite(A0, LOW);
          digitalWrite(6, HIGH);
          digitalWrite(7, LOW);
          digitalWrite(8, LOW);
          digitalWrite(9, HIGH);
          digitalWrite(10, HIGH);
          digitalWrite(11, LOW);
          digitalWrite(12, HIGH);
          digitalWrite(13, LOW);
          
        }
        else if(mydata=='d'){
          //"right"
          analogWrite(A0, LOW);
          digitalWrite(6, LOW);
          digitalWrite(7, HIGH);
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW);
          digitalWrite(10, LOW);
          digitalWrite(11, HIGH);
          digitalWrite(12, LOW);
          digitalWrite(13, HIGH);
          
        }
        else if(mydata=='w'){
          //"Forward"
          analogWrite(A0, LOW);
          digitalWrite(6, HIGH);//HIGH
          digitalWrite(7, LOW);
          digitalWrite(8, LOW);
          digitalWrite(9, HIGH);//HIGH
          digitalWrite(10, LOW);
          digitalWrite(11, HIGH);//HIGH
          digitalWrite(12, LOW);
          digitalWrite(13, HIGH);
          
        }
        else if(mydata=='z'){
          //"STOP"
          analogWrite(A0, LOW);
          digitalWrite(6, LOW);
          digitalWrite(7, LOW);
          digitalWrite(8, LOW);
          digitalWrite(9, LOW);
          digitalWrite(10, LOW);
          digitalWrite(11, LOW);
          digitalWrite(12, LOW);
          digitalWrite(13, LOW);
        }
//      }

    }
    else{
//        Serial.println("lalalal");
        analogWrite(A0, HIGH);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);

    }
  }

      
