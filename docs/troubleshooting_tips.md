---
icon: sfe-logo
---

!!! warning "Need Help?"
	If you need technical assistance or more information on a product that is not working as you expected, we recommend heading on over to the [SparkFun Technical Assistance](https://www.sparkfun.com/technical_assistanc) page for some initial troubleshooting.

	<center>
	[SparkFun Technical Assistance Page](https://www.sparkfun.com/technical_assistance){ .md-button .md-button--primary }
	</center>
	
	If you can't find what you need there, the [SparkFun Forums](https://forum.sparkfun.com/index.php) is a great place to search product forums and ask questions.
	
	!!! info "Account Registration Required"
		If this is your first visit to our forum, you'll need to create a [Forum Account](https://forum.sparkfun.com/ucp.php?mode=register) to post questions.

## ESP32 Compile Error
If users run into an error similar to, `fatal error: soc/soc_caps.h: No such file or directory`, it may be due to an issue with the version of the ESP32 Arduino core that is installed in the **Boards Manager**. Users should make sure the have the latest version of the ESP32 Arduino core installed; or at least a version later than `v2.0.1`.

!!! info
	For more information, please reference this [forum post](https://community.simplefoc.com/t/compilation-error/1700) for the Simple FOC Arduino library.