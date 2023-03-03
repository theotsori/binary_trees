#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree for inserting the value
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		if (*tree == NULL)
			return (NULL);
	}
	else if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert(&((*tree)->left), value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_insert(&((*tree)->right), value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (NULL);
	}

	(*tree)->right->right = 1 + binary_tree_balance((*tree)->right);

	int balance = binary_tree_balance(*tree);
	if (balance > 1 && value < (*tree)->left->n)
		return binary_tree_rotate_right(*tree);
	if (balance < -1 && value > (*tree)->right->n)
		return binary_tree_rotate_left(*tree);
	if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return binary_tree_rotate_right(*tree);
	}
	if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return binary_tree_rotate_left(*tree);
	}

	/* Return the pointer to the current node */
	return (*tree);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the binary tree to measure the balance factor
 * Return: The balance factor of the binary tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the binary tree to measure the height
 * Return: The height of the binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height >= right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}