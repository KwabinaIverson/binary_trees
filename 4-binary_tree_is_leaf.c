#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if node is a leaf in BT
 * @node: node to check
 * Return: 1 if node is a leaf, 0 otherwise
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	/* Store value of node we want to find */
	const binary_tree_t *tmp;

	if (node == NULL)
		return (0);

	tmp = node;

	/* Traverse BT looking for node */
	/* If true, look for children */
	/* If true, return 0 */
	binary_tree_is_leaf(node->left);
	if (node == tmp)
	{
		if (node->left != NULL || node->right != NULL)
			return (0);
	}
	binary_tree_is_leaf(node->right);

	return (1);
}
