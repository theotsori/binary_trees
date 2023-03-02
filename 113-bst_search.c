#include "binary_trees.h"

/**
 * bst_search - function that searches value in a binary search tree
 * @tree: binary tree to be searched
 * @value: value to search in the tree
 *
 * Return: A pointer to the node containing a value equals to value
*/
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (tree->n == value)
		return ((bst_t *)tree);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
}
