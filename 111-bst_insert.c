#include "binary_trees.h"

/**
* bst_insert - inserts a value in a Binary Search Tree
* @tree: double pointer to root node
* @value: value to insert
* Return: pointer to created node, or NULL on failure
*/
bst_t *bst_insert(bst_t **tree, int value)
{
bst_t *new, *temp;

if (tree == NULL)
return (NULL);

if (*tree == NULL)
{
new = binary_tree_node(NULL, value);
*tree = new;
return (new);
}

temp = *tree;
while (temp)
{
if (value < temp->n)
{
if (temp->left == NULL)
{
temp->left = binary_tree_node(temp, value);
return (temp->left);
}
temp = temp->left;
}
else if (value > temp->n)
{
if (temp->right == NULL)
{
temp->right = binary_tree_node(temp, value);
return (temp->right);
}
temp = temp->right;
}
else
return (NULL);
}

return (NULL);
}

