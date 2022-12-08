 #include "Arduino.h"
#include <Adafruit_NeoPixel.h>


 
 //---------------------
  //TWINKLY STARS          Alright rubbish on long strip
  //---------------------
  //brush set to random positions and painting a fading star

 void fadingBackground(int red, int green, int blue, int duration3){
  
  for(loopcounter = 0; loopcounter<duration3; loopcounter++) 
  {

    HSV brushcolor;


    if (initialized == false)
    {
      initialized = true;
      pixelbrush.setSpeed(2000); //do not move automatically
      pixelbrush.setFadein(true); //fade in 
      pixelbrush.setFadeout(true); //and fade out 
    }


    
    if (rand() % 100 == 0) //at a random interval, move the brush to paint a new pixel (brush only paints a new pixel once)
    {
      brushcolor.h = rand ();       //   rand(); MODDED LINE
      brushcolor.s = random(200); //set low saturation, almost white
      brushcolor.v = random(100) + 20; //set random brightness
      pixelbrush.setColor(brushcolor);
      pixelbrush.moveTo(random(NUMBEROFPIXELS)); //move the brush to a new, random pixel
      pixelbrush.setFadeSpeed(random(200) + 5); //set random fade speed, minimum of 5
      pixelbrush.setBounce(true);
    }

    //add a background color by setting all pixels to a color (instead of clearing all pixels):
    int i;
    for (i = 0; i < NUMBEROFPIXELS; i++)
    {
      neopixels.setPixelColor(i, red, green, blue); //color in RGB: green  
    }


    pixelbrush.paint(); //paint the brush to the canvas 
    pixelcanvas.transfer(); //transfer (add) the canvas to the neopixels

    neopixels.show();
  }


  initialized = false; //reset the variable before moving to the next loop

 }
