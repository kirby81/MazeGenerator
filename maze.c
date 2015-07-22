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

/*
 * Get a random border cell from the maze
 * Param: the maze
 * Return: a pointer on a random border cell
*/
char        *rand_border_cell(maze_t *maze)
{
  char      **border_maze;
  int       perimeter;
  int       i, j;
  char      *res;

  perimeter = 2 * maze->m + 2 * (maze->n - 2);
  border_maze = malloc(sizeof(char*) * perimeter);
  i = 0;
  j = 0;
  while (i < maze->m) {
    border_maze[j] = get_cellxy(i, 0, maze);
    border_maze[j + 1] = get_cellxy(i, maze->n - 1, maze);
    j += 2;
    i++;
  }
  i = 1;
  while (i < (maze->n - 1)) {
    border_maze[j] = get_cellxy(0, i, maze);
    border_maze[j + 1] = get_cellxy(maze->m - 1, i, maze);
    j += 2;
    i++;
  }
  res = border_maze[get_nbrand(perimeter)];
  free(border_maze);
  return (res);
}

/*
 * Get a random cell next to the current one
 * Param: the current cell and the maze
 * Return: the random cell
*/
char        *rand_next_cell(char *cell, maze_t *maze)
{
  char      *cellArray[4];
  const int dir[4] = {N, W, S, E};
  int       size;
  int       i;

  size = 0;
  i = 0;
  while (i < 4) {
    if (cellArray[size] = cell_at_dir(i, cell, maze)) {
      if ((*cellArray[size] & CSTATE) == 0)
        size++;
    }
    i++;
  }
  return (cellArray[get_nbrand(size + 1)]);
}

