// Open loop motor control example
#include <SimpleFOC.h>


// BLDC motor & driver instance
// BLDCMotor motor = BLDCMotor(pole pair number);
BLDCMotor motor = BLDCMotor(7);
// BLDCDriver3PWM driver = BLDCDriver3PWM(pwmA, pwmB, pwmC, Enable(optional));
BLDCDriver6PWM driver = BLDCDriver6PWM(5, 6, 9,10, 3, 11);

// Stepper motor & driver instance
//StepperMotor motor = StepperMotor(50);
//StepperDriver4PWM driver = StepperDriver4PWM(9, 5, 10, 6,  8);


//target variable
float target_velocity = 6;

// // instantiate the commander
Commander command = Commander(Serial);
// void doTarget(char* cmd) { command.scalar(&target_velocity, cmd); }
// void doLimit(char* cmd) { command.scalar(&motor.voltage_limit, cmd); }

void setup() {

  // driver config
  // power supply voltage [V]
  driver.voltage_power_supply = 5;
  // limit the maximal dc voltage the driver can set
  // as a protection measure for the low-resistance motors
  // this value is fixed on startup
  driver.voltage_limit = 5;
  // pwm frequency to be used [Hz]
  // for atmega328 fixed to 32kHz
  // esp32/stm32/teensy configurable
  driver.pwm_frequency = 32000;
  

  driver.init();
  // link the motor and the driver
  motor.linkDriver(&driver);

  // limiting motor movements
  // limit the voltage to be set to the motor
  // start very low for high resistance motors
  // current = voltage / resistance, so try to be well under 1Amp
  motor.voltage_limit = 3;   // [V]
 
  // open loop control config
  motor.controller = MotionControlType::velocity_openloop;

  // init motor hardware
  motor.init();

  // add target command T
  // command.add('T', doTarget, "target velocity");
  // command.add('L', doLimit, "voltage limit");

  Serial.begin(115200);
  Serial.println("Motor ready!");
  Serial.println("Set target velocity [rad/s]");
  _delay(1000);

}

void loop() {

  // open loop velocity movement
  // using motor.voltage_limit and motor.velocity_limit
  motor.move(target_velocity);

  // user communication
  command.run();

  
}
