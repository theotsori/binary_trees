#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a binary search tree
 *
 * @tree: A double pointer to the root node of the BST to insert the value
 * @value: The value to store in the node to be iserted
 *
 * Return: A pointer to the created node, or Null on failure
*/
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *parent;

	if (!tree)
		return (NULL);

	parent = NULL;
	while (*tree)
	{
		if ((*tree)->n == value)
			return (NULL);

		parent = *tree;
		if (value < (*tree)->n)
			tree = &((*tree)->left);
		else
			tree = &((*tree)->right);
	}

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (parent)
	{
		if (value < parent->n)
			parent->left = new_node;
		else
			parent->right = new_node;
	}
	else
		*tree = new_node;

	return (new_node);
}
