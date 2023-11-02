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
