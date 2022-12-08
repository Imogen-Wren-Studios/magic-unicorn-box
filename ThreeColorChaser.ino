#include "Arduino.h"
#include <Adafruit_NeoPixel.h>



//------------------------------
  //SPEEDTRAILS FLAGS 
  //------------------------------
  //three brushes painting on one canvas, all following each other at the same speed, painting fading pixels


void ChaseThree(int brush1, int brush2, int brush3,
int brush2sat, int brush2bright, int brush3sat,
int brushSpeed1, int brushSpeed2, int brushSpeed3, int fade1, int fade2, int fade3, boolean bounce){

  
  while(true) //create a loop with two additional brushes (are deleted automatically once the loop finishes)
  {
    int brushspeed = 500;

    //create additional brushes, painting on the same canvas as the globally defined brush
    NeoPixelPainterBrush pixelbrush2 = NeoPixelPainterBrush(&pixelcanvas); 
    NeoPixelPainterBrush pixelbrush3 = NeoPixelPainterBrush(&pixelcanvas); 

    if (pixelbrush2.isvalid() == false) Serial.println(F("brush2 allocation problem"));
    else  Serial.println(F("brush2 allocation ok"));

    if (pixelbrush3.isvalid() == false) Serial.println(F("brush3 allocation problem"));
    else  Serial.println(F("brush3 allocation ok"));

    for(loopcounter = 0; loopcounter<duration; loopcounter++) 
    {

      HSV brushcolor;


      if (initialized == false) //initialize the brushes
      {
        initialized = true;
        brushcolor.h = brush1;      //colour
        brushcolor.s = 255; // Saturation
        brushcolor.v = 150; //medium brightness
        pixelbrush.setColor(brushcolor);
        pixelbrush.setSpeed(brushSpeed1);       //was set to 1000
        pixelbrush.setFadeSpeed(fade1); //fast fading (255 is max.)
        pixelbrush.setFadeHueNear(false); //deactivate hue fading, was activated in last animation
         pixelbrush.setFadeHueFar(false); //fade using the far path on the colorcircle < BUG FIX
        pixelbrush.setFadeout(true);
        pixelbrush.moveTo(0); //move brush to zero
        
        //second brush
        brushcolor.h = brush2;    //yelllow     yellow 25
        brushcolor.s = brush2sat;
        brushcolor.v = brush2bright;  // brush 2 brightness
        pixelbrush2.setSpeed(brushSpeed2);        // was set to 1500
        pixelbrush2.setFadeSpeed(fade2); 
        pixelbrush2.setFadeout(true);
        pixelbrush2.setColor(brushcolor);
        pixelbrush2.moveTo(NUMBEROFPIXELS / 13); //move it up one third of the strip
        
        //third brush
        brushcolor.h = brush3; // green
        brushcolor.s = brush3sat;
        brushcolor.v = 150;
        pixelbrush3.setSpeed(brushSpeed3);                 //was set to 1200
        pixelbrush3.setFadeSpeed(fade3);
        pixelbrush3.setFadeout(true);
        pixelbrush3.setColor(brushcolor);
        pixelbrush3.moveTo(2 * NUMBEROFPIXELS / 2); //move it up two thirds of the strip
      }

      neopixels.clear();

      pixelbrush.paint(); //apply the paint of the first brush to the canvas (and update the brush)
      pixelbrush2.paint(); //apply the paint of the second brush to the canvas (and update the brush)
      pixelbrush3.paint(); //apply the paint of the third brush to the canvas (and update the brush)
      pixelcanvas.transfer(); //transfer the canvas to the neopixels (and update i.e. fade pixels)
       pixelbrush2.setBounce(bounce); //bounce this brush at the end of the strip
       pixelbrush.setBounce(bounce); //bounce this brush at the end of the strip
        pixelbrush3.setBounce(bounce); //bounce this brush at the end of the strip
      neopixels.show();
    }
    break; //quit the while loop immediately (and delete the created brush)
  }


  initialized = false;

}
