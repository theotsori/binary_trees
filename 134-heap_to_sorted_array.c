#include "binary_trees.h"

/**
 * heap_size - Computes the number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: The number of nodes in the tree
 */
size_t heap_size(const heap_t *tree)
{
	if (!tree)
		return (0);

	return (1 + heap_size(tree->left) + heap_size(tree->right));
}

/**
 * heapify_down - Maintains the Max Heap property by swapping
 * nodes down the tree as necessary
 * @heap: Pointer to the root node of the heap
 */
void heapify_down(heap_t *heap)
{
	heap_t *largest = heap;

	if (heap->left && heap->left->n > largest->n)
		largest = heap->left;

	if (heap->right && heap->right->n > largest->n)
		largest = heap->right;

	if (largest != heap)
	{
		int temp = heap->n;

		heap->n = largest->n;
		largest->n = temp;
		heapify_down(largest);
	}
}

/**
 * heap_to_sorted_array - Converts a Max Binary Heap to a sorted array of ints
 * @heap: Pointer to the root node of the heap
 * @size: Address to store the size of the array
 * Return: A pointer to the sorted array of ints, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t i;

	if (!heap || !size)
		return (NULL);

	*size = heap_size(heap);
	array = malloc(*size * sizeof(int));
	if (!array)
		return (NULL);

	for (i = 0; i < *size; i++)
	{
		array[i] = heap->n;
		if (i == *size - 1)
			break;
		heap->n = heap->parent->n;
		if (heap->parent->left == heap)
			heap->parent->left = NULL;
		else
			heap->parent->right = NULL;
		heapify_down(heap);
		while (heap->parent && !heap->left && !heap->right)
			heap = heap->parent;
		if (heap->right)
			heap = heap->right;
		else
			heap = heap->left;
	}

	return (array);
}
