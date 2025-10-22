#include "binary_trees.h"
#include <stdlib.h>

/**
 * find_min - Finds the smallest node (in-order successor)
 * @node: pointer to the node to start from
 * Return: pointer to the node with the minimum value
 */
avl_t *find_min(avl_t *node)
{
	while (node && node->left)
		node = node->left;
	return (node);
}

/**
 * avl_remove - Removes a node from an AVL tree and rebalances it
 * @root: pointer to the root of the AVL tree
 * @value: value to remove
 * Return: pointer to the new root after deletion and rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp;
	int balance;

	if (root == NULL)
		return (NULL);

	/* Step 1: Standard BST delete */
	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		/* Node found */
		if (root->left == NULL || root->right == NULL)
		{
			temp = root->left ? root->left : root->right;
			free(root);
			return (temp);
		}
		else
		{
			temp = find_min(root->right);
			root->n = temp->n;
			root->right = avl_remove(root->right, temp->n);
		}
	}

	if (root == NULL)
		return (NULL);

	/* Step 2: Rebalance */
	balance = binary_tree_balance(root);

	/* Left heavy */
	if (balance > 1)
	{
		if (binary_tree_balance(root->left) >= 0)
			return (binary_tree_rotate_right(root));
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}

	/* Right heavy */
	if (balance < -1)
	{
		if (binary_tree_balance(root->right) <= 0)
			return (binary_tree_rotate_left(root));
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}

	return (root);
}

