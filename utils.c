#include "utils.h"
#include "memory.h"

void write_word(int address, int word){
  int *a = (int*) address;
  *a = word;
}

void write_byte(int address, char byte){
  char *a = (char*) address;
  *a = byte;
}

int read_word(int address){
  int *a = (int*) address;
  return *a;
}

void* find_byte_sequence(char* sequence, int num, int base_address){
  char* c = (char*)base_address;  
  while (1){
    if (*c == sequence[0]){
      int i;
      for (i = 1; i < num; i++){
        if(*(c+i) == sequence[i]){

        } else {
          break;
        }
        return (void*)c;
      }
    }
    c++;
  }
}

int strlen(char* string){
  int i;
  for (i = 0; ; i++){
      if (string[i] == 0x00){
        return i;
      }
  }
}

/* itoa:  convert n to characters in s */
 void itoa(int n, char s[])
 {
     int i, sign;
 
     if ((sign = n) < 0)  /* record sign */
         n = -n;          /* make n positive */
     i = 0;
     do {       /* generate digits in reverse order */
         s[i++] = n % 10 + '0';   /* get next digit */
     } while ((n /= 10) > 0);     /* delete it */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
 }

 /* reverse:  reverse string s in place */
 void reverse(char s[])
 {
     int i, j;
     char c;
 
     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }
