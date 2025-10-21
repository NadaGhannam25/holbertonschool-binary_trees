#include "binary_trees.h"

/**
* max - Returns the maximum of two integers
* @a: first integer
* @b: second integer
* Return: the larger integer
*/
static int max(int a, int b)
{
return (a > b ? a : b);
}

/**
* avl_insert_node - helper function to insert like BST and balance
* @node: current root
* @parent: parent of current node
* @value: value to insert
* Return: pointer to new node or existing node
*/
static avl_t *avl_insert_node(avl_t *node, avl_t *parent, int value)
{
int balance;

if (!node)
{
avl_t *new = binary_tree_node(parent, value);
return (new);
}

if (value < node->n)
node->left = avl_insert_node(node->left, node, value);
else if (value > node->n)
node->right = avl_insert_node(node->right, node, value);
else
return (node); 

balance = binary_tree_balance(node);


if (balance > 1)
{
if (value < node->left->n)
return (binary_tree_rotate_right(node)); 
else
{
node->left = binary_tree_rotate_left(node->left); 
return (binary_tree_rotate_right(node));
}
}


if (balance < -1)
{
if (value > node->right->n)
return (binary_tree_rotate_left(node)); 
else
{
node->right = binary_tree_rotate_right(node->right); 
return (binary_tree_rotate_left(node));
}
}

return (node);
}

/**
* avl_insert - Inserts a value in an AVL tree
* @tree: double pointer to the root of the AVL tree
* @value: value to insert
* Return: pointer to the created node, or NULL on failure
*/
avl_t *avl_insert(avl_t **tree, int value)
{
avl_t *new_node = NULL;

if (!tree)
return (NULL);

if (!*tree)
{
*tree = binary_tree_node(NULL, value);
return (*tree);
}

*tree = avl_insert_node(*tree, NULL, value);


new_node = *tree;
while (new_node && new_node->n != value)
{
if (value < new_node->n)
new_node = new_node->left;
else
new_node = new_node->right;
}

return (new_node);
}

/**
* array_to_avl - builds an AVL tree from an array
* @array: pointer to the array of integers
* @size: number of elements in the array
* Return: pointer to root of AVL tree, or NULL on failure
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
