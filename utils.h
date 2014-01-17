#ifndef UTILS_H
#define UTILS_H

#define STACK_SIZE 0x00004000
#define FCRAM_BASE 0x20000000



// Video Output

#define TOP_ASPECT_X 0x5
#define TOP_ASPECT_Y 0x3
#define TOP_HEIGHT 239
#define TOP_WIDTH 400
#define BOTTOM_WIDTH 320
#define FRAMEBUFFER_SEL 0x20184E59
#define TOP_LEFT_FRAME1 0x20184E60
#define TOP_LEFT_FRAME2 0x201CB370
#define TOP_RIGHT_FRAME1 0x20282160  
#define TOP_RIGHT_FRAME2 0x202C8670
#define BOTTOM_FRAME1 0x202118E0
#define BOTTOM_FRAME2 539039968

// IO  
#define STATE_3D_SLIDER	0x1FF81080 
#define TIMER  0x10003000
#define HID  0x10146000  


  
void write_byte(int address, char byte);
void write_word(int address, int word);
int read_word(int address);
void* find_byte_sequence(char* sequence, int num, int base_address);
int strlen(char* string); 
void itoa(int n, char s[]);
void reverse(char s[]);

#endif

