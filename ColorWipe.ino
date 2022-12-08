// Orange & Blue Swipes
 void colorWipeOB(int loopNumber4, int loopNumber5){

    
 unsigned long loopcounter4;

 unsigned long loopcounter5;

for(loopcounter5 = 0; loopcounter5<loopNumber5; loopcounter5++) 
    { 

 for(loopcounter4 = 0; loopcounter4<loopNumber4; loopcounter4++) 
    {
                           // R  G  B     speed 
  colorWipe(neopixels.Color(255, 135, 15), 5); // orange larger number slower
  colorWipe(neopixels.Color(255, 110, 0), 50); // Orange
   colorWipe(neopixels.Color(255, 135, 15), 10); // Orange
   colorWipe(neopixels.Color(255, 110, 0), 50); // Orange

    }  
   
   for(loopcounter4 = 0; loopcounter4<loopNumber4; loopcounter4++) 
    {
   
  colorWipe(neopixels.Color(0, 0, 255), 5); // Blue
  colorWipe(neopixels.Color(0, 255, 255), 50); // Blue
  colorWipe(neopixels.Color(0, 0, 255), 10); // Blue
  colorWipe(neopixels.Color(0, 255, 255), 50); // Blue
    }

    }

    
    }


    void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<neopixels.numPixels(); i++) {
    neopixels.setPixelColor(i, c);
    
    neopixels.show();
    delay(wait);
  }
}
