#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver board1 = Adafruit_PWMServoDriver(0x40);       // called this way, it uses the default address 0x40   

#define SERVOMIN  125                                                 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  625                                                 // this is the 'maximum' pulse length count (out of 4096)
int frontleftfoot = 0;
int frontleftshoulder = 1;
int frontrightshoulder = 2;
int frontrightfoot = 3;
  
int backleftshoulder = 4;
int backrightshoulder = 5;
int backrightfoot = 6 ;
int backleftfoot = 7;
void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
  board1.begin();
  board1.setPWMFreq(60);                  // Analog servos run at ~60 Hz updates
 
}
void stand (void)
{
  //function for setting the dog to stand needs re arranging with a delay in between shoulders and feet.
      //shoulders 
      board1.setPWM(frontleftshoulder,0, angleToPulse(90));
      board1.setPWM(frontrightshoulder,0, angleToPulse(90));
      board1.setPWM(backleftshoulder,0, angleToPulse(90));
      board1.setPWM(backrightshoulder,0, angleToPulse(90));
      delay(100);
      //feet
      board1.setPWM(frontleftfoot, 0, angleToPulse(90));
      board1.setPWM(frontrightfoot,0, angleToPulse(90));
      board1.setPWM(backrightfoot,0, angleToPulse(90));
      board1.setPWM(backleftfoot,0, angleToPulse(90));

}
void lie(void)
{
  //shoulders 
      board1.setPWM(frontleftshoulder,0, angleToPulse(0));
      board1.setPWM(frontrightshoulder,0, angleToPulse(180));
      board1.setPWM(backleftshoulder,0, angleToPulse(180));
      board1.setPWM(backrightshoulder,0, angleToPulse(0));
      delay(100);
      //feet
      board1.setPWM(frontleftfoot, 0, angleToPulse(45));
      board1.setPWM(frontrightfoot,0, angleToPulse(135));
      board1.setPWM(backrightfoot,0, angleToPulse(45));
      board1.setPWM(backleftfoot,0, angleToPulse(135));

}
void loop() 
  { //for(int i=0; i<15; i++)
      //{ board1.setPWM(i, 0, angleToPulse(0) );}
    //delay(10);
    
    //for( int angle =0; angle<181; angle +=10)
      //{ for(int i=0; i<15; i++)
        //  { board1.setPWM(i, 0, angleToPulse(angle) );}
     // }
    //delay(10);
    while(1)
    {
      lie(); 
      delay(1000);
      stand();
      delay(1000);


    }
  }

int angleToPulse(int ang)                             //gets angle in degree and returns the pulse width
  {  int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);  // map angle of 0 to 180 to Servo min and Servo max 
     Serial.print("Angle: ");Serial.print(ang);
     Serial.print(" pulse: ");Serial.println(pulse);
     return pulse;
  }
