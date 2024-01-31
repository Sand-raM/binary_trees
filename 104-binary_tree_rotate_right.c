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

	if (tree == NULL)
		return (NULL);
	if (tree->left)
	{
		pivot = tree->left->right;
		auxi = tree->left;
		auxi->parent = tree->parent;
		auxi->right = tree;
		tree->parent = auxi;
		tree->left = pivot;
		if (pivot)
			temp->parent = tree;
		return (auxi);
	}
	return (NULL);
}
