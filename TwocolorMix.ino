 //---------------------
  //TWO-BRUSH-COLORMIXING
  //---------------------

  void twoColormix(){

  //two brushes moving around randomly paint on their individual canvas, resulting in colors being mixed 
  while(true) //create a loop with two additional brushes (are deleted automatically once the loop finishes)
  {

    //create an additional canvas for the second brush (needs to be created before the brush)
    NeoPixelPainterCanvas pixelcanvas2 = NeoPixelPainterCanvas(&neopixels);

    //create additional brush, painting on the second canvas 
    NeoPixelPainterBrush pixelbrush2 = NeoPixelPainterBrush(&pixelcanvas2); 

    if (pixelcanvas2.isvalid() == false) Serial.println("canvas2 allocation problem");
    else  Serial.println("canvas2 allocation ok");

    if (pixelbrush2.isvalid() == false) Serial.println(F("brush2 allocation problem"));
    else  Serial.println(F("brush2 allocation ok"));


    for(loopcounter = 0; loopcounter<duration; loopcounter++) 
    {


      HSV brushcolor;
      static bool firstrun = true;

      brushcolor.s = 255; //full color saturation
      brushcolor.v = 150; //medium-low brightness

      if (initialized == false) //initialize the brushes
      {
        initialized = true;

        brushcolor.h = random(255);

        //setup the first brush
        pixelbrush.setSpeed(-900);
        pixelbrush.setSpeedlimit(2000);
        pixelbrush.setFadeSpeed(random(5) + 50);
        pixelbrush.setFadeout(true);
        pixelbrush.setFadein(true);
        pixelbrush.setColor(brushcolor);
        pixelbrush.moveTo(random(NUMBEROFPIXELS));
        pixelbrush.setBounce(true);

        //setup the second brush
        brushcolor.h = random(255);
        pixelbrush2.setSpeed(1100);
        pixelbrush2.setSpeedlimit(2000);
        pixelbrush2.setFadeSpeed(random(5) + 50);
        pixelbrush2.setFadeout(true);
        pixelbrush2.setFadein(true);
        pixelbrush2.setColor(brushcolor);
        pixelbrush2.moveTo(random(NUMBEROFPIXELS));
        pixelbrush2.setBounce(true);
      }


      if (rand() % 10) //slowly (and randomly) change hue of brushes
      {
        brushcolor = pixelbrush.getColor();
        brushcolor.h += random(3) - 1; //randomly change hue a little ( ± random(1))
        pixelbrush.setColor(brushcolor);

        brushcolor = pixelbrush2.getColor();
        brushcolor.h += random(3) - 1; //randomly change hue a little ( ± random(1))
        pixelbrush2.setColor(brushcolor);

      }

      //slowly change speed of both brushes
      pixelbrush.setSpeed(pixelbrush.getSpeed() + random(6) - 3); //means speed = currentspeed ± random(3)
      pixelbrush2.setSpeed(pixelbrush2.getSpeed() + random(6) - 3); //means speed = currentspeed ± random(3)


      neopixels.clear(); //remove any previously applied paint

      pixelbrush.paint(); //apply the paint of the first brush to its assigned canvas (and update the brush)
      pixelbrush2.paint(); //apply the paint of the second brush to  its assigned canvas (and update the brush)

      pixelcanvas.transfer(); //transfer the first canvas to the neopixels
      pixelcanvas2.transfer(); //transfer the sedonc canvas to the neopixels (adding colors, rather than overwriting colors)

      neopixels.show();
    }
    break; //quit the while loop immediately (and delete the created brush)
  }

  }
