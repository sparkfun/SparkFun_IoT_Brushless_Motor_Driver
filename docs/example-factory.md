This example, allows users to reprogram their board with the same sketch that it comes pre-programmed with from SparkFun.


## Example Code
After installing and setting up the Arduino IDE and the Simple FOC Arduino library, users will need to upload the following example code using the **SparkFun ESP32 Thing Plus C** board definition. This code can be copied or downloaded below:

<center>
[:octicons-download-16:{ .heart } Download `IoT_MotorDriver.ino` Example Code](./assets/arduino_examples/IoT_MotorDriver/IoT_MotorDriver.ino){ .md-button .md-button--primary }
</center>

!!! code "Example Code"
	``` c++ title="IoT_MotorDriver.ino"
		--8<-- "./docs/assets/arduino_examples/IoT_MotorDriver/IoT_MotorDriver.ino"
	```

### Running the Motor
By default, the motor should be disabled and spin freely. Users can utilize the user buttons ++"13"++ and ++"14"++ to control the motor.

* ++"13"++ - Starts and stops the motor spin
* ++"14"++ - Reverses the direction of the motor's rotation, when it is spinning

!!! tip "Motor Overheating"
	When the motor is stopped, the motor driver is still enabled. Therefore, current is still running through the stator coils and holding the motor in place. After a few minutes, users may notice that the motor begins to heat up a bit.

	If this becomes an issue, users can modify their code to disable the motor driver when the motor stops. This will prevent the motor from heating up, but the motor will spin freely as the motor driver is no longer engaged.

	??? code "Modification"
		Modify the sketch and insert `motor.disable();` between lines `80` - `81`.

		``` c++ hl_lines="80 81" title="DC.ino"
			--8<-- "./docs/assets/arduino_examples/IoT_MotorDriver/IoT_MotorDriver.ino"
		```
