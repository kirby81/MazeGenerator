#include "stdtool.h"
#include "maze.h"

/*
 * Create a new maze with m lines ans n columns
 * Param: m number of lines, n number of columns
 * Return: pointer on the create maze (maze_t)
*/
maze_t		*newMaze(int m, int n)
{
	maze_t	*maze = malloc(sizeof(maze_t));

	maze->m = m;
	maze->n = n;
	maze->in = NULL;
	maze->out = NULL;
	maze->array = calloc(m * n, sizeof(char));
	return (maze);
}

/*
 * Destroy a maze
 * Param: the maze
*/
void		destroyMaze(maze_t *maze)
{
	free(maze->array);
	free(maze);
}

/*
 * Get the array index from coord
 * Param: x and y coord and number of columns (i = my + x)
 * Return: pointer on the cell or NULL if out of bound
*/
char		*get_cellxy(int x, int y, maze_t *maze)
{
	int		index;

	if (x < 0 || y < 0 || x > maze->m - 1 || y > maze->n - 1)
		return (NULL);
	index = maze->m * y + x;
	return (&(maze->array[index]));
}

/*
 * Get the x coord from a cell pointer
 * Param: pointer on a cell and the maze
 * Return: the x coord
*/
 int		cell_x(char *cell, maze_t *maze)
 {
 	int		index;

 	index = cell - maze->array;
 	return (index % maze->m);
 }

/*
 * Get the y coord from a cell pointer
 * Param: pointer on a cell and the maze
 * Return: the y coord
*/
 int		cell_y(char *cell, maze_t *maze)
 {
 	int		index;

 	index = cell - maze->array;
 	return (index / maze->m);
 }

 /*
  * Check if a cell exist 
  * Param: dir to look from the given cell
  * Return: the cell if exists or NULL
 */
  char		*cell_at_dir(int dir, char *cell, maze_t *maze)
  {
  	int		x, y;

  	x = cell_x(cell, maze);
  	y = cell_y(cell, maze);
  	switch (dir) {
  		case N:
  			y -= 1;
  			break;
  		case W:
  			x -= 1;
  			break;
  		case S:
  			y += 1;
  			break;
  		case E:
  			x += 1;
  			break;
  		default:
  			return (NULL);
  	}
  	return (get_cellxy(x, y, maze));
  }