#include "Arduino.h"
#include <Adafruit_NeoPixel.h>



//---------------------
  //RAINBOW PAINT (aka nyan cat) Slow Colour Fade  Good   Hue changes slowly
  //---------------------

void NyanCat(int brushspeed, int fadespeed, boolean bounce,
boolean fade, int hueFade){   

  
  //the brush moves along the strip, leaving a colorful rainbow trail
  for(loopcounter = 0; loopcounter<duration; loopcounter++) 
  {
    static unsigned int hue = 0; //color hue to set to brush
    HSV brushcolor; //HSV color definition


    if (initialized == false) //initialize the brushes
    {
      initialized = true;
      //pixelbrush.setSpeed(1000); //brush moving speed 
      pixelbrush.setSpeed((brushspeed) + 10); //set a new fadespeed with some randomness
      //pixelbrush.setFadeSpeed(90);
      pixelbrush.setFadeSpeed((fadespeed) + 10); //set a new fadespeed with some randomness
      pixelbrush.setFadein(true); //brightness will fade-in if set to true
      pixelbrush.setFadeout(fade);
      pixelbrush.setBounce(bounce);
    }

    hue++;
    brushcolor.h = hue / hueFade; //divide by 3 to slow down color fading
    brushcolor.s = 255; //full saturation
    brushcolor.v = 200; //full brightness

    pixelbrush.setColor(brushcolor); //set new color to the bursh

    neopixels.clear();

    pixelbrush.paint(); //paint the brush to the canvas (and update the brush, i.e. move it a little)
    pixelcanvas.transfer(); //transfer (add) the canvas to the neopixels

    neopixels.show();
  }


 initialized = false; //reset the variable before moving to the next loop

}
