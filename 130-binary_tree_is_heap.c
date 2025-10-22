#include "binary_trees.h"

/**
* count_nodes - Counts the number of nodes in a binary tree
* @tree: Pointer to the root node of the tree
* Return: Total number of nodes
*/
size_t count_nodes(const binary_tree_t *tree)
{
if (!tree)
return (0);
return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
* is_complete - Checks if a binary tree is complete
* @tree: Pointer to the root node
* @index: Current index assigned to node (like heap array index)
* @size: Total number of nodes in the tree
* Return: 1 if complete, 0 otherwise
*/
int is_complete(const binary_tree_t *tree, size_t index, size_t size)
{
if (!tree)
return (1);

if (index >= size)
return (0);

return (is_complete(tree->left, 2 * index + 1, size) &&
is_complete(tree->right, 2 * index + 2, size));
}

/**
* is_max_heap - Checks if the tree satisfies the Max Heap property
* @tree: Pointer to the root node
* Return: 1 if max heap, 0 otherwise
*/
int is_max_heap(const binary_tree_t *tree)
{
if (!tree)
return (1);

if (tree->left && tree->left->n > tree->n)
return (0);
if (tree->right && tree->right->n > tree->n)
return (0);

return (is_max_heap(tree->left) && is_max_heap(tree->right));
}

/**
* binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
* @tree: Pointer to the root node
* Return: 1 if valid Max Binary Heap, 0 otherwise
*/
int binary_tree_is_heap(const binary_tree_t *tree)
{
size_t size;

if (!tree)
return (0);

size = count_nodes(tree);

if (!is_complete(tree, 0, size))
return (0);

if (!is_max_heap(tree))
return (0);

return (1);
}

