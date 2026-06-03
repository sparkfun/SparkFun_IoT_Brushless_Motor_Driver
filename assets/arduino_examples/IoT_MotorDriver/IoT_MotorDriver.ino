/******************************************************************************
	IoT Motor Driver Example

	Written By:
		Madison Chodikov
		Eric Orosel
	Company: SparkFun Electronics	
	Date: September 1 2023

	This sketch is a stripped down version of the firmware that is preprogrammed
	on the IoT Motor Driver. It is based on the open loop, velocity motor control
	example from the SimpleFOC Arduino library.

	This sketch will spin the motor based on the button inputs:
		- Button 13: Starts/Stops the motor rotation
		- Button 14: When spinning, switches the direction of rotation

===============================================================================
	Products:
		IoT Brushless Motor Driver: https://www.sparkfun.com/products/22132

	Repository:
		https://github.com/sparkfun/SparkFun_IoT_Brushless_Motor_Driver
===============================================================================

	SparkFun code, firmware, and software is released under the MIT 
	License	(http://opensource.org/licenses/MIT).

	Distributed as-is; no warranty is given.
******************************************************************************/

#include <Wire.h>
#include <SimpleFOC.h> //http://librarymanager/All#Simple%20FOC


//GPIO
#define auxBtn2   13
#define auxBtn1   14  

//driver
#define uh16      16
#define ul17      17
#define vh18      18
#define wh19      19
#define vl23      23
#define wl33      33
#define curSense  32

bool state = true;

//motor driver
BLDCMotor motor = BLDCMotor(7);
BLDCDriver6PWM driver = BLDCDriver6PWM(uh16, ul17, vh18, vl23, wh19, wl33,  curSense);
float target_velocity = 0.0;
Commander command = Commander(Serial);
void doTarget(char* cmd) { command.scalar(&target_velocity, cmd); }
void doLimit(char* cmd) { command.scalar(&motor.voltage_limit, cmd); }

//////////////////////motor demo stuff///////////////////////////
struct Button{
  const uint8_t PIN;
  uint32_t numberKeyPresses;
  bool pressed;
};
Button aux1 = {auxBtn1, 0, false};
Button aux2 = {auxBtn2, 0, false};

void IRAM_ATTR isr1(){
  aux1.pressed = true;
  target_velocity = target_velocity*(-1);
  Serial.println("Changing directions.. ");
}

void IRAM_ATTR isr2(){
  aux2.numberKeyPresses++;
  aux2.pressed = true;
  
  if((aux2.numberKeyPresses % 2) == 0)
  {
    target_velocity = 0;
    Serial.println("Stopping motor.. ");
  }
  else
  {
    target_velocity = 5;
    motor.enable();
    Serial.println("Starting motor.. ");
  }
}


void setup() {

  //motor demo stuff
  driver.voltage_power_supply = 3.3;
  driver.pwm_frequency = 20000;
  driver.voltage_limit = 4;
  driver.init();
  motor.linkDriver(&driver);
  motor.voltage_limit = 4;
  motor.controller = MotionControlType::velocity_openloop;
  motor.init();
  motor.disable();
  pinMode(aux1.PIN, INPUT_PULLUP); // Sets pin 14 on the ESP32 as an interrupt
  attachInterrupt(aux1.PIN, isr1, FALLING); // Triggers when aux1 is pulled to GND (button pressed)
  pinMode(aux2.PIN, INPUT_PULLUP); // Sets pin 13 on the ESP32 as an interrupt
  attachInterrupt(aux2.PIN, isr2, FALLING); // Triggers when aux2 is pulled to GND (button pressed)
  delay(100);

  Serial.begin(115200);
}

/////////////////////////////////////////////////////////////////////////
void loop() { 

  // Button Press ISR
  if(aux1.pressed){ 
    aux1.pressed = false;
  }
  
  // Turning motor on and off
  if(aux2.pressed){ 
    aux2.pressed = false;
  }

  // open loop velocity movement
  // using motor.voltage_limit and motor.velocity_limit
  // Basic motor movement
  motor.move(target_velocity);

  // user communication
  command.run();

  delay(5);
}
