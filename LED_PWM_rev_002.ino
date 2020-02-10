// Two LEDs and one button

const int keyPin = 12; // the number for button
const int ledPin1 = 9; // The red LED
const int ledPin2 = 3; // the green LED
int period, startTime; // This creates a variable integear called ' period'
bool isOn = false; // The 'bool' data types uses two values: True or Fasle for the button
byte brightness = 0; //The 'byte' keeps a 8 bit unsigned number. Choose from 0 to 255.
byte brightnessChange = 1; // See comment on top

void setup() { 
  // put your setup code here, to run once:
  pinMode(keyPin,INPUT);//initialize the key pin as input 
  pinMode(ledPin1,OUTPUT);//initialize the led pin as output
  pinMode(ledPin2,OUTPUT);//initialize the led pin as output
  Serial.begin(9600);// This opens serial port for coming data
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(keyPin) == LOW) {
    digitalWrite(ledPin1, LOW);//turn on the led
    delay(250);// Useful for pausing the program
    digitalWrite(ledPin1,HIGH);//turn off the led EDIT
    delay(250); // Good for resetting the red LED

  }
  else {
    // When the button is pressed
    digitalWrite(ledPin1, LOW);
    Serial.print("Begin: ");
    Serial.println(millis());
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
      if(digitalRead(keyPin) == LOW) {
        digitalWrite(ledPin2, LOW);
        break; // Good for looping by bypassing the normal loop condition
      }
      // sets the value (range from 0 to 255):
      analogWrite(ledPin2, fadeValue); // Sample from Fading to fade with LED
      // wait for 30 milliseconds to see the dimming effect 
      delay(30);
    }
  
    // fade out from max to min in increments of 5 points:
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
      if(digitalRead(keyPin) == LOW) {
        digitalWrite(ledPin2, LOW);
        break;
      }
      // sets the value (range from 0 to 255):
      analogWrite(ledPin2, fadeValue);
      // wait for 30 milliseconds to see the dimming effect
      delay(30);
    }

    Serial.print("End: ");
    Serial.println(millis());
    Serial.println("");
  } 
}
