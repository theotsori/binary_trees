#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_levelorder - Traverse a binary tree using level-order traversal.
 *
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *queue[10000];
	int front = 0, rear = 0;

	if (tree == NULL || func == NULL)
		return;

	queue[rear] = (binary_tree_t *)tree;
	rear = (rear + 1) % 10000;

	while (front != rear)
	{
		binary_tree_t *node = queue[front];

		front = (front + 1) % 10000;

		func(node->n);

		if (node->left != NULL)
		{
			queue[rear] = node->left;
			rear = (rear + 1) % 10000;
		}

		if (node->right != NULL)
		{
			queue[rear] = node->right;
			rear = (rear + 1) % 10000;
		}
	}
}
