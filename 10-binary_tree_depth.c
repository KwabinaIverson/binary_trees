#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in binary tree
 * @tree: pointer to the node to measure the depth
 * Return: height og tree on success, 0 on failure
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{

	size_t node_depth;

	if (tree == NULL)
		return (0);

	node_depth = tree->parent ? 1 + binary_tree_depth(tree->parent) : 0;

	return (node_depth);
}
