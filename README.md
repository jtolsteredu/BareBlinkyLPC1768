# BareBlinkyLPC1768

BareBlinkyLPC1768 is a bare metal blinky for LPC1768 using the GNU ARM Embedded Toolchain. This is meant to be a pedagogical project that helps the user learn from scratch, but with an attempt to avoid TLDR. This document assumes the user has a background in software development, knows how to use the command line, and is familiar with Eclipse.

The development board used is the [NXP mbed LPC1768](https://developer.mbed.org/platforms/mbed-LPC1768/), which is designed for the [ARMmbed IoT Device Platform](https://www.mbed.com/en/). This project, however, does not use the mbed platform other than taking advantage of the ease of flashing a binary to the device over USB.

The development platform is Mac OS X Sierra using the GNU ARM Embedded Toolchain and the Eclipse IDE for C/C++ Developers.

About the author: Willie Walker has been doing software development since the late 1970's.

## Related Documentation

### Hardware

* [ARMmbed summary of NXP mbed LPC1768](https://developer.mbed.org/platforms/mbed-LPC1768/)
* [NXP LPC1768 Homepage](http://www.nxp.com/products/microcontrollers-and-processors/arm-processors/lpc-cortex-m-mcus/lpc1700-cortex-m3/512kb-flash-64kb-sram-ethernet-usb-lqfp100-package:LPC1768FBD100)
	* [LPC1769/68/67/66/65/64/63 datasheet](http://www.nxp.com/documents/data_sheet/LPC1769_68_67_66_65_64_63.pdf)
	* [UM10360 - LPC176x/5x User manual](http://www.nxp.com/documents/user_manual/UM10360.pdf)
	* [mbed-005.1 schematic](https://developer.mbed.org/media/uploads/chris/mbed-005.1.pdf)

### Development Environment

* [GNU ARM Embedded Toolchain](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads)
* [Eclipse IDE for C/C++ Developers - Neon2](http://www.eclipse.org/downloads/packages/eclipse-ide-cc-developers/neon2)

## Development Environment Setup

### GNU ARM Embedded Toolchain

Grab and unzip the [GNU ARM Embedded Toolchain](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads) from the ARM Developer website and then set up your system PATH to point to it:

```
tar xjf gcc-arm-none-eabi-6_2-2016q4-20161216-mac.tar.bz2
cd gcc-arm-none-eabi-6_2-2016q4-20161216
sudo sh -c "echo `pwd`/bin > /etc/paths.d/gcc-arm"
```

You need to log out of your terminal window and back in again to see the effect.

### Eclipse IDE for C/C++ Developers

* [Remove the older version from your machine](http://stackoverflow.com/questions/3185664/how-to-delete-eclipse-completely-including-settings-and-plugins-from-mac-os-x).
* Navigate to the [downloads section at eclipse.org](https://www.eclipse.org/downloads/eclipse-packages/) and get the 64 bit version of Eclipse IDE for C/C++ Developers.

	```
	tar xvf eclipse-cpp-neon-2-macosx-cocoa-x86_64.tar
	sudo mv Eclipse.app /Applications
	```

* In the Eclipse app:
	* Help->Install New Software...
	* Add...
	* GNU ARM Eclipse Plug-ins
	* http://gnuarmeclipse.sourceforge.net/updates
	* [x] GNU ARM C/C++ Cross Development Tools

* Then:
    * Eclipse->Preferences...
    * C/C++->Build->Workspace Tools Paths
    	* Default toolchain: GNU Tools for ARM Embedded Processors
    	* Toolchain folder: *the bin holding your GNU ARM Embedded Toolchain*
    
At this point, you can create a new app.

* File->New->C Project
	* Hello World ARM C Project
	* Cross ARM GCC

In the project, set it up to output *.bin files for the Debug and Release build configurations (you need to do this step twice - once for each build configuration):

* File->Properties
* C/C++ Build->Settings->Tool Settings->Cross ARM GNU Create Flash Image->General
	* Output file format (-O): Raw binary

## Sources

The sources in this repo have been acquired from various places on the web. It is somewhat of a challenge to find the original source, but this README and the source code will be updated as I find these.

Potential sources of the needed files include the following locations, but I'm having trouble getting all these working together as one:

`core_cm3.h` - Buried in [ARM-software github project](https://github.com/ARM-software/CMSIS)

`LPC17xx.h` - [lpc17xx.h](http://www.keil.com/dd/docs/arm/nxp/lpc17xx/lpc17xx.h) from [ARM Keil](http://www.keil.com/dd/chip/4868.htm)

`{system,startup}_LPC17xx.{c,h,cpp}`, `LPC17xx.h`, `LPC1768.ld` - [mbed-os](https://github.com/ARMmbed/mbed-os) from the [ARMmbed github project](https://github.com/ARMmbed)

