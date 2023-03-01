#include "binary_trees.h"
/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_t *queue = NULL;
	const binary_tree_t *node = NULL;
	int is_complete = 1, has_missing = 0, *queue = NULL;

	if (!tree)
		return (0);
	queue = queue_create();
	if (!queue)
		return (0);
	queue_push(queue, (void *)tree);
	while (!queue_is_empty(queue))
	{
		node = (const binary_tree_t *)queue_pop(queue);
		if (node->left)
		{
			if (has_missing)
			{
				is_complete = 0;
				break;
			}
			queue_push(queue, (void *)node->left);
		}
		else
		{
			has_missing = 1;
		}
		if (node->right)
		{
			if (has_missing)
			{
				is_complete = 0;
				break;
			}
			queue_push(queue, (void *)node->right);
		}
		else
		{
			has_missing = 1;
		}
	}
	queue_delete(queue);
	return (is_complete);
}
