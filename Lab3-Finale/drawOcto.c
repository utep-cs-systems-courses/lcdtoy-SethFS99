#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

void drawO(){
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLACK);//BG color
  int XOFFSET = 50;
  int YOFFSET = 75;
  int h = 25;

  for(int i = 0; i < h; i++){//draws octogon
    drawPixel(i+XOFFSET, YOFFSET-h, COLOR_RED);//top line
    drawPixel(i+XOFFSET, h+YOFFSET+h, COLOR_BLUE);//bottom
    drawPixel(XOFFSET-h, i+YOFFSET, COLOR_GREEN);//left
    drawPixel(XOFFSET+h+h, i+YOFFSET, COLOR_MAGENTA);//right
    if(i == 0){//left side angles
      for(int k = 0; k < h; k++){
	drawPixel(k+XOFFSET-h, k+YOFFSET+h, COLOR_FIREBRICK);//Bottom Left diag
	drawPixel((XOFFSET-k), k+YOFFSET-h, COLOR_WHITE);//Top Left diag
	drawPixel(k+XOFFSET+h, k+YOFFSET-h, COLOR_FIREBRICK);//Top Right diag
	drawPixel(XOFFSET-k+h+h, k+YOFFSET+h, COLOR_WHITE);//Bottom Right diag
      }
    }
  }
}
