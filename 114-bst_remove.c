#include "binary_trees.h"
/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree where to remove a node
 * @value: Value to remove in the tree
 *
 * Return: Pointer to the new root node of
 * the tree after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *parent, *current, *successor;

	if (root == NULL)
		return (NULL);
	current = root;
	parent = NULL;

	while (current != NULL && current->n != value)
	{
		parent = current;
		if (value < current->n)
			current = current->left;
		else
			current = current->right;
	}
	if (current == NULL)
		return (root);
	if (current->left == NULL)
		successor = current->right;
	else if (current->right == NULL)
		successor = current->left;
	else
	{
		successor = current->right;

		while (successor->left != NULL)
			successor = successor->left;
		successor->left = current->left;
	}
	if (parent == NULL)
		root = successor;
	else if (parent->left == current)
		parent->left = successor;
	else
		parent->right = successor;

	if (successor != NULL)
		successor->parent = parent;
	free(current);
	return (root);
}
