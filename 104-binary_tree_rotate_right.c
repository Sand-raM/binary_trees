#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *auxi, *pivot;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	auxi = tree->left;
	pivot = auxi->right;
	auxi->right = tree;
	tree->left = pivot;
	if (pivot != NULL)
		pivot->parent = tree;
	pivot = tree->parent;
	tree->parent = auxi;
	auxi->parent = pivot;
	if (pivot != NULL)
	{
		if (pivot->left == tree)
			pivot->left = auxi;
		else
			pivot->right = auxi;
	}
	return (pivot);
}
