#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: a pointer to the root node of the tree to count the number of leaves
 *
 * Return: If tree is NULL, the function must return 0
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t LeaVes = 0;

	if (tree)
	{
		LeaVes += (!tree->left && !tree->right) ? 1 : 0;
		LeaVes += binary_tree_leaves(tree->left);
		LeaVes += binary_tree_leaves(tree->right);
	}
	return (LeaVes);
}
