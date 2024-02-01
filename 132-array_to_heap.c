#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: pointer to the root node of the created Binary Heap,
 * or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int c;
	heap_t *tree = NULL;

	for (c = 0; c < size; c++)
		heap_insert(&tree, array[c]);
	return (tree);
}
