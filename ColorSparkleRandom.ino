#include "Arduino.h"
#include <Adafruit_NeoPixel.h>


 
  //SPARKLER: a brush seeding random colours  NEEDS IMPROVEMENT

void colorSparkle(boolean fadeout, boolean fadein, int brushSpeed){
  
  for(loopcounter = 0; loopcounter<duration; loopcounter++) 
  {

    HSV brushcolor;
 
    if (initialized == false)
    {
      initialized = true;
      pixelbrush.setSpeed(brushSpeed);
      pixelbrush.setFadeout(fadeout); //sparkles fade in (true)
      pixelbrush.setFadein(fadein);  //and fade out immediately after reaching the set brightness (True)
    }

    //set a new brush color in each loop
    brushcolor.h = random(255); //random color
    brushcolor.s = (255); //random but low saturation, giving white-ish sparkles
    brushcolor.v = random(150); //random (peak) brighness

    
      if (rand() % 10) //slowly (and randomly) change hue of brushes
      {
        brushcolor = pixelbrush.getColor();
        brushcolor.h += random(3) - 1; //randomly change hue a little ( ± random(1))
        pixelbrush.setColor(brushcolor);


      }

    pixelbrush.setColor(brushcolor);
    pixelbrush.setFadeSpeed(random(100) + 150); //set a new fadespeed with some randomness

    neopixels.clear();
      pixelbrush.moveTo(random(NUMBEROFPIXELS));  // < USER ADDED LINE
    pixelbrush.paint(); //paint the brush to the canvas (and update the brush, i.e. move it a little)
    pixelcanvas.transfer(); //transfer (add) the canvas to the neopixels

    neopixels.show();
  }

}
