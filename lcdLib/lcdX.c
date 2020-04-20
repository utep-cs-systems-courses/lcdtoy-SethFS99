/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_GRAY);

  // fillRectangle((screenWidth * 0.5) - 10,(screenHeight * 0.5) -10, 20, 20, COLOR_FIREBRICK);
  
  for(int i = 0; i < 1; i++){
    for(int y = 0; y < 16; y++){
      drawPixel(i, y, COLOR_RED);
    }
  }
  for(int i = 0; i < 16; i++){
    drawPixel(i, 15, COLOR_BLACK);
  }
  for(int x = 15; x > 0; x--){
    drawPixel(x,x, COLOR_GREEN);
  }
  
}
