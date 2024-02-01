#include "binary_trees.h"

/**
 * find_node - finds node in a tree
 * @root: root of the tre to evaluate
 * @node: node to find
 * Return: 1 if it exits 0 if it doesnot
 */
int find_node(binary_tree_t *root, binary_tree_t *node)
{

	if (root == NULL)
		return (0);
	if (node == root)
		return (1);
	if (node->n < root->n)
		return (find_node(root->left, node));
	if (node->n > root->n)
		return (find_node(root->right, node));
	return (0);
}

/**
 * croos_tree - Cross the tree checking if each node exist correctly
 * @root: root node of the tree
 * @node: the current node to evaluate
 * Return: 1 if is BST0 if no
 */
int croos_tree(binary_tree_t *root, binary_tree_t *node)
{
	if (root && node)
	{
		int ptr = 0;

		ptr = find_node(root, node);
		if (node->left)
			ptr &= croos_tree(root, node->left);
		if (node->right)
			ptr &= croos_tree(root, node->right);
		return (ptr);
	}
	return (0);
}

/**
 * binary_tree_is_bst - Checks if ist a correctly bst tree
 * @tree: tree to check
 * Return: 1 if is bst 0 if it is not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (croos_tree((binary_tree_t *)tree, (binary_tree_t *)tree));
}
