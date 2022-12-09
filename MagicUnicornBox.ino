-#include <NeoPixelPainter.h>





const int duration = 3000; //number of loops to run each animation for

#define NUMBEROFPIXELS 64 //Number of LEDs on the strip
#define PIXELPIN 2 //Pin where WS281X pixels are connected

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>
#include <NeoPixelPainter.h>



Adafruit_NeoPixel neopixels = Adafruit_NeoPixel(NUMBEROFPIXELS, PIXELPIN, NEO_GRB + NEO_KHZ800);

NeoPixelPainterCanvas pixelcanvas = NeoPixelPainterCanvas(&neopixels); //create canvas, linked to the neopixels (must be created before the brush)
NeoPixelPainterBrush pixelbrush = NeoPixelPainterBrush(&pixelcanvas); //crete brush, linked to the canvas to paint to


void setup() {
  randomSeed(analogRead(0)); //new random seed 
  pinMode(PIXELPIN, OUTPUT);

  neopixels.begin();

  Serial.begin(115200);
  Serial.println(" ");
  Serial.println("NeoPixel Painter Demo");

  //check if ram allocation of brushes and canvases was successful (painting will not work if unsuccessful, program should still run though)
  //this check is optional but helps to check if something does not work, especially on low ram chips like the Arduino Uno
  if (pixelcanvas.isvalid() == false) Serial.println("canvas allocation problem");
  else  Serial.println("canvas allocation ok");


  if (pixelbrush.isvalid() == false) Serial.println("brush allocation problem");
  else  Serial.println("brush allocation ok");

}

unsigned long loopcounter; //count the loops, switch to next animation after a while
bool initialized = false; //initialize the canvas & brushes in each loop when zero

int brightness = 255;  // scaling factor for brightness






