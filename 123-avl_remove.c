#include "binary_trees.h"

/**
 * find_successor - Finds the in-order successor of a node.
 * @node: Pointer to the node whose successor is to be found.
 *
 * Return: Pointer to the successor node.
 */
avl_t *find_successor(avl_t *node)
{
	while (node && node->left)
		node = node->left;
	return (node);
}

/**
 * avl_remove - Removes a node from an AVL tree and rebalances it.
 * @root: Pointer to the root node of the tree.
 * @value: Value to remove from the tree.
 *
 * Return: Pointer to the new root node after removal and rebalancing.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *tmp;
	int balance;

	if (!root)
		return (NULL);

	/* Step 1: Perform standard BST deletion */
	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		/* Node found */
		if (!root->left || !root->right)
		{
			tmp = root->left ? root->left : root->right;
			free(root);
			return (tmp);
		}
		tmp = find_successor(root->right);
		root->n = tmp->n;
		root->right = avl_remove(root->right, tmp->n);
	}

	if (!root)
		return (NULL);

	/* Step 2: Rebalance the node */
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

