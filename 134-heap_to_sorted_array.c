#include "binary_trees.h"

/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted array
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 *
 * Return: pointer to the sorted array, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array, temp;
	size_t i;

	if (heap == NULL || size == NULL)
		return (NULL);

	*size = binary_tree_size(heap);
	array = malloc(*size * sizeof(int));
	if (array == NULL)
		return (NULL);

	for (i = 0; i < *size; i++)
	{
		array[i] = heap_extract(&heap);
		if (array[i] == 0)
		{
			free(array);
			return (NULL);
		}
	}

	for (i = 0; i < *size / 2; i++)
	{
		temp = array[i];
		array[i] = array[*size - i - 1];
		array[*size - i - 1] = temp;
	}

	return (array);
}
