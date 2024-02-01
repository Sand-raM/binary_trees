#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: if tree is NULL, your function must return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int lft = 0, rgt = 0;

		if (tree->rgt)
			rgt = 1 + binary_tree_height(tree->rgt);
		if (tree->lft)
			lft = 1 + binary_tree_height(tree->lft);
		if (lft > rgt)
			return (lft);
		else
			return (rgt);
	}
	else
		return (0);
}

/**
 * print_at_level - prints node specific level
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * @level: level to print
 */
void print_at_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree && func)
	{
		if (level == 1)
			func(tree->n);
		else
		{
			print_at_level(tree->left, func, level - 1);
			print_at_level(tree->right, func, level - 1);
		}
	}

}

/**
 * binary_tree_levelorder - goes through a binary tree in level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t c = 0, j = 1;

	if (tree && func)
	{
		c = binary_tree_height(tree);
		while (j <= c + 1)
		{
			print_at_level(tree, func, j);
			j++;
		}
	}

}
