#include "binary_trees.h"

/**
 * max - returns the maximum of two integers
 * @a: first integer
 * @b: second integer
 * Return: maximum of a and b
 */
int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

/**
 * height - measures the height of a binary tree
 * @tree: pointer to the root node
 * Return: height of tree, 0 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * is_bst - checks if a tree is a valid BST within min/max bounds
 * @tree: pointer to the root node
 * @min: minimum allowed value
 * @max: maximum allowed value
 * Return: 1 if BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (is_bst(tree->left, min, tree->n - 1) &&
		is_bst(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree
 * @tree: pointer to the root node
 * Return: 1 if tree is AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	if (!is_bst(tree, -2147483648, 2147483647))
		return (0);

	left_height = (tree->left) ? height(tree->left) : 0;
	right_height = (tree->right) ? height(tree->right) : 0;

	if (abs(left_height - right_height) > 1)
		return (0);

	if (tree->left && !binary_tree_is_avl(tree->left))
		return (0);

	if (tree->right && !binary_tree_is_avl(tree->right))
		return (0);

	return (1);
}
