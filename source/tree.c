#include "../include/stdtool.h"
#include "../include/maze.h"

node_t			*add_child(node_t *node, char *cell)
{
	node_t		*new_node;

	if (!cell)
		return (NULL);

	new_node = malloc(sizeof(node_t));
	new_node->cell = cell;
	new_node->prev = node;
	new_node->next = node->next;
	node->next = new_node;

	return (new_node);
}

list_t			*new_list(char *cell)
{
	list_t		*list;
	node_t		*node;

	node = malloc(sizeof(node_t));
	node->cell = cell;
	node->prev = NULL;
	node->next = NULL;

	list = malloc(sizeof(list_t));
	list->root = node;
	list->size = 1;

	return (list);
}

void			destroy_list(list_t *list)
{
	node_t		*garbage;

	while (list->root != NULL) {
		garbage = list->root;
		list->root = (list->root)->next;
		free(garbage);
	}

	free(list);
}
