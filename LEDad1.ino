
// This is for Arduino Program LED
#include <FastLED.h> //LED library initialization
int a,b,c,d,e,f,g,h,j=0; //Variables to store Sensor data

#define NUM_LEDS 90 // How many leds in your strip?
#define DATA_PIN 3 // Data pin of LED will be connected here on arduino

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
  pinMode(4,INPUT); //Digital Input Pin for IR sensor
  pinMode(5,INPUT); //Digital Input Pin for IR sensor
  pinMode(6,INPUT); //Digital Input Pin for IR sensor
  pinMode(7,INPUT); //Digital Input Pin for IR sensor
  pinMode(8,INPUT); //Digital Input Pin for IR sensor
  pinMode(9,INPUT); //Digital Input Pin for IR sensor
  pinMode(10,INPUT);//Digital Input Pin for IR sensor
  pinMode(11,INPUT);//Digital Input Pin for IR sensor
  
  LEDS.addLeds<WS2812,DATA_PIN,RGB>(leds,NUM_LEDS); //LED initialization
  LEDS.setBrightness(84); // Brightness of LED (0-255 range)
}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); } } //Function for Fading Effect

void loop() { 
  a=digitalRead(4); //Read input from sensor A
  b=digitalRead(5); //Read input from sensor B
  c=digitalRead(6); //Read input from sensor C
  d=digitalRead(7); //Read input from sensor D
  e=digitalRead(8); //Read input from sensor E
  f=digitalRead(9); //Read input from sensor F
  g=digitalRead(10);//Read input from sensor G
  h=digitalRead(11);//Read input from sensor H
  
  static uint8_t hue = 0; // Variable 8 bit
 
  // First slide the led in one direction
  if(a==1)
  {
    if(b==1)
    {
  for(int i = 4; i < 55; i++) {
    // Set the i'th led to red 
    leds[i] = CHSV(hue++, 255, 255);
    // Show the leds
    FastLED.show(); 
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall();
    // Wait a little bit before we loop around and do it again
    delay(10);
                              }
    }
  }

  if(g==1)
{
  if(f==1)
  {
  // Now go in the other direction.  
  for(int i = (56)-1; i >= 4; i--) {
    // Set the i'th led to red 
    leds[i] = CHSV(hue++, 255, 255);
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall();
    // Wait a little bit before we loop around and do it again
    delay(10);
                                   }
  }
}
          }
