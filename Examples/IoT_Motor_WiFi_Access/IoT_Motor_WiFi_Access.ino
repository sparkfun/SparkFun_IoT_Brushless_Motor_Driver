/*
  Steps:
  1. Connect to the access point "yourAp"
  2. Point your web browser to http://192.168.4.1/H to turn the motor on or http://192.168.4.1/L to turn it off
     OR
     Run raw TCP "GET /H" and "GET /L" on PuTTY terminal with 192.168.4.1 as IP address and 80 as port

  Original WiFi Code created for arduino-esp32 on 04 July, 2018
  by Elochukwu Ifediora (fedy0)
*/

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

// To download the Arduino Simple FOC Library, use this link: https://docs.simplefoc.com/arduino_simplefoc_library_showcase
#include <SimpleFOC.h> 

// Set these to your desired credentials.
const char *ssid = "ESP32IoTMotorDriver";
const char *password = "your-password"; // Make sure the new password set is at least 7 characters

WiFiServer server(80);

// BLDC motor & driver instance
BLDCMotor motor = BLDCMotor(8);

// BLDCDriver6PWM(int phA_h,int phA_l,int phB_h,int phB_l,int phC_h,int phC_l, int en)
BLDCDriver6PWM driver = BLDCDriver6PWM(16,17, 18,23, 19,33, 34);

//target variable in rad/s (radians per second)
float target_velocity_rps = 3;

// instantiate the commander
Commander command = Commander(Serial);
void doTarget(char* cmd) { command.scalar(&target_velocity_rps, cmd); }
void doLimit(char* cmd) { command.scalar(&motor.voltage_limit, cmd); }



void setup() {
  Serial.begin(115200);

  // Begin example of the magnetic sensor code
  Serial.println("Example: Communication over WiFi with the IoT Motor Driver");

  Serial.println();
  Serial.println("Configuring access point...");

  // ********* WiFi config *********
  // You can remove the password parameter if you want the AP to be open.
  // a valid password must have more than 7 characters
  if (!WiFi.softAP(ssid, password)) {
    log_e("Soft AP creation failed.");
    while(1);
  }
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();

  Serial.println("Server started");

  // ********* Driver config *********
  // power supply voltage [V]
  driver.voltage_power_supply = 3.3; // ESP32 3.3V supply pin
  // PWM Configuration
  driver.pwm_frequency = 20000;
  // this value is fixed on startup
  driver.voltage_limit = 4;
  driver.init();
  // link the motor and the driver to enable usage
  motor.linkDriver(&driver);
  // limit the voltage to be set to the motor
  motor.voltage_limit = 4;   // [V]
  // open loop control config
  motor.controller = MotionControlType::velocity_openloop;
  // init motor hardware
  motor.init();
 
  // add target command T
  command.add('T', doTarget, "target velocity");
  command.add('L', doLimit, "voltage limit");

  Serial.println("Motor ready!");
  Serial.print("Set target velocity [rad/s]: ");
  Serial.println(target_velocity_rps);
  _delay(1000);


}

void loop() 
{
  // Basic motor movement
  motor.move(target_velocity_rps);
  // user communication to motor
  command.run();

  WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("Click <a href=\"/H\">here</a> to turn ON the motor.<br>");
            client.print("Click <a href=\"/L\">here</a> to turn OFF the motor.<br>");

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /H")) {
          target_velocity_rps = 3;
        }
        if (currentLine.endsWith("GET /L")) {
          target_velocity_rps = 0;
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
