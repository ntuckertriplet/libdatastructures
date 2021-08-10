#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

typedef struct tree_node
{
    struct tree_node *left;
    struct tree_node *right;
    void *data;
} tree_node;

typedef struct bst
{
    tree_node *root;
    int size;
} bst;

tree_node *search(bst *tree, void *data, int (*compar)(const void *, const void *));
tree_node *delete (bst *tree, void *data, size_t size, int (*compar)(const void *, const void *));
tree_node *insert(bst *tree, void *data, size_t size, int (*compar)(const void *, const void *));
void **inorder(bst *tree, size_t size);

#endif