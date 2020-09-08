# Using an IOT GUI to Control a UGV Robot Using Arduino and Rasberry Pi

There are two boards involved in this project. The first one was a Rasberry Pi 3 board that was used to interfere directly with the UGV robot and the AUTUGV4.c file was runned within the Rasberry Pi 3 board. Although the UGV robot has 4 wheels the interface and the control sequence are written in a way that it works like a joystick with the options forward, backward, turn right and left.

Additionally, an arduino board is needed that has the hardware needed for connecting to a local wifi network and in this case an ESP8266 board was used. The ESP board should be programmed to first of all connect to a local wifi network by using its username and password and then create a local server and wait for local clients to use the interface and refresh the interface page everytime a client action is made. The interface itself is a simple web gui written in HTML.

The communication between the boards are used by a dual way UART serial connection(2 wires). The basis of this communication from the interface to the Rasberry Pi 3 board is on sending certain strings based on actions and decoding them on the other end.
