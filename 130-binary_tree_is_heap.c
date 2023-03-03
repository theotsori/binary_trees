#include "binary_trees.h"

/**
 * binary_tree_is_heap - function that checks if a binary
 * tree is a valid Max Binary Heap
 * @tree: A pointer to the tree
 * Return: 1 if tree is valid
*/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}
	if (tree->right == NULL)
	{
		return (tree->n >= tree->left->n && binary_tree_is_heap(tree->left));
	}
	if (tree->left == NULL)
	{
		return (tree->n >= tree->right->n && binary_tree_is_heap(tree->right));
	}
	if (tree->n >= tree->left->n && tree->n >= tree->right->n)
	{
		return (binary_tree_is_heap(tree->left) && binary_tree_is_heap(tree->right));
	}
	return (0);
}
