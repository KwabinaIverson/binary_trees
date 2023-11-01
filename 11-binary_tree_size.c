#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: height og tree on success, 0 on failure
 */
size_t binary_tree_size(const binary_tree_t *tree)
{

	size_t height_l, height_r;

	if (tree == NULL)
		return (0);

	/* size of tree is sum of heights */
	height_l = binary_tree_size(tree->left);
	height_r = binary_tree_size(tree->right);

	return (height_l + height_r + 1);
}
