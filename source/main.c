#include "../include/maze.h"
#include "../include/stdtool.h"

int 				main(int argc, char const *argv[])
{
	maze_t			*maze;

	if (argc != 3) {
		printf("\033[31;01mUsage: ./a.out nbCol nbLine\033[00m\n");
		return (0);
	}
	maze = newMaze(strtol(argv[1], NULL, 10), strtol(argv[2], NULL, 10));
	generate_maze(maze);
	// printCharArrayMaze(maze->array, maze->m, maze->n);
	printSDLCharArrayMaze(maze->array, maze->m, maze->n);
	destroyMaze(maze);

	return (0);
}
