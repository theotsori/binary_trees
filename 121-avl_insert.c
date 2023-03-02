#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree for inserting the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node, *parent, *grandparent, *unbalanced;

	if (tree == NULL)
		return (NULL);

	parent = NULL;
	grandparent = NULL;
	node = *tree;

	while (node != NULL)
	{
		if (value == node->n)
			return (NULL);
		if (node->left != NULL)
			node->left->parent = node;
		if (node->right != NULL)
			node->right->parent = node;
		if (binary_tree_balance(node) != 0)
		{
			grandparent = parent;
			parent = node;
		}

		parent = node;
		node = (value < node->n) ? node->left : node->right;
	}
	node = binary_tree_node(parent, value);

	if (node == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = node;
		return (node);
	}
	if (value < parent->n)
		parent->left = node;
	else
		parent->right = node;
	unbalanced = NULL;

	while (parent != NULL)
	{
		if (parent->left == node)
			parent->balance--;
		else
			parent->balance++;
		if (parent->balance == 0)
			break;
		if (parent->balance < -1 || parent->balance > 1)
		{
			unbalanced = parent;
			break;
		}
		node = parent;
		parent = parent->parent;
	}
	return (node);
}
