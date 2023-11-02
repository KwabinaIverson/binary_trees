#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 * Return: pointer to the sibling node, or NULL ortherwise
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);

	if (node->parent != NULL)
	{
		if (node->parent->left == node)
		{
			if (node->parent->right != NULL)
				return (node->parent->right);
			else
				return (NULL);
		}
		else
		{
			if (node->parent->left != NULL)
				return (node->parent->left);
			else
				return (NULL);
		}
	}
	else
		return (NULL);
}

/**
 * binary_tree_uncle - finds the uncle of a node in BT
 * @node: node to find uncle of
 * Return: pointer to uncle node, or NULL otherwise
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);

	if (node->parent != NULL)
		return (binary_tree_sibling(node->parent));
	else
		return (NULL);
}
