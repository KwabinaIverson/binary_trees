#include "binary_trees.h"

/**
 * binary_tree_insert_left - node of a binary tree
 * @parent: points to the parent node of current node
 * @value: value to be stored in BT node
 * Return: pointer to new node created, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	/* If parent node is empty */
	if (parent == NULL)
		return NULL;

	binary_tree_t *node = malloc(sizeof(binary_tree_t));
	binary_tree_t *tmp = malloc(sizeof(binary_tree_t));

	if (node == NULL || tmp == NULL)
		return (NULL);

	/* create new node called tmp */
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	/* Insert node as left child of parent if empty */
	if (parent->left == NULL)
		parent->left = node;
	else
	{
		/* tmp holds left child of parent */
		/* node created gets set to be the new left child of parent */
		/* old left child of parent (tmp) becomes left child of node */
		tmp->n = parent->left->n;
		tmp->left = NULL;
		tmp->right = NULL;
		tmp->parent = node;

		parent->left = node;
		node->left = tmp;
	}

	return (node);
}
