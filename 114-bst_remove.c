#include "binary_trees.h"

/**
* bst_minimum - Finds the node with the minimum value in a BST
* @node: Pointer to the root node of the tree
* Return: Pointer to the node with the minimum value
*/
bst_t *bst_minimum(bst_t *node)
{
if (node == NULL)
return (NULL);
while (node->left != NULL)
node = node->left;
return (node);
}

/**
* bst_remove - Removes a node from a Binary Search Tree
* @root: Pointer to the root node of the tree
* @value: Value to remove in the tree
* Return: Pointer to the new root node after removal
*/
bst_t *bst_remove(bst_t *root, int value)
{
bst_t *temp = NULL;

if (root == NULL)
return (NULL);

if (value < root->n)
root->left = bst_remove(root->left, value);

else if (value > root->n)
root->right = bst_remove(root->right, value);

else
{
if (root->left == NULL)
{
temp = root->right;
if (temp)
temp->parent = root->parent;
free(root);
return (temp);
}

else if (root->right == NULL)
{
temp = root->left;
if (temp)
temp->parent = root->parent;
free(root);
return (temp);
}

else
{
temp = bst_minimum(root->right);
root->n = temp->n;
root->right = bst_remove(root->right, temp->n);
}
}

return (root);
}

