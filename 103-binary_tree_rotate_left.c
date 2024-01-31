#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *auxi, *pivot;

	if (tree == NULL)
		return (NULL);
	if (tree->right)
	{
		pivot = tree->right->left;
		auxi = tree->right;
		auxi->parent = tree->parent;
		auxi->left = tree;
		tree->parent = auxi;
		tree->right = pivot;
		if (pivot)
			pivot->parent = tree;
		return (auxi);
	}
	return (NULL);
}
