#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: The first pointer
 * @second: Second node pointer
 * Return: lowest common ancestor
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *) first);

	if (binary_tree_is_descendant(first, second))
		return ((binary_tree_t *) first);

	if (binary_tree_is_descendant(second, first))
		return ((binary_tree_t *) second);

	return (binary_trees_ancestor(first->parent, second->parent));
}

/**
 * binary_tree_is_descendant - finds the parent of the nodes
 * @first: The first pointer
 * @second: Second node pointer
 * Return: The descendant of a node
*/
int binary_tree_is_descendant(const binary_tree_t *first,
const binary_tree_t *second)
{
	if (first == NULL)
		return (0);

	if (first == second)
		return (1);

	return (binary_tree_is_descendant(first->left, second)
			|| binary_tree_is_descendant(first->right, second));
}
