#include "maze.h"
#include "stdtool.h"

int 				main(int argc, char const *argv[])
{
	maze_t			*maze;

	maze = newMaze(strtol(argv[1], NULL, 10), strtol(argv[2], NULL, 10));
	generate_maze(maze);
	printCharArrayMaze(maze->array, maze->m, maze->n);
	destroyMaze(maze);

	return (0);
}