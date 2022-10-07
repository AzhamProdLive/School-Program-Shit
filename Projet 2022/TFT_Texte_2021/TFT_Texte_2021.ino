
#include <TFT.h>  // Arduino LCD library
#include <SPI.h>

// pin definition for the Uno
#define cs   10
#define dc   9
#define rst  8

// create an instance of the library
TFT TFTscreen = TFT(cs, dc, rst);


void setup() {

  // Put this line at the beginning of every sketch that uses the GLCD:
  TFTscreen.begin();

  // clear the screen with a black background
  TFTscreen.background(200, 0, 0);

  // set the font size
  TFTscreen.setTextSize(1);
}

void loop() {

  
  // set the font color
  TFTscreen.stroke(255, 255, 255);
  TFTscreen.text("vive les sti2d 2020...", 10, 100);
 

}
