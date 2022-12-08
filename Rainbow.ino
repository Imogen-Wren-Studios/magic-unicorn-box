void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<neopixels.numPixels(); i++) {
      neopixels.setPixelColor(i, Wheel((i+j) & 255));
    }
    neopixels.show();
    delay(wait);
  }
}


// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return neopixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return neopixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return neopixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}


// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< neopixels.numPixels(); i++) {
      neopixels.setPixelColor(i, Wheel(((i * 256 / neopixels.numPixels()) + j) & 255));
    }
    neopixels.show();
    delay(wait);
  }
}



//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < neopixels.numPixels(); i=i+2) {
        neopixels.setPixelColor((i+q), Wheel((( i+j)*5) % 255));    //turn every third pixel on
      }
      neopixels.show();

      delay(wait);

      for (uint16_t i=0; i < neopixels.numPixels(); i=i+2) {
        neopixels.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}
