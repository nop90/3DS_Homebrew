#ifndef PSDRAW_H
#define PSDRAW_H

#define Z_LOW -64
#define Z_HIGH 63

int Xleft(int x,int z);
int Xright(int x,int z);
int pY(int y,int z);
void psdraw_pixel(int x, int y, int z, char r, char g, char b);
void psdraw_line( int x1, int y1, int x2, int y2, int z, char r, char g, char b);
void psdraw_rect( int x1, int y1, int x2, int y2, int z, char r, char g, char b);
void psdraw_fillrect( int x1, int y1, int x2, int y2, int z, char r, char g, char b);
void psdraw_circle(int x, int y, int z, int rad, char r, char g, char b);
void psdraw_fillcircle(int x, int y, int z, int rad, char r, char g, char b);

#endif

