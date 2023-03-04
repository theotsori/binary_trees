#include "binary_trees.h"

/**
 * tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the binary tree
 */
size_t tree_size(heap_t *tree)
{
	size_t size = 0;

	if (tree)
		size = 1 + tree_size(tree->left) + tree_size(tree->right);

	return (size);
}

/**
 * heapify_down - Reorders the heap from the root node downwards
 * @root: Double pointer to the root node of the heap
 */
void heapify_down(heap_t **root)
{
	heap_t *node = *root, *child = NULL;
	int temp;

	while (node->left)
	{
		child = node->left;
		if (node->right && node->right->n > child->n)
			child = node->right;

		if (node->n < child->n)
		{
			temp = node->n;
			node->n = child->n;
			child->n = temp;

			node = child;
		}
		else
		{
			break;
		}
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *node = *root, *parent = NULL;
	int value;

	if (!node)
		return (0);

	value = node->n;

	if (!node->left && !node->right)
	{
		free(node);
		*root = NULL;
		return (value);
	}

	node = *root;
	while (node->left)
	{
		parent = node;
		if (node->right && node->right->n > node->left->n)
			node = node->right;
		else
			node = node->left;
	}

	(*root)->n = node->n;
	if (parent && parent->right)
		parent->right = NULL;
	else if (parent)
		parent->left = NULL;
	else
		*root = NULL;

	free(node);

	heapify_down(root);

	return (value);
}
