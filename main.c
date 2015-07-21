#include "maze.h"
#include "stdtool.h"

int 				main(int argc, char const *argv[])
{
//	unsigned char 	test;
	maze_t			*maze;

	srand(time(NULL));
//	test = 0;
//	test |= 1 << 0;
//	printBit(test);
//	printf("%d\n", test & CELL_N);
//	printf("%s\n", argv[1]);
	maze = newMaze(strtol(argv[1], NULL, 10), strtol(argv[2], NULL, 10));
	printf("Taille du tableau = %d\n", maze->m * maze->n);
	if (cell_at_dir(24, &maze->array[19], maze))
		printf("The cell exists !\n");
	else
		printf("The cell doesn't exist !\n");
	printCharArrayMaze(maze->array, maze->m, maze->n);
	destroyMaze(maze);

	return (0);
}