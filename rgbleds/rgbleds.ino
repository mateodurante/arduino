/*
  Reading a serial ASCII-encoded string.

 This sketch demonstrates the Serial parseInt() function.
 It looks for an ASCII string of comma-separated values.
 It parses them into ints, and uses those to fade an RGB LED.

 Circuit: Common-Cathode RGB LED wired like so:
 * Red anode: digital pin 3
 * Green anode: digital pin 5
 * Blue anode: digital pin 6
 * Cathode : GND

 created 13 Apr 2012
 by Tom Igoe
 
 modified 14 Mar 2016
 by Arturo Guadalupi

 This example code is in the public domain.
 */

// pins for the LEDs:
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

int red;
int green;
int blue;

int primera = 1;

char separatorR;
char separatorG;
char separatorB;
char separatorLine;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}

void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {
        separatorR = Serial.read();
        red = Serial.parseInt();
        separatorG = Serial.read();
        green = Serial.parseInt();
        separatorB = Serial.read();
        blue = Serial.parseInt();
        separatorLine = Serial.read();
    
        
          Serial.print(separatorR);
          Serial.print(separatorG);
          Serial.println(separatorB);
    
        if (separatorR == 'r' && separatorG == 'g' && separatorB == 'b' ) {
    
          // constrain the values to 0 - 255 and invert
          // if you're using a common-cathode LED, just use "constrain(color, 0, 255);"
          red = constrain(red, 0, 255);
          green = constrain(green, 0, 255);
          blue = constrain(blue, 0, 255);
    
          // fade the red, green, and blue legs of the LED:
          analogWrite(redPin, red);
          analogWrite(greenPin, green);
          analogWrite(bluePin, blue);
    
          // print the three numbers in one string as hexadecimal:
          Serial.print(red, HEX);
          Serial.print(green, HEX);
          Serial.println(blue, HEX);
        }
  }
}

