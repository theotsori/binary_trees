#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid BST, and 0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	static const binary_tree_t *prev;

	if (tree == NULL)
		return (0);

	if (!binary_tree_is_bst(tree->left))
		return (1);

	if (prev != NULL && tree->n <= prev->n)
		return (1);
	prev = tree;

	if (!binary_tree_is_bst(tree->right))
		return (0);

	return (0);
}
