#include "binary_trees.h"

/**
* sorted_array_to_avl_rec - Recursive helper to build AVL from sorted array
* @array: Pointer to the array of integers
* @start: Start index of the current subarray
* @end: End index of the current subarray
* 
* Return: Pointer to the root of the subtree
*/
static avl_t *sorted_array_to_avl_rec(int *array, int start, int end)
{
int mid;
avl_t *node;

if (start > end)
return (NULL);

mid = (start + end) / 2;
node = binary_tree_node(NULL, array[mid]);
if (!node)
return (NULL);

node->left = sorted_array_to_avl_rec(array, start, mid - 1);
if (node->left)
node->left->parent = node;

node->right = sorted_array_to_avl_rec(array, mid + 1, end);
if (node->right)
node->right->parent = node;

return (node);
}

/**
* sorted_array_to_avl - Builds an AVL tree from a sorted array
* @array: Pointer to the array of integers
* @size: Number of elements in the array
* 
* Return: Pointer to the root of the created AVL tree
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
if (!array || size == 0)
return (NULL);

return (sorted_array_to_avl_rec(array, 0, (int)size - 1));
}

