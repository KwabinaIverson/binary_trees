#include "binary_trees.h"

/**
 * binary_tree_delete - deletes a binary tree
 * @tree: binary tree to delete
 * Return: nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	else
	{
		binary_tree_delete(tree->left);
		free(tree);
		binary_tree_delete(tree->right);
	}
}
