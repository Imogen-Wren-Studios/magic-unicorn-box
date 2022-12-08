//-------------
  //BOUNCY BALLS   blue green purple Meh
  //-------------
  //three brushes painting on one canvas, attracted to the zero pixel as if by gravity


void gravityBalls(int brush1, int brush2, int brush3,
boolean bounce1, boolean bounce2, boolean bounce3, int duration2){

  while(true) //create a loop with two additional brushes (are deleted automatically once the loop finishes)
  {

    //create additional brushes, painting on the same canvas as the globally defined brush
    NeoPixelPainterBrush pixelbrush2 = NeoPixelPainterBrush(&pixelcanvas); 
    NeoPixelPainterBrush pixelbrush3 = NeoPixelPainterBrush(&pixelcanvas); 

  

    if (pixelbrush2.isvalid() == false) Serial.println(F("brush2 allocation problem"));
    else  Serial.println(F("brush2 allocation ok"));

    if (pixelbrush3.isvalid() == false) Serial.println(F("brush3 allocation problem"));
    else  Serial.println(F("brush3 allocation ok"));

    byte skipper = 0;

    for(loopcounter = 0; loopcounter<duration2; loopcounter++) 
    {


      if (initialized == false) //initialize the brushes
      {
        initialized = true;

        HSV brushcolor;

        brushcolor.h = brush1; //blue
        brushcolor.s = 255; //almost full saturation
        brushcolor.v = 150; //medium brightness

        //first brush
        pixelbrush.setSpeed(300); //zero initial speed
        pixelbrush.setFadeSpeed(150);
        pixelbrush.setFadeout(true);
        pixelbrush.setColor(brushcolor);
        pixelbrush.moveTo(NUMBEROFPIXELS - 6 ); //move to end of the strip
        pixelbrush.setBounce(bounce1); //bounce if either end of the strip is reached

        //second brush
        brushcolor.h = brush2; //orange
        pixelbrush2.setSpeed(100); //zero initial speed
        pixelbrush2.setFadeSpeed(50);
        pixelbrush2.setFadeout(true);
        pixelbrush2.setColor(brushcolor);
        pixelbrush2.moveTo(NUMBEROFPIXELS / 1); //move to one third of the strip
        pixelbrush2.setBounce(bounce2);

        brushcolor.h = brush3; //green-ish (pure green is 85 or 255/3)
        pixelbrush3.setSpeed(200);
        pixelbrush3.setFadeSpeed(100);
        pixelbrush3.setFadeout(true);
        pixelbrush3.setColor(brushcolor);
        pixelbrush3.moveTo(2 * NUMBEROFPIXELS / 3);
        pixelbrush3.setBounce(bounce3);
      }

      //apply some gravity force that accelerates the painters (i.e. add speed in negative direction = towards zero pixel)
      //  if (skipper % 5 == 0) //only apply gravity at some interval to make it slower on fast processors
      //  {
      //read current speed of each brush and speed it up in negative direction (towards pixel zero)
      pixelbrush.setSpeed(pixelbrush.getSpeed() - 10); 
      pixelbrush2.setSpeed(pixelbrush2.getSpeed() - 10);
      pixelbrush3.setSpeed(pixelbrush3.getSpeed() - 10);
      //  }
      //  skipper++;


      neopixels.clear();

      pixelbrush.paint(); //apply the paint of the first brush to the canvas (and update the brush)
      pixelbrush2.paint(); //apply the paint of the second brush to the canvas (and update the brush)
      pixelbrush3.paint(); //apply the paint of the third brush to the canvas (and update the brush)
      pixelcanvas.transfer(); //transfer the canvas to the neopixels (and update i.e. fade pixels)

      neopixels.show();
    }
    break; //quit the while loop immediately (and delete the created brush)
  }


  initialized = false;

}
