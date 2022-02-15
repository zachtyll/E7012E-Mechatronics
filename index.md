# E7012E-Mechatronics: Team Line Riders
This repository contains work done for the course E7012E - Mechatronics at LTU Spring 2019

## The Project
The task is to build an automated guided vehicle or AGV. The vehicle should be able to follow along a line track without deviating from the line and finish a track within a set time.

### The Team
![The team.](/E7012E-Mechatronics/docs/assets/Team 8 - Line Rider.JPG| width=100)
The team consists of [Jonathan Myrsell](https://www.linkedin.com/in/jonmyr/), [Ivar Rockström](https://www.linkedin.com/in/ivar/), [Julius Lundberg](https://www.linkedin.com/in/julius-lundberg/), [Anton Sundström](https://www.linkedin.com/in/anton-sundstr%C3%B6m-622431194/), [Zacharias Tyllström](https://www.linkedin.com/in/zacharias-tyllstrom/) and [Alejandro Salvador](https://www.linkedin.com/in/alejandro-salvador-cabo-9a6175156/). 

### The AGV
The tasks the team were set out to solve were to design and construct a
- [x] Line sensor using the ITR20001-T photo transistor
- [x] Hall sensor using the Hall Effect sensor SS441A, TO-92
- [x] Control a steering servo using PID
- [x] Control a DC motor using PID

### Line Sensor Array
The line sensor uses the [ITR20001-T](https://cdn-shop.adafruit.com/product-files/3930/ITR20001-T.pdf) optical interrupter (OI) to sense a black line in the floor. This is done by emitting IR and recieving the bounching light in the OI. The amount of measured light indicates if there is a black surface under the OI. The team was able to construct a tuneable ADC using the [LM339](https://www.ti.com/product/LM339) and connect it to the microcontrollers digital inputs by wire. This allowed the microcontroller to read the frequently updating OI at a high resolution without too much processing. An array of eight total sensors provided adequate range of measurement.

### Hall Sensors
Each back wheel was equipped with a custom built Hall sensor. These measured the speed of the back tires.

### Microcontroller
The AGV used an [Arduino M0 Pro](https://docs.arduino.cc/retired/boards/arduino-m0-pro) as the system processor.

### Energy Supply
The energy was routed to each component as described in the figure below.
![The energy routing schematic.](/E7012E-Mechatronics/docs/assets/power-schematic.png| width=100)

### Automatic Control Software
The motor speed was regulated by a simple PI controller and used the hall sensors as its input measurement. The sensor array was used to determine the steering angle of the RC car. As this task was more sophisticated a PID controller was used. Several experimental tests were carried out in order to find the best gains for the PID controller.

An additional feature that was implemented was that the RC car slowed down on tight turns, leading to less error in position due slippage of the wheels.

### Decoration
Due to the teams good humor, it was decided that the RC car shell was too dull and a more thematic hull was designed. Based on the classic game [Line Rider](https://en.wikipedia.org/wiki/Line_Rider). A small character was 3D-printed and a motor was connected to the base of its head in order to allow the prop to turn its head when cornering. Two eyes created from several LED lights accentuated the gaze of the charater. This added flair led to the RC car turning into a crowd favourite. Below is a picture of the RC car in action.
![RC car dressed with a Line Rider themed shell.](/E7012E-Mechatronics/docs/assets/line-rider.JPG| width=100)

### Results
The RC car performed adequately and placed on a fourth place in the time trials. Improvements for the future would be to tune the PID for the steering with a stronger theoretical foundation or to switch to a more advanced controller strategy.
