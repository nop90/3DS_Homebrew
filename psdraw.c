/* 
Plane Stereographic drawing primitives for 3DS

 - Items are drawn on planes parallel to the screen surface
 - Draw items respecting z-order, i.e. from lower (-64) to higher (63) 
 - At the moment 3D level is fixed and not related to the 3D slider position 

  January 13, 2014
  Nop90 - Public domain
*/

#include "psdraw.h"
#include "draw.h"
#include "memory.h"

int pXleft(int x,int z){
// Prospectic projection of x coordinate for left image

int r;

  if(z){  
    if(x<200){
      return r=((200-(z+z/2))*(200-x))/200; // Ignoring approximation 
    } else {
      return r=200+((200+z)*(x-200))/200;
    }
  } else {
    return x;
  }
}

int pXright(int x,int z){
// Prospectic projection of x coordinate for right image

int r;

  if(z){  
    if(x<200){
      return r = ((200-z)*(200-x))/200; 
    } else {
      return r= 200+((200+(z+z/2))*(x-200))/200; // Ignoring approximation 
    }
  } else {
    return x;
  }
}

int pY(int y,int z){
// Prospectic projection of y coordinate

  if(z){  
    if(y<120){
      return ((120-z)*(120-y))/120; 
    } else {
      return 120+((120+z)*(y-120))/120; 
    }
  }
}

void psdraw_pixel(int x, int y,int z, char r, char g, char b){
  if ((z>=Z_LOW)&(z<=Z_HIGH)){
    draw_pixel(pXleft(x,z),pY(y,z),r,g,b,TOP_LEFT_FRAME1);
    draw_pixel(pXright(x,z),pY(y,z),r,g,b,TOP_LEFT_FRAME2);
  }
}

void psdraw_line( int x1, int y1, int x2, int y2, int z, char r, char g, char b){
  if ((z>=Z_LOW)&(z<=Z_HIGH)){
    draw_line(pXleft(x1,z),pY(y1,z),pXleft(x2,z),pY(y2,z),r,g,b,TOP_LEFT_FRAME1);
    draw_line(pXright(x1,z),pY(y1,z),pXright(x2,z),pY(y2,z),r,g,b,TOP_LEFT_FRAME2);
  }
}

void psdraw_rect( int x1, int y1, int x2, int y2, int z, char r, char g, char b){
  psdraw_line( x1, y1, x2, y1, z, r, g, b);
  psdraw_line( x2, y1, x2, y2, z, r, g, b);
  psdraw_line( x1, y2, x2, y2, z, r, g, b);
  psdraw_line( x1, y1, x1, y2, z, r, g, b);
}

void psdraw_fillrect( int x1, int y1, int x2, int y2, int z, char r, char g, char b){
int X1,X2,Y1,Y2,i,j;
  
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
    Y1=Y1;
    Y2=Y2;
  } 

  for(i=X1;i<=X2;i++){
    for(j=Y1;i<=Y2;j++){
      psdraw_pixel(i, j, z, r, g, b);
// TO DO: above it's better to have two cicles for drawing right and left rectange using draw_pixel with adjusted x and y  boundaries, 
// avoiding prospectic transformation of each pixel of the cicle  
    }
  }
}


/*
  psdraw_circle - draws a stereographic circle parallel to screen, with center at coordinates (x,y,z) and radius rad
*/

void psdraw_circle(int x, int y, int z, int rad, char r, char g, char b){
/*
  float deg = 0;
  int X,Y;

  do
  {
	X = rad * fast_cos(deg);
	Y = rad * fast_sin(deg);
	psdraw_pixel(x+X,y+Y,z,r,g,b);
	deg += 0.005;
  }
  while (deg <= 6.4);
*/
}

void psdraw_fillcircle(int x, int y, int z, int rad, char r, char g, char b){
}
