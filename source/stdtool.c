#include "../include/stdtool.h"
#include "../include/maze.h"

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
 * Return: random int [0:n[
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

void SDLFillCell(char cell, SDL_Surface *rect) {
	SDL_Surface *door;
	SDL_Rect pos;

	SDL_FillRect(rect, NULL, SDL_MapRGB(rect->format, 0, 0, 0));
	if (!(cell & CELL_N)) {
		door = SDL_CreateRGBSurface(0, rect->w, 2, 32, 0, 0, 0, 0);
		SDL_FillRect(door, NULL, SDL_MapRGB(rect->format, 255, 0, 0));
		pos.x = 0;
		pos.y = 0;
		SDL_BlitSurface(door, NULL, rect, &pos);
		SDL_FreeSurface(door);
	}

	if (!(cell & CELL_S)) {
		door = SDL_CreateRGBSurface(0, rect->w, 2, 32, 0, 0, 0, 0);
		SDL_FillRect(door, NULL, SDL_MapRGB(rect->format, 255, 0, 0));
		pos.x = 0;
		pos.y = rect->h - 2;
		SDL_BlitSurface(door, NULL, rect, &pos);
		SDL_FreeSurface(door);
	}

	if (!(cell & CELL_E)) {
		door = SDL_CreateRGBSurface(0, 2, rect->h, 32, 0, 0, 0, 0);
		SDL_FillRect(door, NULL, SDL_MapRGB(rect->format, 255, 0, 0));
		pos.x = rect->w - 2;
		pos.y = 0;
		SDL_BlitSurface(door, NULL, rect, &pos);
		SDL_FreeSurface(door);
	}

	if (!(cell & CELL_W)) {
		door = SDL_CreateRGBSurface(0, 2, rect->h, 32, 0, 0, 0, 0);
		SDL_FillRect(door, NULL, SDL_MapRGB(rect->format, 255, 0, 0));
		pos.x = 0;
		pos.y = 0;
		SDL_BlitSurface(door, NULL, rect, &pos);
		SDL_FreeSurface(door);
	}
}

SDLMaze_t *SDLMazeGenerator(char *array, int m, int n) {
	SDLMaze_t *SDLMaze = malloc(sizeof(SDLMaze_t));
	SDLMaze->size = m * n;
	SDLMaze->w = 20 * m;
	SDLMaze->h = 20 * n;
	SDLMaze->cells = malloc(sizeof(SDL_Surface*) * SDLMaze->size);
	SDLMaze->positions = malloc(sizeof(SDL_Rect) * SDLMaze->size);
	SDL_Rect *tmpRect;

	for (size_t i = 0; i < SDLMaze->size; i++) {
		tmpRect = &SDLMaze->positions[i];
		SDLMaze->cells[i] = SDL_CreateRGBSurface(0, 20, 20, 32, 0, 0, 0, 0);
		SDLFillCell(array[i], SDLMaze->cells[i]);
		tmpRect->x = (i % m) * SDLMaze->cells[i]->w;
		tmpRect->y = (i / m) * SDLMaze->cells[i]->h;
	}

	return (SDLMaze);
}

void SDL_Pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}

int printSDLCharArrayMaze(char *array, int m, int n) {
	SDLMaze_t *SDLMaze;
	SDL_Surface *window;

	if (SDL_Init(SDL_INIT_VIDEO) == -1) {
		fprintf(stderr, "Erreur d'initialisation de la sdl\n");
		return (-1);
	}

	SDLMaze = SDLMazeGenerator(array, m , n);
	window = SDL_SetVideoMode(SDLMaze->w, SDLMaze->h, 32, SDL_HWSURFACE);

	for (size_t i = 0; i < SDLMaze->size; i++) {
		SDL_BlitSurface(SDLMaze->cells[i], NULL, window, &SDLMaze->positions[i]);
		// printf("x = %d y = %d\n", SDLMaze->positions[i].x, SDLMaze->positions[i].y);
	}

	for (size_t i = 0; i < SDLMaze->size; i++) {
		SDL_FreeSurface(SDLMaze->cells[i]);
	}

	free(SDLMaze->positions);
	free(SDLMaze->cells);
	free(SDLMaze);

	SDL_Flip(window);
	SDL_Pause();

	SDL_FreeSurface(window);
	SDL_Quit();

	return (0);
 }
