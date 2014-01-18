#include "main.h"
#include "memory.h"
#include "HID.h"
#include "utils.h"
#include "draw.h"

int main()
{
  int i,slider3d,framebuffer,HID_new,HID_old;
  char buf[34];

  draw_fillrect(0,0,399,239,0,0,0, TOP_LEFT_FRAME0);
  draw_fillrect(0,0,399,239,0,0,0, TOP_RIGHT_FRAME0);
  draw_fillrect(0,0,399,239,0,0,0, TOP_LEFT_FRAME1);
  draw_fillrect(0,0,399,239,0,0,0, TOP_RIGHT_FRAME1);
  draw_fillrect(0,0,319,239,0,0,0, BOTTOM_FRAME0);
  draw_fillrect(0,0,319,239,0,0,0, BOTTOM_FRAME1);

  draw_string("Framebuffer 0",0,0,255,255,255, BOTTOM_FRAME0);
  draw_string("Framebuffer 1",0,0,255,255,255, BOTTOM_FRAME1);

  draw_line(0,0,399,239,255,0,0, TOP_LEFT_FRAME0); 
  draw_line(0,0,399,239,255,0,0, TOP_RIGHT_FRAME0); 
  draw_rect(0,0,399,239,0,0,255, TOP_LEFT_FRAME0);   
  draw_rect(0,0,399,239,0,0,255, TOP_RIGHT_FRAME0);   
  draw_fillrect(103,100,203,200,0,255,0,TOP_LEFT_FRAME0);   
  draw_fillrect(100,100,200,200,0,255,0,TOP_RIGHT_FRAME0);   

  draw_line(0,0,399,239,255,0,0, TOP_LEFT_FRAME1); 
  draw_line(0,0,399,239,255,0,0, TOP_RIGHT_FRAME1); 
  draw_rect(0,0,399,239,0,0,255, TOP_LEFT_FRAME1);   
  draw_rect(0,0,399,239,0,0,255, TOP_RIGHT_FRAME1);   
  draw_fillrect(103,100,203,200,0,255,0,TOP_LEFT_FRAME1);   
  draw_fillrect(100,100,200,200,0,255,0,TOP_RIGHT_FRAME1);   

  draw_fillcircle(205,200,25,255,255,255, TOP_LEFT_FRAME0);
  draw_fillcircle(200,200,25,255,255,255, TOP_RIGHT_FRAME0);

  draw_fillcircle(205,200,25,255,255,255, TOP_LEFT_FRAME1);
  draw_fillcircle(200,200,25,255,255,255, TOP_RIGHT_FRAME1);

  HID_old = 0;

  while (1){
    HID_new = read_word(HID);
    if(HID_new^HID_old){
      HID_old=HID_new;
      if (HID_new & BUTTON_A){
        draw_fillcircle(300,120,6,0,0,0, BOTTOM_FRAME0);
        draw_circle(300,120,6,0,0,255, BOTTOM_FRAME0);
        draw_string("A",296,116,0,0,255, BOTTOM_FRAME0);
        draw_fillcircle(300,120,6,0,0,0, BOTTOM_FRAME1);
        draw_circle(300,120,6,0,0,255, BOTTOM_FRAME1);
        draw_string("A",296,116,0,0,255, BOTTOM_FRAME1);
      } else {
        draw_fillcircle(300,120,6,0,0,255, BOTTOM_FRAME0);
        draw_string("A",296,116,0,0,0, BOTTOM_FRAME0);
        draw_fillcircle(300,120,6,0,0,255, BOTTOM_FRAME1);
        draw_string("A",296,116,0,0,0, BOTTOM_FRAME1);
      }
      if (HID_new & BUTTON_X){
        draw_fillcircle(288,108,6,0,0,0, BOTTOM_FRAME0);
        draw_circle(288,108,6,0,0,255, BOTTOM_FRAME0);
        draw_string("X",284,104,0,0,255, BOTTOM_FRAME0);
        draw_fillcircle(288,108,6,0,0,0, BOTTOM_FRAME1);
        draw_circle(288,108,6,0,0,255, BOTTOM_FRAME1);
        draw_string("X",284,104,0,0,255, BOTTOM_FRAME1);
      } else {
        draw_fillcircle(288,108,6,0,0,255, BOTTOM_FRAME0);
        draw_string("X",284,104,0,0,0, BOTTOM_FRAME0);
        draw_fillcircle(288,108,6,0,0,255, BOTTOM_FRAME1);
        draw_string("X",284,104,0,0,0, BOTTOM_FRAME1);
      }
      if (HID_new & BUTTON_Y){
        draw_fillcircle(276,120,6,0,0,0, BOTTOM_FRAME0);
        draw_circle(276,120,6,0,0,255, BOTTOM_FRAME0);
        draw_string("Y",272,116,0,0,255, BOTTOM_FRAME0);
        draw_fillcircle(276,120,6,0,0,0, BOTTOM_FRAME1);
        draw_circle(276,120,6,0,0,255, BOTTOM_FRAME1);
        draw_string("Y",272,116,0,0,255, BOTTOM_FRAME1);
      } else {
        draw_fillcircle(276,120,5,0,0,255, BOTTOM_FRAME0);
        draw_string("Y",272,116,0,0,0, BOTTOM_FRAME0);
        draw_fillcircle(276,120,5,0,0,255, BOTTOM_FRAME1);
        draw_string("Y",272,116,0,0,0, BOTTOM_FRAME1);
      }
      if (HID_new & BUTTON_B){
        draw_fillcircle(288,132,6,0,0,0, BOTTOM_FRAME0);
        draw_circle(288,132,6,0,0,255, BOTTOM_FRAME0);
        draw_string("B",284,128,0,0,255, BOTTOM_FRAME0);
        draw_fillcircle(288,132,6,0,0,0, BOTTOM_FRAME1);
        draw_circle(288,132,6,0,0,255, BOTTOM_FRAME1);
        draw_string("B",284,128,0,0,255, BOTTOM_FRAME1);
      } else {
        draw_fillcircle(288,132,6,0,0,255, BOTTOM_FRAME0);
        draw_string("B",284,128,0,0,0, BOTTOM_FRAME0);
        draw_fillcircle(288,132,6,0,0,255, BOTTOM_FRAME1);
        draw_string("B",284,128,0,0,0, BOTTOM_FRAME1);
      }
      if (HID_new & BUTTON_UP){
        draw_fillrect(230,103,242,115,0,0,0, BOTTOM_FRAME0);
        draw_rect(230,103,242,115,0,0,255, BOTTOM_FRAME0);
        draw_fillrect(230,103,242,115,0,0,0, BOTTOM_FRAME1);
        draw_rect(230,103,242,115,0,0,255, BOTTOM_FRAME1);
      } else {
        draw_fillrect(230,103,242,115,0,0,255, BOTTOM_FRAME0);
        draw_fillrect(230,103,242,115,0,0,255, BOTTOM_FRAME1);
      }
      if (HID_new & BUTTON_DOWN){
        draw_fillrect(230,129,242,142,0,0,0, BOTTOM_FRAME0);
        draw_rect(230,129,242,142,0,0,255, BOTTOM_FRAME0);
        draw_fillrect(230,129,242,142,0,0,0, BOTTOM_FRAME1);
        draw_rect(230,129,242,142,0,0,255, BOTTOM_FRAME1);
      } else {
        draw_fillrect(230,129,242,142,0,0,255, BOTTOM_FRAME0);
        draw_fillrect(230,129,242,142,0,0,255, BOTTOM_FRAME1);
      }
      if (HID_new & BUTTON_LEFT){
        draw_fillrect(217,116,229,128,0,0,0, BOTTOM_FRAME0);
        draw_rect(217,116,229,128,0,0,255, BOTTOM_FRAME0);
        draw_fillrect(217,116,229,128,0,0,0, BOTTOM_FRAME1);
        draw_rect(217,116,229,128,0,0,255, BOTTOM_FRAME1);
      } else {
        draw_fillrect(217,116,229,128,0,0,255, BOTTOM_FRAME0);
        draw_fillrect(217,116,229,128,0,0,255, BOTTOM_FRAME1);
      }
      if (HID_new & BUTTON_RIGHT){
        draw_fillrect(243,116,255,128,0,0,0, BOTTOM_FRAME0);
        draw_rect(243,116,255,128,0,0,255, BOTTOM_FRAME0);
        draw_rect(243,116,255,128,0,0,255, BOTTOM_FRAME1);
      } else {
        draw_fillrect(243,116,255,128,0,0,255, BOTTOM_FRAME0);
        draw_fillrect(243,116,255,128,0,0,255, BOTTOM_FRAME1);
      }
      if (HID_new & BUTTON_SELECT){
        draw_fillrect(243,146,261,155,0,0,0, BOTTOM_FRAME0);
        draw_rect(243,146,261,155,0,0,255, BOTTOM_FRAME0);
        draw_fillrect(243,146,261,155,0,0,0, BOTTOM_FRAME1);
        draw_rect(243,146,261,155,0,0,255, BOTTOM_FRAME1);
      } else {
        draw_fillrect(243,146,261,155,0,0,255, BOTTOM_FRAME0);
        draw_fillrect(243,146,261,155,0,0,255, BOTTOM_FRAME1);
      }
      if (HID_new & BUTTON_START){
        draw_fillrect(263,146,281,155,0,0,0, BOTTOM_FRAME0);
        draw_rect(263,146,281,155,0,0,255, BOTTOM_FRAME0);
        draw_fillrect(263,146,281,155,0,0,0, BOTTOM_FRAME1);
        draw_rect(263,146,281,155,0,0,255, BOTTOM_FRAME1);
      } else {
        draw_fillrect(263,146,281,155,0,0,255, BOTTOM_FRAME0);
        draw_fillrect(263,146,281,155,0,0,255, BOTTOM_FRAME1);
      }
      if (HID_new & BUTTON_L1){
        draw_fillrect(217,90,245,99,0,0,0, BOTTOM_FRAME0);
        draw_rect(217,90,245,99,0,0,255, BOTTOM_FRAME0);
        draw_fillrect(217,90,245,99,0,0,0, BOTTOM_FRAME1);
        draw_rect(217,90,245,99,0,0,255, BOTTOM_FRAME1);
      } else {
        draw_fillrect(217,90,245,99,0,0,255, BOTTOM_FRAME0);
        draw_fillrect(217,90,245,99,0,0,255, BOTTOM_FRAME1);
      }
      if (HID_new & BUTTON_R1){
        draw_fillrect(278,90,306,99,0,0,0, BOTTOM_FRAME0);
        draw_rect(278,90,306,99,0,0,255, BOTTOM_FRAME0);
        draw_fillrect(278,90,306,99,0,0,0, BOTTOM_FRAME1);
        draw_rect(278,90,306,99,0,0,255, BOTTOM_FRAME1);
      } else {
        draw_fillrect(278,90,306,99,0,0,255, BOTTOM_FRAME0);
        draw_fillrect(278,90,306,99,0,0,255, BOTTOM_FRAME1);
      }
    }
  }

return 0;
}

