#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is aleaf
 * @node: node to be checked
 *
 * Return: the value in node
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
	{
		return (0);
	}

	return (node->left == NULL && node->right == NULL);
}
