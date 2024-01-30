#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure the size
 *
 * Return: If tree is NULL, the function must return 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t lft = 0;

	if (tree)
	{
		lft += 1;
		lft += binary_tree_size(tree->left);
		lft += binary_tree_size(tree->right);
	}
	return (lft);
}
