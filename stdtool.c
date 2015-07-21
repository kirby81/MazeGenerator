#include "stdtool.h"
#include "maze.h"

/*
 * Print a char on the standard outpout
 * param: c the char to print
*/
void				my_putchar(char c)
{
	write(1, &c, 1);
}

/*
 * Get a random int between 0 and n - 1
 * param: borne sup
 * Return: 
*/
int					get_nbrand(int n)
{
	return (rand() % (n - 1));
}

/*
 * Print a char in the binary format
 * Param: var the char to print
*/
void				printBit(unsigned char var)
{
	unsigned char 	size = sizeof(unsigned char);
    unsigned char 	maxPow = 1<<(size*8-1);
    int				i = 0;

	for (; i < size * 8; ++i) {
		printf("%u ", var&maxPow ? 1 : 0);
		var = var << 1;
	}
	printf("\n");
}

/*
 * Print an array of char in 2D
 * Param: array the char array, m lines, n columns
*/
 void				printCharArray2D(char *array, int m, int n)
 {
 	int				i = 0;

 	for (; i < m * n; i++) {
 		printf("%c ", array[i] + '0');
 		if ((i + 1) % n == 0 && i != 0)
 			printf("\n");
 	}
 }

 /*
 * Print an array of char like a maze
 * Param: array the char array, n lines, m columns
*/
 void				printCharArrayMaze(char *array, int m, int n)
 {
 	int				i = 0;
 	int				j = 0;

 	while (j < n) {
 		while (i < m * (j + 1)) {
 			if (!(array[i] & CELL_N)) {
 				my_putchar(' ');
 				my_putchar('_');
 				my_putchar(' ');
 			}
 			else {
 				my_putchar(' ');
 				my_putchar(' ');
 				my_putchar(' ');	
 			}
 			i++;
 		}
 		my_putchar('\n');
 		i -= (m);
 		while (i < m * (j + 1)) {
 			if (!(array[i] & CELL_W))
 				my_putchar('|');
 			else
 				my_putchar(' ');
 			if (!(array[i] & CELL_S))
 				my_putchar('_');
 			else
 				my_putchar(' ');
  			if (!(array[i] & CELL_E))
 				my_putchar('|');
 			else
 				my_putchar(' ');
 			i++;
 		}
 		my_putchar('\n');
 		j++;
 	}
 }