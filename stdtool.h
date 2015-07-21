#ifndef STDTOOL_H
#define STDTOOL_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//Print a char on the standard outpout
void				my_putchar(char c);
// Print a char in the binary format
void				printBit(unsigned char var);
// Print an array of char in 2D
void				printCharArray2D(char *array, int m, int n);
//Print an array of char like a maze
void				printCharArrayMaze(char *array, int m, int n);
// Get a random int between 0 and n - 1
int					get_nbrand(int n);

#endif