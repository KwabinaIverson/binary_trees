#include "binary_trees.h"

/**
 *  inorderTraversal - use inorder traversal to delete binary tree
 *  @root: root node of tree
 *  Return: nothing
 */
void inorderTraversal(binary_tree_t *root)
{
	if (root == NULL)
		return;

	inorderTraversal(root->left);
	free(root);
	inorderTraversal(root->right);
}

/**
 * binary_tree_delete - deletes a binary tree
 * @tree: binary tree to delete
 * Return: nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	inorderTraversal(tree);
}
