//Arduino Code for Stepper DC Motor 
//Final Prototype

int buttonPin=7; //Input pin of the button
int limitPin=8; //Input pin of the device limit button
int motorPin=3; //Output pin for the motor speed
int switchPin=4; //Input pin of the switch (OFF=Right (1), ON=LEFT (0))
int pin1=5; //Motor output 1
int pin2=6; //Motor output 2

void setup()
{
  Serial.begin(9600); //start the serial monitor
  pinMode(buttonPin,INPUT); //setting inputs
  pinMode(limitPin,INPUT);
  pinMode(switchPin,INPUT);
  pinMode(motorPin,OUTPUT); //setting outputs
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
}

void setMotor(boolean reverse, boolean button, boolean limit){
    if(button){                      //when the button is pressed
      if(limit){                     //if the device is at the limit
        analogWrite(motorPin,255);     //rotate the motor, speed is between 0 to 255.
        digitalWrite(pin1, !reverse);  //CW if on right-handed mode, CCW if on left-handed mode
        digitalWrite(pin2, reverse);
      }
      else if(!limit){               //if the device is not at the limit
        analogWrite(motorPin,255);   //rotate the motor
        digitalWrite(pin1, reverse); //CCW if on right-handed mode, CW if on left-handed mode
        digitalWrite(pin2, !reverse);
      }
    }
    else{                             //if the button isn't pressed
      analogWrite(motorPin,0);        //don't rotate the motor
      digitalWrite(pin1, reverse);
      digitalWrite(pin2, !reverse);
  }
}
//DC Motor Reverse
//motorPin=3 (assign motor speed), Pin1=5(motor-output1), Pin2=6(motor-output2)
void loop(){
  boolean button=digitalRead(buttonPin);
  boolean limit=digitalRead(limitPin);
  boolean reverse=digitalRead(switchPin);
  Serial.println(buttonext);
  Serial.println(buttonret);
  Serial.println(reverse);
  setMotor(reverse, button, limit);
  if(button){
    delay(5500);                   //Motor rotation time input (set in microseconds)
  }
}

