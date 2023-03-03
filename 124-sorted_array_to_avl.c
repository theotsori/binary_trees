#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 *
 * @array: Pointer to the first element of the array to be converted.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (build_avl_tree(array, 0, size - 1));
}

/**
 * build_avl_tree - Recursively builds an AVL tree from a sorted array.
 *
 * @array: Pointer to the first element of the array to be converted.
 * @start: Index of the first element of the current subtree.
 * @end: Index of the last element of the current subtree.
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *build_avl_tree(int *array, int start, int end)
{
	int mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = binary_tree_node(NULL, array[mid]);
	if (root == NULL)
		return (NULL);

	root->left = build_avl_tree(array, start, mid - 1);
	root->right = build_avl_tree(array, mid + 1, end);
	if (root->left)
		root->left->parent = root;
	if (root->right)
		root->right->parent = root;

	avl_rebalance(&root);

	return (root);
}
