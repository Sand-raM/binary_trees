#include "binary_trees.h"

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: double pointer to the root node of the Heap to insert the value
 * @value: the value to store in the node to be inserted
 * Return: pointer to the created node, NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *ptr, *lip;
	int size, sl, sub, byt, level, tmp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	sl = size;
	for (level = 0, sub = 1; sl >= sub; sub *= 2, level++)
		sl -= sub;

	for (byt = 1 << (level - 1); byt != 1; byt >>= 1)
		tree = sl & byt ? tree->right : tree->left;

	ptr = binary_tree_node(tree, value);
	sl & 1 ? (tree->right = ptr) : (tree->left = ptr);

	lip = ptr;
	for (; lip->parent && (lip->n > lip->parent->n); lip = lip->parent)
	{
		tmp = lip->n;
		lip->n = lip->parent->n;
		lip->parent->n = tmp;
		ptr = ptr->parent;
	}

	return (ptr);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: the tree to measure the size of
 *
 * Return: size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
