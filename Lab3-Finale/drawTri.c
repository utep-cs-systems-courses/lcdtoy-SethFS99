/** \Draws a right triangle
 *  \
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

/** */
int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLACK);
  int XOFFSET = 50;
  int YOFFSET = 100;
  int h = 21;
  
  // fillRectangle((screenWidth * 0.5) - 10,(screenHeight * 0.5) -10, 20, 20, COLOR_FIREBRICK);
  
  for(int i = 0; i < 41; i++){//triangle
    drawPixel(i, 20, COLOR_RED);
    if( i < 21){
      drawPixel(0,i, COLOR_BLUE);
    }
    drawPixel(i, i/2, COLOR_GREEN);
  }


  for(int x = 0; x < 2*h; x++){//upside down triangle
    //if statement switches how it's being drawn
    if( x >= h){
      drawPixel(x+XOFFSET, YOFFSET/2,COLOR_MAGENTA);//straight line
      drawPixel(x+XOFFSET, (h+YOFFSET/2)-x+h, COLOR_GREEN);//pushes line down amount and pulls up by x-h amount
    }else{
      drawPixel((x + XOFFSET), (x + YOFFSET/2), COLOR_RED);//pushes line down by x amount
      drawPixel((x+XOFFSET),YOFFSET/2, COLOR_BLUE);//straight line
    }
  }


  for(int x = 0; x<2*h; x++){//draws a triangle, only possible in one loop because equal side lengths
    if(x >= h){
      drawPixel(x+XOFFSET, YOFFSET, COLOR_MAGENTA);//straight line
      drawPixel(x+XOFFSET, (YOFFSET-h)+(x-h), COLOR_GREEN);//x moves it right, y is pulled up by h amount and down by x-h amount, this is to have more control of how far down it goes
    }else{
      drawPixel(x+XOFFSET, YOFFSET, COLOR_BLUE);//straight line
      drawPixel(x+XOFFSET, YOFFSET - x, COLOR_RED);//pulls up x amount
    }
  }




  
}
