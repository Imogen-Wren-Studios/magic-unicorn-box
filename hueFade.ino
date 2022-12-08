//------------------------------
  //HUE FADER: demo of hue fading  TYPE 2 FAST
  //------------------------------

  //hue fading can be done in two ways: change the color moving the shortest distance around the colorwheel (setFadeHueNear)
  //or intentionally moving around the colorwheel choosing the long way (setFadeHueFar)
  //two brushes move along the strip in different speeds, each painting a different color that the canvas will then fade to
  //a new color is set when the first brush passes pixel 0
  //both brushes act on the same canvas


  void hueFade(int moveSpeed1, int moveSpeed2, int fadeSpeed11, int fadeSpeed22){

  while(true) //create a loop with an additional brush (is deleted automatically once the loop finishes)
  {

    //create an additional brush, painting on the same canvas as the globally defined brush
    NeoPixelPainterBrush pixelbrush2 = NeoPixelPainterBrush(&pixelcanvas); 

    if (pixelbrush2.isvalid() == false) Serial.println(F("brush2 allocation problem"));
    else  Serial.println(F("brush2 allocation ok"));

     pixelcanvas.clear(); //clear the canvas

    for(loopcounter = 0; loopcounter<duration; loopcounter++) 
    {

      static unsigned int lastposition = 0; //to detect zero crossing only once (brush may stay at pixel zero for some time since it uses sub-pixel resolution movement)

      if (pixelbrush.getPosition() == 0 && lastposition > 0) initialized = false; //choose new color & speed if brush reaches pixel 0

      lastposition = pixelbrush.getPosition(); //save current position for next position check

      if (initialized == false)
      {
        initialized = true;

        HSV brushcolor;
   

        brushcolor.h = random(255); //random color
        brushcolor.s = 255; //full saturation
        brushcolor.v = 130; //medium brightness

        pixelbrush.setSpeed(random(moveSpeed1) + 150); //random movement speed 4000
        pixelbrush.setFadeSpeed(random(fadeSpeed11) + 20); //set random fading speed 8000
        pixelbrush.setColor(brushcolor); //update the color of the brush
        pixelbrush.setFadeHueNear(true); //fade using the near path on the colorcircle
        
        //second brush paints on the same canvas
        brushcolor.h = random(255);
        pixelbrush2.setSpeed(random(moveSpeed2) + 150);     // 4000
        pixelbrush2.setFadeSpeed(random(fadeSpeed22) + 20);         // 6000   
        pixelbrush2.setColor(brushcolor);
        //pixelbrush2.setFadeHueNear(true); //fade using the near path on the colorcircle
        pixelbrush.setFadeHueFar(true); //fade using the far path on the colorcircle (if both are set, this path is chosen)
        pixelbrush2.setBounce(true); //bounce this brush at the end of the strip
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
