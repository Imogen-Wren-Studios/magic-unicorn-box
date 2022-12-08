#include "Arduino.h"
#include <Adafruit_NeoPixel.h>




  //-------------
  //CHASER       good
  //-------------

  // two brushes chasing each other, one painting the pixel in a color, the other one painting 'black' (acting on the same canvas)
  
void ChaseTwo(int brush1, int brush2, int brushSpeed1, int brushSpeed2, boolean bounce){
  
  while(true) //create a loop with an additional brush (is deleted automatically once the loop finishes)
  {

    //create an additional brush, painting on the same canvas as the globally defined brush
    NeoPixelPainterBrush pixelbrush2 = NeoPixelPainterBrush(&pixelcanvas); 

    if (pixelbrush2.isvalid() == false) Serial.println(F("brush2 allocation problem"));
    else  Serial.println(F("brush2 allocation ok"));


    for(loopcounter = 0; loopcounter<duration; loopcounter++) 
    {


      if (initialized == false)
      {
        HSV brushcolor;

        initialized = true;

        brushcolor.h = (brush1); //choose random color once Purple = 200
        brushcolor.s = 255; //full staturation
        brushcolor.v = 200; // Brightness

        //initialize the first brush to move and paint a color, no fading 
        pixelbrush.setSpeed(brushSpeed1); //moving speed
        pixelbrush.setColor(brushcolor);
        pixelbrush.setFadeout(false); //deactivate fade-out (was activated in last animation)
        pixelbrush.setFadein(false); //deactivate fade-in 
          pixelbrush.setBounce(bounce); // BUG FIX
        pixelbrush2.moveTo(0); //move the brush to pixel 0
        //initialize the second brush to move at the same speed but starting at a different position (default position is 0)
        brushcolor.v = 50; //zero intensity = black
        brushcolor.h = (brush2); //choose random color once  < USER ADDED LINE 70 = green
        
        pixelbrush2.setSpeed(brushSpeed2);
        pixelbrush2.setColor(brushcolor);
        pixelbrush2.moveTo(2*NUMBEROFPIXELS/3); //move the brush 
       

      }

      neopixels.clear();

      pixelbrush.paint(); //apply the paint of the first brush to the canvas (and update the brush)
      pixelbrush2.paint(); //apply the paint of the second brush to the canvas (and update the brush)
      pixelcanvas.transfer(); //transfer the canvas to the neopixels

      neopixels.show();
    }
    break; //quit the while loop immediately (and delete the created brush)
  }


  initialized = false;

}
