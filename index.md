# E7012E-Mechatronics: Team Line Riders
This repository contains work done for the course E7012E - Mechatronics at LTU Spring 2019

## The Project
The task is to build an automated guided vehicle or AGV. The vehicle should be able to follow along a line track without deviating from the line and finish a track within a set time.

### The Team
![The team.](/E7012E-Mechatronics/docs/assets/Team 8 - Line Rider.JPG)
The team consists of [Jonathan Myrsell](https://www.linkedin.com/in/jonmyr/), [Ivar Rockström](https://www.linkedin.com/in/ivar/), [Julius Lundberg](https://www.linkedin.com/in/julius-lundberg/), [Anton Sundström](https://www.linkedin.com/in/anton-sundstr%C3%B6m-622431194/), [Zacharias Tyllström](https://www.linkedin.com/in/zacharias-tyllstrom/) and [Alejandro Salvador](https://www.linkedin.com/in/alejandro-salvador-cabo-9a6175156/). 

### The AGV
The tasks the team were set out to solve were to design and construct a
- [x] Line sensor using the ITR20001-T photo transistor
- [x] Hall sensor using the Hall Effect sensor SS441A, TO-92
- [x] Control a steering servo using PID
- [x] Control a DC motor using PID

### Line Sensor Array
The line sensor uses the ![ITR20001-T](https://cdn-shop.adafruit.com/product-files/3930/ITR20001-T.pdf) optical interrupter (OI) to sense a black line in the floor. This is done by emitting IR and recieving the bounching light in the OI. The amount of measured light indicates if there is a black surface under the OI. The team was able to construct a tuneable ADC and connect it to the microcontroller. This allowed for fast reading of the frequently updating OI.
