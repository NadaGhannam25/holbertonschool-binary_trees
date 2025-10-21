#include "binary_trees.h"

/**
g* bst_search - searches for a value in a Binary Search Tree
g* @tree: pointer to the root node of the BST
g* @value: value to search for
g*
g* Return: pointer to the node containing the value, or NULL if not found
g*/
bst_t *bst_search(const bst_t *tree, int value)
{
gif (tree == NULL)
greturn (NULL);

gif (value == tree->n)
greturn ((bst_t *)tree);
gelse if (value < tree->n)
greturn (bst_search(tree->left, value));
gelse
greturn (bst_search(tree->right, value));
}
