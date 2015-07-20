#include "I2Cdev.h"

#include "MPU6050_6Axis_MotionApps20.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif

MPU6050 mpu;
#define OUTPUT_READABLE_REALACCEL
#define LED_PIN 13
int LDR_Pin = 7;
bool blinkState = false;

// MPU control/status vars
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

// orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorInt16 aa;         // [x, y, z]            accel sensor measurements
VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
VectorFloat gravity;    // [x, y, z]            gravity vector


volatile bool mpuInterrupt = false;     
void dmpDataReady() {
    mpuInterrupt = true;
}
void setup() {
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
        TWBR = 24; 
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif

    Serial.begin(9600);
    while (!Serial); // wait for Leonardo enumeration, others continue immediately
    mpu.initialize();

    devStatus = mpu.dmpInitialize();
    mpu.setXGyroOffset(0);//220
    mpu.setYGyroOffset(0);//76
    mpu.setZGyroOffset(0);//-85
    mpu.setZAccelOffset(1788); // 1688 factory default for my test chip
    mpu.setDMPEnabled(true);

    if (devStatus == 0) {
        attachInterrupt(0, dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();
        dmpReady = true;
        packetSize = mpu.dmpGetFIFOPacketSize();
        
    } else {
        Serial.print(F("DMP Initialization failed (code "));
        Serial.print(devStatus);
        Serial.println(F(")"));
    }
    pinMode(LED_PIN, OUTPUT);
}

int arrx[10];
int arry[10];
int arrz[10];
int i = 0;
float sx = 0;float sy=0; float sz=0;
int flag = 0;
void loop() {
    int LDRReading = digitalRead(LDR_Pin); 
//    Serial.println(LDRReading);
//    Serial.println("lalalal");
      if (!dmpReady) return;
      mpuInterrupt = false;
      mpuIntStatus = mpu.getIntStatus();
      fifoCount = mpu.getFIFOCount();
      if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
          mpu.resetFIFO();
      } else if (mpuIntStatus & 0x02) {
          while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();
          mpu.getFIFOBytes(fifoBuffer, packetSize);
          fifoCount -= packetSize;
          #ifdef OUTPUT_READABLE_REALACCEL
              mpu.dmpGetQuaternion(&q, fifoBuffer);
              mpu.dmpGetAccel(&aa, fifoBuffer);
              mpu.dmpGetGravity(&gravity, &q);
              mpu.dmpGetLinearAccel(&aaReal, &aa, &gravity);
              if(flag==1){
/*
                Serial.print(aaReal.x);
                Serial.print("\t");
                Serial.print(aaReal.y);
                Serial.print("\t");
                Serial.println(aaReal.z);
*/
            
                if(i<10){
                  arrx[i] = aaReal.x;
                  arry[i] = aaReal.y;
                  arrz[i] = aaReal.z;
                  i++;
                }
                else{
                  for(int j=0; j<10; j++){
                    sx +=arrx[i];
                    sy +=arry[i];
                    sz +=arrz[i];
                  }
                  Serial.print(sx/10);
                  Serial.print("\t");
                  Serial.print(sy/10);
                  Serial.print("\t");
                  Serial.println(sz/10);
                  sx = sy = sz = i = 0;

                }
                }
                else{
                  Serial.println("first reading for callibration..");
                  Serial.print(aaReal.x);
                  Serial.print("\t");
                  Serial.print(aaReal.y);
                  Serial.print("\t");
                  Serial.println(aaReal.z);
                  Serial.println("callibrate and here you go....");
                  flag = 1;
                }
              
              
          #endif
          blinkState = !blinkState;
          digitalWrite(LED_PIN, blinkState);
      }
}
