#include "binary_trees.h"

/**
 * binary_tree_insert_right -  inserts node as the right-child of another node
 * @parent: a pointer to the node to insert the right-child in
 * @value: the value to store in the new node
 * Return: the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_node;

	if (parent == NULL)
		return (NULL);

	right_node = malloc(sizeof(binary_tree_t));
	if (right_node == NULL)
		return (NULL);

	right_node->n = value;
	right_node->parent = parent;
	right_node->right = parent->right;
	right_node->right = NULL;

	if (parent->right != NULL)
		parent->right->parent = right_node;

	parent->right = right_node;

	return (right_node);
}
