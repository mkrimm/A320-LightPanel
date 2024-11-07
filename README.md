| Supported Targets | Arduino Mirco | Atmega32u4 |
| ----------------- | ------------- | ---------- |


# A320 overhead light panel controller
* [What is this?](#what-is-this)
* [Whys should I use this?](#when-should-i-use-this)
* [Getting started](#getting-started)
  * [Requirements](#requirements)
    * [Hardware](#hardware)
    * [Software](#software)
  * [Configure the project](#configure-the-project)
  * [Debugging](#debugging)
* [Circuit diagram](#circuit-diagram)
* [Print file](#print-files)
* [Contribute](#contribute)
<br><br>


# What is this?
This project has the intention to build a A320 overhead panel, espacial the light control panel section.
Maybe in the futur this project will be extend with other functions of the overhead panel.

This project use the [ArduinoJoystickLibrary](https://github.com/MHeironimus/ArduinoJoystickLibrary) by [MHeironimus](https://github.com/MHeironimus).

> **_NOTE:_** <br>
This project is configured to run it direct in Microsoft VS Code.
Just clone, open the project in VS Code.
If you did not install the [PlatformIO](https://platformio.org) extension VS Code will ask you to install the extension.

<br><br><br><br>
IMAGE
<br><br><br><br><br>

<br><br>


# Why should I use this?
It is completly up to you to use this project.
You can us this project as an example, as an inspiration or just as it is.
<br><br>


# Getting started
Let get started and learn how you can us the project.
<br><br>


## Requirements
As always we have some requirements to us this projetc.
In the following you will learn which one.
<br><br>


#### Hardware
The project is only tested with an Arduino Micro derivat with the Atmega32u4 chip.
I used the this [Arduino Mirco](https://www.amazon.de/dp/B0CXXPNQS1?ref=ppx_yo2ov_dt_b_fed_asin_title) derivat.

<br><br><br><br>
IMAGE
<br><br><br><br><br>

<br><br>

#### Software
To us the light controller in your flight simulator you should us a 3th party software to connect the botton / switches direct to simulator variables.
Why?
For example in MSFS 2020 you can not map all lights of the A320 to buttons.
Due to this reason I choose the app [SPAD.next](https://www.spadnext.com/home.html).
To make the starting point to you as easy as possible you can find a SPAD.next profile for the Fenix A320 in the [doc]() folder.
<br><br>


## Configure the project
Before you build the project, make sure to set the HID report id fits to your system.
To check this have a look to the [main.h](src/main.h#L19) file on line 19.
<br><br>


## Debugging
If you have issues with the Arduino you can enable the [debug mode](src/main.h#16) and use the serial monitor to have a look to the debug messages.
Example output of the debug mode.

<br><br><br><br>
IMAGE
<br><br><br><br><br>

<br><br>


# Circuit diagram
To be able to use the Arduino micro without additional IC's or the like, I decided to connect each switch to the micro's analog inputs via a voltage divider.
I choose this approach because I had everything available at home to finish the circuit.

You can find the full [cicuit diagram]() in the [doc](doc) folder.
<br><br>


# Print files
All files to build the light control panel by your own, you fill find on [cults]().
I printed all parts in PLA.
<br><br>


## Contribute
Pull requests are welcome.
For major changes, please open an issue first to discuss what you would like to change.
Please make sure to update tests as appropriate.
