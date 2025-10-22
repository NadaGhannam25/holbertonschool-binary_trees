#include "binary_trees.h"

/**
* avl_find_min - Finds the minimum value node in an AVL tree
*
* @node: Pointer to the root node of the subtree
*
* Return: Pointer to the minimum value node
*/
avl_t *avl_find_min(avl_t *node)
{
while (node && node->left)
node = node->left;
return (node);
}

/**
* avl_remove - Removes a node from an AVL tree
*
* @root: Pointer to the root node of the tree
* @value: Value to remove
*
* Return: Pointer to the new root node after removal and rebalancing
*/
avl_t *avl_remove(avl_t *root, int value)
{
if (!root)
return (NULL);

if (value < root->n)
{
root->left = avl_remove(root->left, value);
if (root->left)
root->left->parent = root;
}
else if (value > root->n)
{
root->right = avl_remove(root->right, value);
if (root->right)
root->right->parent = root;
}
else
{
if (!root->left || !root->right)
{
avl_t *child = root->left ? root->left : root->right;
if (child)
child->parent = root->parent;
free(root);
return (child);
}
else
{
avl_t *successor = avl_find_min(root->right);
root->n = successor->n;
root->right = avl_remove(root->right, successor->n);
if (root->right)
root->right->parent = root;
}
}

/* Balance the tree */
int bf = binary_tree_balance(root);
if (bf > 1)
{
if (binary_tree_balance(root->left) < 0)
{
root->left = binary_tree_rotate_left(root->left);
if (root->left)
root->left->parent = root;
}
return (binary_tree_rotate_right(root));
}
else if (bf < -1)
{
if (binary_tree_balance(root->right) > 0)
{
root->right = binary_tree_rotate_right(root->right);
if (root->right)
root->right->parent = root;
}
return (binary_tree_rotate_left(root));
}
return (root);
}

