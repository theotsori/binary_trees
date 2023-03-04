#include "binary_trees.h"

/**
 * count_nodes - Count the number of nodes in a binary tree
 * @root: Pointer to the root node of the tree to count nodes in
 *
 * Return: The number of nodes in the binary tree
 */
size_t count_nodes(heap_t *root)
{
	size_t count = 0;

	if (root)
	{
		count++;
		count += count_nodes(root->left);
		count += count_nodes(root->right);
	}

	return (count);
}

/**
 * heapify - Heapify a binary tree
 * @node: Pointer to the root node of the tree to heapify
 */
void heapify(heap_t *node)
{
	heap_t *max = NULL;
	int temp;

	if (!node)
		return;

	while (1)
	{
		if (node->left && node->left->n > node->n)
			max = node->left;
		else
			max = node;

		if (node->right && node->right->n > max->n)
			max = node->right;

		if (max == node)
			break;

		temp = node->n;
		node->n = max->n;
		max->n = temp;
		node = max;
	}
}

/**
 * heap_insert - Insert a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap to insert the value in
 * @value: Value to insert
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	size_t n_nodes;

	if (!root)
		return (NULL);
	n_nodes = count_nodes(*root);
	if (!n_nodes)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	parent = *root;
	while (parent->left && parent->right)
	{
		if (count_nodes(parent->left) == count_nodes(parent->right))
			parent = parent->left;
		else
			parent = parent->right;
	}
	if (!parent->left)
	{
		new_node = binary_tree_node(parent, value);
		if (!new_node)
			return (NULL);
		parent->left = new_node;
	}
	else
	{
		new_node = binary_tree_node(parent, value);
		if (!new_node)
			return (NULL);
		parent->right = new_node;
	}
	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		new_node->n ^= new_node->parent->n;
		new_node->parent->n ^= new_node->n;
		new_node->n ^= new_node->parent->n;
		new_node = new_node->parent;
	}
	heapify(*root);
	return (new_node);
}
