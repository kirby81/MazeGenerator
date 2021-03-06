#ifndef MAZE_H
#define MAZE_H

/* Define directions */
enum {N, W, S, E};

/*
 * Cell definitions:
 * -----------------
 * Cells are maped by chars.
 * 1st bit maps North door
 * 2nd bit maps West  door
 * 3rd bit maps South door
 * 4th bit maps East  door
 * 5th bit maps visited cells.
 *
 * bit unset  => closed or unvisited
 * bit set    => open   or visited
*/

 /* Bit masks: */
#define CELL_N  1
#define CELL_W  2
#define CELL_S  4
#define CELL_E  8
#define CSTATE 	16

#define STATE 	4

/* Define maze structure */
typedef struct {
	/* Maze size = m lines * n columns */
	int 	m, n;

	/* Entrence and exit cells */
	char 	*in, *out;

	/* Array of cells ==> the maze */
	char 	*array;
} maze_t;

/* Define node structure */
typedef struct 			node_t{
	/* A maze cell */
	char 				*cell;

	struct node_t		*next;
	struct node_t		*prev;

} node_t;

/* Define tree structure */
typedef struct 	list_t
{
	node_t 		*root;

	int			size;
} list_t;

/* Prototypes maze.c*/
// Create a new maze with m lines ans n columns
maze_t		*newMaze(int m, int n);
// Destroy a maze
void		destroyMaze(maze_t *maze);
// Get the array index from coord
char		*get_cellxy(int x, int y, maze_t *maze);
// Get the x coord from a cell pointer
int			cell_x(char *cell, maze_t *maze);
// Get the y coord from a cell pointer
int			cell_y(char *cell, maze_t *maze);
// Check if a cell exist
char		*cell_at_dir(int dir, char *cell, maze_t *maze);
// Get a random border cell from the maze
char        *rand_border_cell(maze_t *maze);
// Get a random cell next to the current one
char        *rand_next_cell(char *cell, maze_t *maze);
// Get a random cell from the maze
char        *rand_cell(maze_t *maze);
// Generate a maze
void        generate_maze(maze_t *maze);

/* Prototypes tree.c*/
node_t		*add_child(node_t *node, char *cell);
list_t		*new_list(char *cell);
void		destroy_list(list_t *list);

#endif