void loop() {

  // Brazil                          //slow down
  ChaseThree(85, 40, 140,
    0, 0, 0,
     700, 300, 500,
     140, 60, 6, 
     true);      
  //  brush1, brush2, brush3,
 //  brush2sat, brush2bright, brush3sat,
 //  brushSpeed1, brushSpeed2, brushSpeed3,
 //  fade1, fade2, fade3, 
 //  boolean bounce)




// Ambient colour change mood lighting

NyanCat(1000, 100, false, false, 5);    //brushspeed, fadespeed, bounce, fade 
                               // Larger numbers faster
                               
 


   // Orange & Blue  Slow   Theatre Lighting                                    
  ChaseTwo(140, 25, 150, 250, true);      //brush1, brush2, brushSpeed1, brushSpeed2
                                          // bounce
/*  COLOURS:
 *  0 = red
 *  10-15 = Orange
 *  20= Almost Daylight
 *  32= Pikachu Yellow
 *  40 = yellow
 *  60 greenish yellow
 *  70= yellowish green
 *  85 = Green
 *  90 Blueish green
 *  100= teal
 *  130 = sky blue
 *  150 = blue
 *  175 = Dark blue
 *  200 = purple
 *  225 = pink
 *  255 = red 
 */  


 
   // pure Unicorn Splooge    make slower
   NyanCat(1200, 325, true, true, 1);    //brushspeed, fadespeed, bounce, fade, 
                                       // hueFade - between 1 - 6,
                                       // smaller numbe r= faster colour change
 
// Rasta Flag  red yellow green    slow this down more
   ChaseThree(255, 25, 85,
       255,  150, 255,
       600, 300, 400,
       1500, 1, 1, 
       true);      
 //  brush1, brush2, brush3,
 //  brush2sat, brush2bright, brush3sat,
 //  brushSpeed1, brushSpeed2, brushSpeed3,
 //  fade1, fade2, fade3, 
 //  boolean bounce)


 // theatre chase rainbow        move to later?
 
    theaterChaseRainbow(100);
 


//TEAM AMERICA, or Russia, or France, or Union Flag      slow this down
 ChaseThree(255, 150, 85,
       255, 150, 0,
     700, 300, 400,
     1000, 60, 6, 
     true);      
 //  brush1, brush2, brush3,
 //  brush2sat, brush2bright, brush3sat,
 //  brushSpeed1, brushSpeed2, brushSpeed3,
 //  fade1, fade2, fade3, 
 //  boolean bounce)
 


// Brazil                          //slow down
  ChaseThree(85, 40, 140,
    255, 150, 255,
     700, 300, 500,
     140, 60, 6, 
     true);      
  //  brush1, brush2, brush3,
 //  brush2sat, brush2bright, brush3sat,
 //  brushSpeed1, brushSpeed2, brushSpeed3,
 //  fade1, fade2, fade3, 
 //  boolean bounce)
 

/*
 // German Sausage
  ChaseThree(255, 30, 32, 0, 255,
     500, 750, 600,
     140, 60, 6, 
     true);      
  //  brush1, brush2, brush3,
 //  brush2sat, brush2bright, brush3sat,
 //  brushSpeed1, brushSpeed2, brushSpeed3,
 //  fade1, fade2, fade3, 
 //  boolean bounce)

 */


 
   
   //  Fast Unicorn Jizz        can expand      again make slower
   hueFade(4000, 4000, 4000, 4000);                       // moveSpeed1, moveSpeed2, fadeSpeed11, fadeSpeed22)
                                     // 4000, 8000, 4000, 6000



/*
// purple green blue  fast
gravityBalls(100, 17, 70,         // brush1, brush2, brush 3
true, true, true,
3000);    
// boolean bounce1, bounce2, bounce3
 //duration2 500-300  




// SPEEDING UP RUSH DOWN
 int loopNumber = 7; 
 unsigned long loopcounter2;

//green purple blue   fast unidirectional  repeat loop several times 

  for(loopcounter2 = 0; loopcounter2<loopNumber; loopcounter2++) 
    {
                                   
gravityBalls(100, 200, 70,     // brush1, brush2, brush 
false, false, false,
725);    
// boolean bounce1, bounce2, bounce3
//duration2 500-300
 }





//green purple blue bouncing
 gravityBalls(100, 200, 70,     // brush1, brush2, brush 
true, true, true,
3000);    
// boolean bounce1, bounce2, bounce3
//duration2 500-300

*/


 NyanCat(800, 10, true, true, 2);    //brushspeed, fadespeed, bounce, fade   // make this slower and change differently




colorSparkle(false, true, 100);   //boolean fadeout, boolean fadein    make colours less random?



//Solid Colour Changing and fading to white
 int loopNumber3 = 3; 
 unsigned long loopcounter3;

 for(loopcounter3 = 0; loopcounter3<loopNumber3; loopcounter3++) 
    {
 
// fading background Green & White
 fadingBackground(120, 255, 0, 1000);    // Red Green Blue duration 3 500-3000

// fading background Purple & White
 fadingBackground(200, 0, 255, 1000);    // Red Green Blue duration 3 500-3000

 // fading background Blue & White
 fadingBackground(0, 200, 255, 1000);    // Red Green Blue duration 3 500-3000

 // fading background Orange & White
 fadingBackground(255, 150, 0, 1500);    // Red Green Blue duration 3 500-3000

    }

   


// two brushes random colours mixing   not random enough can expand.
   twoColormix();     // needs improvement
   

     // Rainbow pulsing quickly
unsigned long loopcounter7;
int loopNumber7 = 8;

  for(loopcounter7 = 0; loopcounter7<loopNumber7; loopcounter7++) 
    {
  
  rainbow(10);  // delay    //slower

    }

   


// SPEEDING UP RUSH DOWN
int loopNumber8 = 6; 
int loopcounter8;

//Cyan & Yellow  fast unidirectional  repeat loop several times 

  for(loopcounter8 = 0; loopcounter8<loopNumber8; loopcounter8++) 
    {
                                   
gravityBalls(100, 100, 14,     // brush1, brush2, brush 
false, false, false,
725);    
// boolean bounce1, bounce2, bounce3
//duration2 500-300
 }


 

 

  // Orange & Blue Swipes
             //mini loop, total loop
  colorWipeOB(2, 4);


    rainbowCycle(10);



 
  // Flag Chase  slow    Cyan, Yellow, Magenta
   ChaseThree(110, 27, 235,
       255,  150, 255,
       500, 750, 600,
       140, 60, 6, 
       true);   
 //  brush1, brush2, brush3,
 //  brush2sat, brush2bright, brush3sat,
 //  brushSpeed1, brushSpeed2, brushSpeed3,
 //  fade1, fade2, fade3, 
 //  boolean bounce)


 // Rainbow pulsing gently


  for(loopcounter7 = 0; loopcounter7<loopNumber7; loopcounter7++) 
    {
  
  rainbow(20);  // delay

    }

 
  // Theater chasing lights green purple blue orange
 colorChase();
 


     
 

}                                   
