#include "main.h"
#include "memory.h"
#include "utils.h"
#include "draw.h"

int main()
{
  int i,slider3d;
  char* a = "Top screen";
  char* b = "Bottom screen";

  draw_fillrect(0,0,399,239,0,0,0, TOP_LEFT_FRAME1);
  draw_fillrect(0,0,399,239,0,0,0, TOP_RIGHT_FRAME1);
  draw_fillrect(0,0,319,239,0,0,0, BOTTOM_FRAME1);

  draw_string(a,8,40,255,255,255, TOP_LEFT_FRAME1);
  draw_string(a,8,40,255,255,255, TOP_RIGHT_FRAME1);
  draw_string(b,8,40,255,255,255, BOTTOM_FRAME1);
  draw_line(0,0,399,239,255,0,0, TOP_LEFT_FRAME1); 
  draw_line(0,0,399,239,255,0,0, TOP_RIGHT_FRAME1); 
  draw_rect(0,0,399,239,0,0,255, TOP_LEFT_FRAME1);   
  draw_rect(0,0,399,239,0,0,255, TOP_RIGHT_FRAME1);   
  draw_fillrect(100,100,200,200,0,255,0,TOP_LEFT_FRAME1);   
  draw_fillrect(100,100,200,200,0,255,0,TOP_RIGHT_FRAME1);   
  draw_fillrect(8,56,79,63,255,255,255, BOTTOM_FRAME1);
draw_fillcircle(200,200,25,255,255,255, TOP_LEFT_FRAME1);
draw_fillcircle(200,200,25,255,255,255, TOP_RIGHT_FRAME1);
draw_circle(200,200,25,255,0,0, BOTTOM_FRAME1);

return 0;
}

