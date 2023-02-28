#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if given node is root
 * @node: node to be checked
 *
 * Return: node if parent
*/
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
	{
		return (0);
	}

	return (node->parent == NULL);
}
