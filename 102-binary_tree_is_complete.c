#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the binary tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t nodes_count, i;
	binary_tree_t **queue, *node;

	if (tree == NULL)
		return (0);

	nodes_count = binary_tree_size(tree);

	queue = malloc(sizeof(*queue) * nodes_count);
	if (queue == NULL)
		return (0);

	queue[0] = (binary_tree_t *)tree;
	i = 0;

	while (i <= nodes_count - 1)
	{
		node = queue[i];

		if (node->left != NULL)
		{
			queue[(2 * i) + 1] = node->left;
			if (node->right != NULL)
				queue[(2 * i) + 2] = node->right;
			else if (node->left->left != NULL || node->left->right != NULL)
				return (0);
		}
		else if (node->right != NULL)
			return (0);

		++i;
	}

	free(queue);
	return (1);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: A pointer to the node to measure size
 *
 * Return: Size ot the measured tree
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
