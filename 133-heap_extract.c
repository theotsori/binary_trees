#include "binary_trees.h"

/**
 * binary_tree_get_last - Gets the last node of a binary tree
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: Pointer to the last node of the binary tree, or NULL on failure
 */
heap_t *binary_tree_get_last(heap_t *tree)
{
	heap_t *last = NULL;
	size_t height, i;

	if (tree == NULL)
		return (NULL);

	height = binary_tree_height(tree);

	for (i = 0; i < height; i++)
		tree = tree->left;

	while (tree)
	{
		last = tree;
		tree = tree->right;
	}

	return (last);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: Height of the binary tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const heap_t *tree)
{
	size_t height_l, height_r;

	if (tree == NULL)
		return (0);

	height_l = binary_tree_height(tree->left);
	height_r = binary_tree_height(tree->right);

	return (1 + (height_l > height_r ? height_l : height_r));
}

/**
 * swap_values - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap_values(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last, *parent;

	if (root == NULL || *root == NULL)
		return (0);

	value = (*root)->n;

	last = binary_tree_get_last(*root);
	if (*root == last)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	last->parent = NULL;
	last->left = (*root)->left;
	last->right = (*root)->right;

	if (last->left)
		last->left->parent = last;
	if (last->right)
		last->right->parent = last;

	free(*root);
	*root = last;

	parent = last->parent;
	while (parent && last->n > parent->n)
	{
		swap_values(&last->n, &parent->n);
		last = parent;
		parent = last->parent;
	}

	return (value);
}
