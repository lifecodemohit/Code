//reciever 
/*
DC Motor connections, 10, 11, 12, 13
Ultrasound sensor , 8=trigPin, 9=echoPin
LED, 7
*/
void setup(){
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, INPUT);
}
void loop(){
  clear mydata;
  long distance,duration;
  digitalWrite(8,LOW);
  duration = pulseIn(9, HIGH);
  distance = (duration/2)/29.1;
  if(Serial.available()>0){
    mydata = Serial.read();{
      if(distance<50){
        //stop;
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
      }        
      if(mydata=='a'){
        //"left"
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        digitalWrite(12, LOW);
        digitalWrite(13, HIGH);
      }
      else if(mydata=='d'){
        //"right"
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        digitalWrite(12, HIGH);
        digitalWrite(13, LOW);
      }
      else if(mydata=='a'){
        //"Forward"
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, HIGH);
      }
    }
  }
}
      
