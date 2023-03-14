#**propellor-clock**
General description
Put seven LEDs on a stick and rotate them at 600 rpm, use a small microcontroller to keep the time and blink the LEDs in an appropriate pattern to show the numbers and you have a propeller clock! As your eye cannot follow the flash rate of the LEDs, it looks like the digital numbers are floating in thin air! Main features of my clock are:

Easy-to build isolated power supply with a transformer built with 40mm & 50mm PVC pipe. Basic PIC 16F84 flash microcontroller Hall sensor with permanent magnet as index sensor Time set possible when the clock is rotating (using a second Hall sensor with an electromagnet from a relay) Standard PC power supply FAN used as motor to get the clock rotating. The first idea to create a clock like this is from Bob Blick, you can find more designs on the internet, just use a search engine and look for "propeller clock".

#**Mechanics**
To get the propeller clock going I used a 230Vac fan (as used in PC power supplies) because it is easy to get and it has a nice large rotating motor house to build on. I tuned down the speed to an acceptable low level of about 600 rpm by using series capacitors (about 1µF). The PIC is fast enough for higher speed, but the noise becomes unacceptably high at higher speeds!

The main problem with this propeller clock is how to get the power to the rotating printed circuit board. This problem is solved by building an air-core (!) transformer with static primary and rotating secondary winding. The air core transformer is driven by a high frequency SMPS which will be described later on.

In the drawing below you see how the rotating PCB is connected to the FAN motor: -The Copper windings are coiled on the 40 mm secondary PVC pipe and fixed with laquer or glue -The primary is built in the same way usinng a slightly shorter 50mm PVC pipe. -The base plate has a hole with the same ddiameter as the static PVC pipe inner diameter -The secondary coil is glued to the fan mootor house (be sure that it is centered well!) -The primary is glued to the base plate wiith the hole -The base plate is screwed to the corner hholes of the fan house. -The rotating pcb is screwed to a small piiece of PCB which is glued on top of the rotating PVC pipe.

#**The isolated power supply**
The isolated power supply is an isolated flyback converter circuit running at 200kHz. For details on the isolated air transformer, see the section about the mechanics above. The 4047 builds a stable 200kHz oscillator which drives a small push pull MOSFET driver stage built with small signal transistors Q1 and Q2 (transistor type is not very critical here). The MOSFET should be a high voltage type which can handle the voltage spikes across the transformers primary. C4 limits the voltage spikes to an acceptable level (this capacitor can be tuned for optimal performance). C5 (1µF film cap) must be connected directly to the source of Q3 and the transformers primary.

On the (rotating) secondary side, four FAST (150ns) diodes rectify the AC voltage. C6 is a buffer elcap to handle pulse loads. A basic 7805 1Amp stabilizer IC creates a stable 5 V supply for the clock circuit.

The power supply can source up to 200mA at 5V. Note: the secondary voltage before the 5V stabilizer is not very stable, without any load it may rise up to 50 volts! Make sure that some load is placed here (1k resistor is sufficient). The losses in the converter are quite low, components do not get hot at all. C4 is very important here, if omitted, MOSFET Q3 will run hot because the voltage spikes on the primary even exceed the breakdown voltage of this FET!
