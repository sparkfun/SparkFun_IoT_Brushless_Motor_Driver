---
icon: material/book-open-page-variant
---

# Introduction
<div class="grid cards desc" markdown>

-   <a href="https://www.sparkfun.com/products/22132">
	**IoT Brushless Motor Driver**<br>
	**SKU:** ROB-22132
	
	---
	
	<figure markdown>
	![Product Thumbnail](https://cdn.sparkfun.com/assets/parts/2/1/9/9/5/22132-_01.jpg)
	</figure></a>

	<center>
	<article class="video_desc">
	<iframe src="https://www.youtube.com/embed/4GGIxnUDrU0" title="Product Showcase: SparkFun IoT Brushless Motor Driver (ESP32 WROOM, TMC6300)" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
	</article>
	![QR code to play video](./assets/img/qr_code/product_video.png){ .qr }
	</center>


-	The SparkFun IoT Brushless Motor Driver is an all-in-one development platform. It includes all the components to create a simple IoT device or learn about [control systems](https://en.wikipedia.org/wiki/Control_system). On the boaard, users will find an ESP32 microcontroller, a TMC6300 motor driver, a [gimbal motor](https://www.sparkfun.com/products/20441), a TMAG5273 hall-effect sensor, three INA240A1 inline current sensors, an MCP6021T low-side current sensor, two user buttons, a Qwiic connector, a 3-pin JST connector (for the gimbal motor), and a WS2812 RGB LED.

	The TMC6300 from [ADI + Trinamic](https://www.trinamic.com/) is a powerful and easy-to-use three-phase motor driver with up to 2A (1.4A<sub>RMS</sub>) of total drive current. Separate high-side and low-side control of the three half-bridges allows for incredible control of each phase of the [motor commutation](https://fab.cba.mit.edu/classes/865.21/topics/power_electronics/commutation/#bldc-commutation). We've found the [*Arduino Simple Field Oriented Control*](https://docs.simplefoc.com/) library to work well with the TMC6300 motor driver.
  
	However, a field-oriented control (FOC) algorithm requires some feedback to close and optimize the control loop. Therefore, we integrated a TMAG5273 hall-effect sensor and INA240A1 current sensor amplifiers *(both manufactured by [Texas Instruments](https://www.ti.com/))* into the design of the IoT motor driver board. This allows users to incorporate a [position sensor](https://docs.simplefoc.com/position_sensors) and [current sensing](https://docs.simplefoc.com/current_sense) into the FOC algorithm or any feedback control loop they choose to implement.

	<center>
	[![QR code to product page](./assets/img/qr_code/product-low.png){ .tinyqr }&nbsp;&nbsp;&nbsp;Purchase from SparkFun :fontawesome-solid-cart-plus:{ .heart }](https://www.sparkfun.com/products/22132){ .md-button .md-button--primary }
	</center>

</div>


## :fontawesome-solid-list-check:&nbsp;Required Materials
To get started, users will need a few items. Now some users may already have a few of these items, feel free to modify your cart accordingly.

* Computer with an operating system (OS) that is compatible with all the software installation requirements.
* [USB 3.1 Cable A to C - 3 Foot](https://www.sparkfun.com/products/14743) - Used to interface with the IoT Brushless Motor Driver (1)
{ .annotate }

	1.	If your computer doesn't have a USB-A slot, then choose an appropriate cable or adapter.

* [SparkFun IoT Brushless Motor Driver (ESP32 WROOM, TMC6300)](https://www.sparkfun.com/products/22132) (1)
{ .annotate }

	1. The included gimbal motor requires a 6 to 8V power supply. However, for zero-load, low-speed testing, we have found the power from the USB connection to be sufficient.


<div class="grid cards col-4" markdown>

-   <a href="https://www.sparkfun.com/products/14743">
	<figure markdown>
	![USB 3.1 Cable A to C - 3 Foot](https://cdn.sparkfun.com/assets/parts/1/2/9/7/2/14743-USB_3.1_Cable_A_to_C_-_3_Foot-01.jpg)
	</figure>

	---

	**USB 3.1 Cable A to C - 3 Foot**<br>
	CAB-14743</a>

-   <a href="https://www.sparkfun.com/products/22132">
	<figure markdown>
	![Product Thumbnail](https://cdn.sparkfun.com/assets/parts/2/1/9/9/5/22132-_01.jpg)
	</figure>

	---

	**IoT Brushless Motor Driver (ESP32 WROOM, TMC6300)**<br>
	ROB-22132</a>

</div>



??? note "Jumper Modification"
	To modify the [jumper](hardware_overview/#jumper), users will need [soldering equipment](https://www.sparkfun.com/categories/49) and/or a [hobby knife](https://www.sparkfun.com/categories/379).

	!!! tip "New to jumper pads?"
		Check out our [Jumper Pads and PCB Traces Tutorial](https://learn.sparkfun.com/tutorials/664) for a quick introduction!

		<div class="grid cards col-4" markdown  align="center">

		-   <a href="https://learn.sparkfun.com/tutorials/664">
			<figure markdown>
			![Tutorial thumbnail](https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/6/6/4/PCB_TraceCutLumenati.jpg)
			</figure>

			---
			
			**How to Work with Jumper Pads and PCB Traces**</a>

		</div>



	<div class="grid cards col-4" markdown>

	-   <a href="https://www.sparkfun.com/products/9325">
		<figure markdown>
		![Product Thumbnail](https://cdn.sparkfun.com/assets/parts/2/8/7/3/09325_9161-Solder_Lead_Free_-_100-gram_Spool-01.jpg)
		</figure>		

		---

		**Solder Lead Free - 100-gram Spool**<br>
		TOL-09325</a>

	-   <a href="https://www.sparkfun.com/products/14228">
		<figure markdown>
		![Product Thumbnail](https://cdn.sparkfun.com/assets/parts/1/2/1/7/3/14228-01.jpg)
		</figure>

		---
		
		**Weller WLC100 Soldering Station**<br>
		TOL-14228</a>


	-   <a href="https://www.sparkfun.com/products/14579">
		<figure markdown>
		![Product Thumbnail](https://cdn.sparkfun.com/assets/parts/1/2/7/2/5/14579-Chip_Quik_No-Clean_Flux_Pen_-_10mL-01.jpg)
		</figure>

		---

		**Chip Quik No-Clean Flux Pen - 10mL**<br>
		TOL-14579</a>


	-   <a href="https://www.sparkfun.com/products/9200">
		<figure markdown>
		![Product Thumbnail](https://cdn.sparkfun.com/assets/parts/2/6/4/6/09200-Hobby_Knife-01.jpg)
		</figure>

		---

		**Hobby Knife**<br>
		TOL-09200</a>
	</div>





## :material-bookshelf:&nbsp;Suggested Reading

As a more sophisticated product, we will skip over the more fundamental tutorials (i.e. [**Ohm's Law**](https://learn.sparkfun.com/tutorials/voltage-current-resistance-and-ohms-law) and [**What is Electricity?**](https://learn.sparkfun.com/tutorials/what-is-electricity)). However, below are a few tutorials that may help users familiarize themselves with various aspects of the board.


<div class="grid cards col-4" markdown align="center">

-   <a href="https://learn.sparkfun.com/tutorials/908">
	<figure markdown>
	![Tutorial Thumbnail](https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/9/0/8/USB-to-serial_converter_CH340-closeup.jpg)
	</figure>

	---
	
	**How to Install CH340 Drivers**</a>

-   <a href="https://learn.sparkfun.com/tutorials/2353">
	<figure markdown>
	![Tutorial Thumbnail](https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/2/3/5/3/assembly_batt.jpg)
	</figure>

	---
	
	**ESP32 Thing Plus (USB-C)**</a>

-   <a href="http://docs.sparkfun.com/SparkFun_Three_Phase_Motor_Driver-TMC6300/">
	<figure markdown>
	![Tutorial Thumbnail](https://cdn.sparkfun.com/c/264-148/assets/parts/2/1/6/9/6/21867-_SparkFun_Brushless_Motor_Drive-_04.jpg)
	</figure>

	---
	
	**TMC6300 BLDC Motor Driver**</a>

-   <a href="https://learn.sparkfun.com/tutorials/61">
	<figure markdown>
	![Tutorial Thumbnail](https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/6/1/arduinoThumb.jpg)
	</figure>

	---
	
	**Installing the Arduino IDE**</a>

-   <a href="https://learn.sparkfun.com/tutorials/1265">
	<figure markdown>
	![Tutorial Thumbnail](https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/1/2/6/5/sparkfun_boards.PNG)
	</figure>

	---
	
	**Installing Board Definitions in the Arduino IDE**</a>

-   <a href="https://learn.sparkfun.com/tutorials/15">
	<figure markdown>
	![Tutorial Thumbnail](https://cdn.sparkfun.com/c/264-148/assets/b/e/4/b/2/50f04b99ce395fd95e000001.jpg)
	</figure>

	---
	
	**Installing an Arduino Library**</a>

-   <a href="https://learn.sparkfun.com/tutorials/62">
	<figure markdown>
	![Tutorial Thumbnail](https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/6/2/Input_Output_Logic_Level_Tolerances_tutorial_tile.png)
	</figure>

	---
	
	**Logic Levels**</a>

-   <a href="https://learn.sparkfun.com/tutorials/51">
	<figure markdown>
	![Tutorial Thumbnail](https://cdn.sparkfun.com/c/264-148/assets/f/9/c/8/a/512e869bce395fbc64000002.JPG)
	</figure>

	---
	
	**Pulse Width Modulation**</a>

-   <a href="https://learn.sparkfun.com/tutorials/89">
	<figure markdown>
	![Tutorial Thumbnail](https://cdn.sparkfun.com/c/264-148/assets/3/7/6/6/0/51c48875ce395f745a000000.png)
	</figure>

	---
	
	**Analog vs. Digital**</a>

-   <a href="https://learn.sparkfun.com/tutorials/82">
	<figure markdown>
	![Tutorial Thumbnail](https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/8/2/I2C-Block-Diagram.jpg)
	</figure>

	---
	
	**I2C**</a>

-   <a href="https://learn.sparkfun.com/tutorials/16">
	<figure markdown>
	![Tutorial Thumbnail](https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/1/6/spiThumb_Updated.jpg)
	</figure>

	---
	
	**SPI**</a>

-   <a href="https://learn.sparkfun.com/tutorials/8">
	<figure markdown>
	![Tutorial Thumbnail](https://cdn.sparkfun.com/c/264-148/assets/7/d/f/9/9/50d24be7ce395f1f6c000000.jpg)
	</figure>

	---
	
	**Serial Communication**</a>

-   <a href="https://learn.sparkfun.com/tutorials/5">
	<figure markdown>
	![Tutorial Thumbnail](https://cdn.sparkfun.com/c/264-148/assets/e/3/9/9/4/51d9fbe1ce395f7a2a000000.jpg)
	</figure>

	---
	
	**How to Solder: Through-Hole Soldering**</a>

-   <a href="https://learn.sparkfun.com/tutorials/664">
	<figure markdown>
	![Tutorial Thumbnail](https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/6/6/4/PCB_TraceCutLumenati.jpg)
	</figure>

	---
	
	**How to Work with Jumper Pads and PCB Traces**</a>

-   <a href="https://learn.sparkfun.com/tutorials/126">
	<figure markdown>
	![Tutorial Thumbnail](https://cdn.sparkfun.com/c/264-148/assets/4/c/6/4/7/52a22672757b7f511d8b456b.jpg)
	</figure>

	---
	
	**Motors and Selecting the Right One**</a>

-   <a href="https://learn.sparkfun.com/tutorials/115">
	<figure markdown>
	![Tutorial Thumbnail](https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/1/1/5/acDC.jpg)
	</figure>

	---
	
	**Alternating Current (AC) vs. Direct Current (DC)**</a>

</div>

??? info "Need to control a different type of motor?"
	This tutorial is primarily focused on utilizing the TMC6300 motor driver to control a 3-phase brushless DC (BLDC) motor. We would recommend users explore other products for these specific motors and actuators. Below, are additional product tutorials and resources for our other actuator and motor types:

	=== "Brushed DC Motors"

		<div class="grid cards col-4" markdown align="center">

		-   <a href="https://learn.sparkfun.com/tutorials/934">
			<figure markdown>
			![Tutorial Thumbnail](https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/9/3/4/15451-SparkFun_Qwiic_Motor_Driver-01.jpg)
			</figure>

			---
			
			**Hookup Guide for the Qwiic Motor Driver**</a>

		-   <a href="https://learn.sparkfun.com/tutorials/526">
			<figure markdown>
			![Tutorial Thumbnail](https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/5/6/2/13845-02.jpg)
			</figure>

			---
			
			**TB6612FNG Hookup Guide**</a>
		
		</div>


	=== "Stepper Motors"

		<div class="grid cards col-4" markdown align="center">

		-   <a href="https://learn.sparkfun.com/tutorials/1200">
			<figure markdown>
			![Tutorial Thumbnail](https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/1/2/0/0/example8_demo.gif)
			</figure>

			---
			
			**SparkFun ProDriver Hookup Guide**</a>

		-   <a href="https://learn.sparkfun.com/tutorials/210">
			<figure markdown>
			![Tutorial Thumbnail](https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/2/4/1/EasyDriver_Angled.jpg)
			</figure>

			---
			
			**Easy Driver Hook-up Guide**</a>
		
		</div>


	=== "Servos"

		<div class="grid cards col-4" markdown align="center">

		-   <a href="https://learn.sparkfun.com/tutorials/1109">
			<figure markdown>
			![Tutorial Thumbnail](https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/1/1/0/9/Basic_Servo_Guide_Demo.gif)
			</figure>

			---
			
			**Basic Servo Control for Beginners**</a>

		-   <a href="https://learn.sparkfun.com/tutorials/526">
			<figure markdown>
			![Tutorial Thumbnail](https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/5/2/6/servo_6.jpg)
			</figure>

			---
			
			**Hobby Servo Tutorial**</a>
		
		-   <a href="https://learn.sparkfun.com/tutorials/910">
			<figure markdown>
			![Tutorial Thumbnail](https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/9/1/0/Assembly_Servo.gif)
			</figure>

			---
			
			**Pi Servo pHAT (v2) Hookup Guide**</a>
		
		</div>