#include "binary_trees.h"

/**
* bst_search - searches for a value in a BST
* @tree: pointer to root node
* @value: value to search
* Return: pointer to found node, or NULL
*/
bst_t *bst_search(const bst_t *tree, int value)
{
if (tree == NULL)
return (NULL);

if (value == tree->n)
return ((bst_t *)tree);

if (value < tree->n)
return (bst_search(tree->left, value));
else
return (bst_search(tree->right, value));
}

