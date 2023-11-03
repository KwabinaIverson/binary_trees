#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height og tree on success, 0 on failure
 */
size_t binary_tree_height(const binary_tree_t *tree)
{

	size_t height_l, height_r;

	if (tree == NULL)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 1;

	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to root node of tree
 * Return: balance factor of tree, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int height_l, height_r;

	if (tree == NULL)
		return (0);

	height_l = (int)binary_tree_height(tree->left);
	height_r = (int)binary_tree_height(tree->right);

	return (height_l - height_r);
}

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree
 * Return: Number of nodes with at least 1 child in a binary tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree == NULL)
		return (0);

	if ((tree->left != NULL && tree->right == NULL) ||
		(tree->left == NULL && tree->right != NULL))
		count++;

	/* count left/right sub-tree */
	count += binary_tree_nodes(tree->left);
	count += binary_tree_nodes(tree->right);

	return (count);
}

/**
 * b_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree
 * Return: 1 if leaf is on last level, or 0 otherwise
 */
size_t b_tree_leaves(const binary_tree_t *tree, size_t tree_height)
{
	size_t leaves_count = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
	{
		if (tree_height - binary_tree_height(tree) == tree_height)
			leaves_count = 0;
		else
			return (1);
	}

	leaves_count = b_tree_leaves(tree->left, tree_height);
	leaves_count = b_tree_leaves(tree->right, tree_height);

	return (leaves_count);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to root node of tree
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t i;

	if (tree == NULL)
		return (0);

	i = binary_tree_nodes(tree);
	if (i > 0)
		return (0);

	/*Check if balance factor (BF) of tree is == 0 */
	/* If FALSE, tree is not perfect*/
	/* binary_tree_height makes sure leaf node is on the last level */
	if ((binary_tree_balance(tree) == 0) &&
		(b_tree_leaves(tree, binary_tree_height(tree)) == 0))
		return (1);
	else
		return (0);

	return (1);
}
