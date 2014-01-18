#ifndef UTILS_H
#define UTILS_H

void write_byte(int address, char byte);
void write_word(int address, int word);
int read_word(int address);
void* find_byte_sequence(char* sequence, int num, int base_address);
int strlen(char* string); 
void itoa(int n, char s[]);
void reverse(char s[]);


#endif

