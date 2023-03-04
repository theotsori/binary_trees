#include "binary_trees.h"

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * Return: Value stored in the root node or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *node, *last;

	if (!root || !*root)
		return (0);

	value = (*root)->n;
	
	last = binary_tree_leaves(*root);

	if (*root == last)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	(*root)->n = last->n;

	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	free(last);

	node = *root;
	while (node)
	{
		heap_t *left, *right, *max = node;

		left = node->left;
		right = node->right;

		if (left && left->n > max->n)
			max = left;
		if (right && right->n > max->n)
			max = right;
		if (max == node)
			break;

		node->n = max->n;
		max->n = value;
		node = max;
	}
	return (value);
}
