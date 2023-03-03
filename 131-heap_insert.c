#include "binary_trees.h"

/**
 * heap_size - Measures the size of a heap
 * @root: Pointer to the root node of the heap
 *
 * Return: The size of the heap
 */
size_t heap_size(const binary_tree_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + heap_size(root->left) + heap_size(root->right));
}

/**
 * heapify - Heapifies a binary tree node
 * @node: Pointer to the root node of the binary tree to heapify
 */
void heapify(heap_t *node)
{
	heap_t *largest = node;

	if (node->left && node->left->n > largest->n)
		largest = node->left;

	if (node->right && node->right->n > largest->n)
		largest = node->right;

	if (largest != node)
	{
		int tmp = node->n;

		node->n = largest->n;
		largest->n = tmp;
		heapify(largest);
	}
}

/**
 * heap_insert - Inserts a value in a max binary heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node, *parent;
	int tmp;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	node = *root;
	while (node->left != NULL)
	{
		if (node->right == NULL)
			break;
		if (heap_size(node->left) > heap_size(node->right))
			node = node->right;
		else
			node = node->left;
	}

	parent = node->parent;
	while (parent != NULL && node->n > parent->n)
	{
		tmp = node->n;
		node->n = parent->n;
		parent->n = tmp;
		node = parent;
		parent = node->parent;
	}

	if (node->left == NULL)
		node->left = binary_tree_node(node, value);
	else
		node->right = binary_tree_node(node, value);

	heapify(*root);

	return (node->left ? node->left : node->right);
}
