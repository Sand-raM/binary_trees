#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return:  pointer to the lowest common ancestor node,
 * of the two given nodes, else NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *tmp, *ptr;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	tmp = first->parent, ptr = second->parent;
	if (first == ptr || !tmp || (!tmp->parent && ptr))
		return (binary_trees_ancestor(first, ptr));
	else if (tmp == second || !ptr || (!ptr->parent && tmp))
		return (binary_trees_ancestor(tmp, second));
	return (binary_trees_ancestor(tmp, ptr));
}
