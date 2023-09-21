SparkFun IoT Brushless Motor Driver (ESP32 WROOM, TMC6300)
========================================

[![SparkFun IoT Brushless Motor Driver (ESP32 WROOM, TMC6300)](https://cdn.sparkfun.com/assets/parts/2/1/9/9/5/22132-_01.jpg)](https://www.sparkfun.com/products/22132)

[*SparkFun IoT Brushless Motor Driver (ESP32 WROOM, TMC6300) (ROB-22132)*](https://www.sparkfun.com/products/22132)

The SparkFun IoT Brushless Motor Driver is an all-in-one development platform. It includes all the components to create a simple IoT device or learn about [control systems](https://en.wikipedia.org/wiki/Control_system). On the boaard, users will find an ESP32 microcontroller, a TMC6300 motor driver, a [gimbal motor](https://www.sparkfun.com/products/20441), a TMAG5273 hall-effect sensor, three INA240A1 inline current sensors, an MCP6021T low-side current sensor, two user buttons, a Qwiic connector, a 3-pin JST connector (for the gimbal motor), and a WS2812 RGB LED.

The TMC6300 from [ADI + Trinamic](https://www.trinamic.com/) is a powerful and easy-to-use three-phase motor driver with up to 2A (1.4A<sub>RMS</sub>) of total drive current. Separate high-side and low-side control of the three half-bridges allows for incredible control of each phase of the [motor commutation](https://fab.cba.mit.edu/classes/865.21/topics/power_electronics/commutation/#bldc-commutation). We've found the [*Arduino Simple Field Oriented Control*](https://docs.simplefoc.com/) library to work well with the TMC6300 motor driver.

However, a field-oriented control (FOC) algorithm requires some feedback to close and optimize the control loop. Therefore, we integrated a TMAG5273 hall-effect sensor and INA240A1 current sensor amplifiers *(both manufactured by [Texas Instruments](https://www.ti.com/))* into the design of the IoT motor driver board. This allows users to incorporate a [position sensor](https://docs.simplefoc.com/position_sensors) and [current sensing](https://docs.simplefoc.com/current_sense) into the FOC algorithm or any feedback control loop they choose to implement.

Repository Contents
-------------------

* **[/docs](/docs/)** - Online documentation files
    * [assets](/docs/assets/) - Assets files
        * [arduino_examples](/docs/assets/arduino_examples/) - Example code
        * [board_files](/docs/assets/board_files/) - Files for the product design
            * [Eagle design files](/docs/assets/board_files/eagle_files.zip) (.zip)
            * [Schematic](/docs/assets/board_files/schematic.pdf) (.pdf)
            * [Dimensions](/docs/assets/board_files/dimensions.pdf) (.pdf)
        * [component_documentation](/docs/assets/component_documentation/) - Datasheets for hardware components
        * [img/hookup_guide/](/docs/assets/img/hookup_guide/) - Images for hookup guide documentation
* **[/Hardware](/Hardware/)** - Eagle design files (.brd, .sch)
* **[/Production](/Production/)** - Production files

Documentation
--------------

* **[Hookup Guide (mkdocs)](http://docs.sparkfun.com/SparkFun_IoT_Brushless_Motor_Driver/)** - Hookup guide for the IoT Brushless Motor Driver hosted by GitHub pages.

*Need to download or print our hookup guide?*

* [Print *(Print to PDF)* from Single-Page View](http://docs.sparkfun.com/SparkFun_IoT_Brushless_Motor_Driver/print_view)

Product Variants
----------------

* [ROB-22132](https://www.sparkfun.com/products/22132)- v1.0, Initial Release

Version History
---------------

* [v10](https://github.com/sparkfun/SparkFun_IoT_Brushless_Motor_Driver/releases/tag/v10) - Initial Release


License Information
-------------------

This product is ***open source***!

Please review the [`LICENSE.md`](./LICENSE.md) file for license information.

If you have any questions or concerns about licensing, please contact technical support on our [SparkFun forums](https://forum.sparkfun.com/viewforum.php?f=152).

Distributed as-is; no warranty is given.

- Your friends at SparkFun.
