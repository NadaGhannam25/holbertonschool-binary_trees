#include "binary_trees.h"

/**
* binary_tree_rotate_right - Performs a right rotation on a binary tree
* @tree: Pointer to the root node of the tree to rotate
*
* Return: Pointer to the new root node of the tree once rotated
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
binary_tree_t *new_root;

if (tree == NULL || tree->left == NULL)
return (NULL);

new_root = tree->left;       /* Step 1: new root becomes the left child */
tree->left = new_root->right; /* Step 2: move new_root’s right subtree */

if (new_root->right)
new_root->right->parent = tree; /* Step 3: update parent of moved node */

new_root->right = tree;       /* Step 4: old root becomes right child */
new_root->parent = tree->parent; /* Step 5: new root inherits parent */
tree->parent = new_root;      /* Step 6: update parent pointer */

return (new_root);            /* Step 7: return new root */
}
