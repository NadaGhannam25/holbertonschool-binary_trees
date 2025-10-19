#include <stdio.h>
#include "binary_trees.h"

/* Helper function to print the tree structure */
static void print_tree(const binary_tree_t *tree, int space)
{
int COUNT = 5;
int i;

if (tree == NULL)
return;

space += COUNT;

print_tree(tree->right, space);

printf("\n");
for (i = COUNT; i < space; i++)
printf(" ");
printf("%d\n", tree->n);

print_tree(tree->left, space);
}

/* Main function to be called externally */
void binary_tree_print(const binary_tree_t *tree)
{
print_tree(tree, 0);
}
