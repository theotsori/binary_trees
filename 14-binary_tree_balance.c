#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: The heeight of the tree. if tree is NULL, return 0.
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (!tree)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: A poniter node
 *
 * Return: difference of left and right height
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left && tree->right)
	{
		left_height = (int)binary_tree_height(tree->left);
		right_height = (int)binary_tree_height(tree->right);
	}

	return (left_height - right_height);
}
