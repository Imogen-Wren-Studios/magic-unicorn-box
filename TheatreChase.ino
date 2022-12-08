//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < neopixels.numPixels(); i=i+3) {
        neopixels.setPixelColor(i+q, c);    //turn every third pixel on
      }
      neopixels.show();

      delay(wait);

      for (uint16_t i=0; i < neopixels.numPixels(); i=i+3) {
        neopixels.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}




void colorChase(){

                            // R     G   B   SPEED
  theaterChase(neopixels.Color(127, 255, 0), 200); // Green
  theaterChase(neopixels.Color(50, 255, 0), 100); // green
  theaterChase(neopixels.Color(0, 255, 0), 255); // green    
   theaterChase(neopixels.Color(200, 255, 0), 100); // green
   
    theaterChase(neopixels.Color(255, 0, 255), 200); // Purple
  theaterChase(neopixels.Color(255, 0, 100), 100); // Purple
  theaterChase(neopixels.Color(255, 0, 255), 55); // Purple
   theaterChase(neopixels.Color(255, 0, 150), 10); // Purple

    
    theaterChase(neopixels.Color(0, 255, 255), 200); // blue
  theaterChase(neopixels.Color(0, 100, 255), 100); // blue
  theaterChase(neopixels.Color(0, 255, 255), 255); // blue
   theaterChase(neopixels.Color(0, 0, 255), 100); // blue

   
   theaterChase(neopixels.Color(255, 150, 0), 200); // Orange
  theaterChase(neopixels.Color(255, 100, 0), 100); //Orange
  theaterChase(neopixels.Color(255, 150, 0), 255); // orange
   theaterChase(neopixels.Color(255, 75, 0), 100); // potato

}
