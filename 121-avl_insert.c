#include "binary_trees.h"

/**
* avl_insert - temporary AVL insert for testing
* @tree: double pointer to root
* @value: value to insert
* Return: pointer to node inserted
*/
avl_t *avl_insert(avl_t **tree, int value)
{
if (!tree)
return (NULL);

if (*tree == NULL)
*tree = binary_tree_node(NULL, value);
return (*tree);
}

/**
* array_to_avl - builds AVL tree from array
* @array: array of integers
* @size: array size
* Return: pointer to root
*/
avl_t *array_to_avl(int *array, size_t size)
{
size_t i;
avl_t *root = NULL;

if (!array || size == 0)
return (NULL);

for (i = 0; i < size; i++)
avl_insert(&root, array[i]);

return (root);
}

