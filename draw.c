/* 
2d drawing primitives for 3DS

  collection and adaption from etherogeneus web sources - fully open source if not otherwise specified

  January 13, 2014
  Nop90 - Public domain
*/

#include "draw.h"
#include "memory.h"
#include "utils.h"
#include "ascii64.h"
#include "sin_lookup.h"

void draw_color(int address, char r, char g, char b){
  write_byte(address, b);
  write_byte(address+1, g);
  write_byte(address+2, r);
}

void draw_pixel(int x, int y, char r, char g, char b, int screen){
/*  int width;
  if((screen==BOTTOM_FRAME1)|(screen==BOTTOM_FRAME2)){
    width=BOTTOM_WIDTH;
  } else {
    width=TOP_WIDTH;
  }
  if((x>=0)&(y>=0)&(y<240)&(x<width)){    */
    int coord = 720*x+720-(y*3)-3;
    draw_color(coord+screen,r,g,b);
//  }
}

void draw_char(char letter,int x,int y, char r, char g, char b, int screen){
  int i, k;
  unsigned char mask;
  unsigned char l;

  for (i = 0; i < 8; i++){
    mask = 0b10000000;
    l = ascii_data[letter][i];
    for (k = 0; k < 8; k++){
      if ((mask >> k) & l){
        draw_pixel(k+x,i+y,r,g,b,screen);
      }     
    }
  }
}

void draw_string(char* word, int x,int y, char r, char g, char b, int screen){
    int tmp_x =x;
    int i;
    int line = 0;

    int width;

  switch(screen){
    case BOTTOM_FRAME1:
      width=BOTTOM_WIDTH;
      break;
    default:
      width=TOP_WIDTH;
      break;
  }

    for (i = 0; i <strlen(word); i++){
     
      if (tmp_x+8 > width) {
        line++;
        tmp_x = x;
      }
      draw_char(word[i],tmp_x,y+(line*8),r,g,b, screen);

      tmp_x = tmp_x+8;
    }
}

/*
  draw_line - Bresenham Alghoritm
*/

void draw_line( int x1, int y1, int x2, int y2, char r, char g, char b, int screen){

int dx, dy, sdx, sdy, x, y, px, py;

 x = 0;
 y = 0;
 dx = x2 - x1;
 dy = y2 - y1;
 sdx = (dx < 0) ? -1 : 1;
 sdy = (dy < 0) ? -1 : 1;
 dx = sdx * dx + 1;
 dy = sdy * dy + 1;
 px = x1;
 py = y1;

 if (dx >= dy)
 {
	for (x = 0; x < dx; x++)
	{
		draw_pixel(px,py,r,g,b,screen);
		y += dy;
		if (y >= dx)
		{
			y -= dx;
			py += sdy;
		}
		px += sdx;
	}
 }
   else
 {
	for (y = 0; y < dy; y++)
	{
		draw_pixel(px,py,r,g,b,screen);
		x += dx;
		if (x >= dy)
		{
			x -= dy;
			px += sdx;
		}
		py += sdy;
	}
 }
}

void draw_rect( int x1, int y1, int x2, int y2, char r, char g, char b, int screen){

// TO DO: change the code, because draw_line is not efficient for horizontal and vertical lines 

  draw_line( x1, y1, x2, y1, r, g, b, screen);
  draw_line( x2, y1, x2, y2, r, g, b, screen);
  draw_line( x1, y2, x2, y2, r, g, b, screen);
  draw_line( x1, y1, x1, y2, r, g, b, screen);
}

void draw_fillrect( int x1, int y1, int x2, int y2, char r, char g, char b, int screen){
int X1,X2,Y1,Y2,i,j;

/*  
  if (x1>x2){ 
    X1=x2;
    X2=x1;
  } else { 
    X1=x1;
    X2=x2;
  } 

  if (y1>y2){ 
    Y1=y2;
    Y2=y1;
  } else { 
    Y1=y1;
    Y2=y2;
  } 
*/
  for(i=x1;i<=x2;i++){
    for(j=y1;j<=y2;j++){
      draw_pixel(i,j, r, g, b, screen);
    }
  }
}

/*
  draw_circle - draws a circle with center at coordinates (x,y) and radius rad
*/

void draw_circle(int x, int y, int rad, char r, char g, char b, int screen){
  int deg = 0;
  int X,Y;
  do
  {
	X = (rad * sin_lookuptable[255-deg])>>10;
	Y = (rad * sin_lookuptable[deg])>>10;
	draw_pixel(x+X, y+Y,r,g,b,screen);
	draw_pixel(x-X, y+Y,r,g,b,screen);
	draw_pixel(x+X, y-Y,r,g,b,screen);
	draw_pixel(x-X, y-Y,r,g,b,screen);
	deg += 1;
  }
  while (deg <= 255);
}

void draw_fillcircle(int x, int y, int rad, char r, char g, char b, int screen){
  int deg = 0;
  int X,Y,i;
  do
  {
    X = (rad * sin_lookuptable[255-deg])>>10;
    Y = (rad * sin_lookuptable[deg])>>10;
    for(i=x-X;i<=x+X;i++){
      draw_pixel(i, y+Y,r,g,b,screen);
      draw_pixel(i, y-Y,r,g,b,screen);
    }
    deg += 1;
  }
  while (deg <= 255);
}

