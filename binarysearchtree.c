#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "binarysearchtree.h"

tree_node* _find_minimum(tree_node* root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left != NULL) {
        return _find_minimum(root->left);
    }

    return root;
}

tree_node* _search(tree_node* root, void* data, int (*compar)(const void *, const void*)) {
    if (root == NULL || (*compar)(root->data, data) == 0) {
        return root;
    } else if ((*compar)(root->data, data) < 0) {
        return _search(root->right, data, (*compar));
    } else {
        return _search(root->left, data, (*compar));
    }
}

tree_node* search(bst* tree, void* data, int (*compar)(const void *, const void*)) {
    return _search(tree->root, data, (*compar));
}

tree_node* _delete(tree_node* root, void* data, size_t size, int (*compar)(const void *, const void*)) {
    if (root == NULL) {
        return NULL;
    }
    
    if ((*compar)(root->data, data) < 0) {
        memcpy(root->right, _delete(root->right, data, size, (*compar)), size);
    } else if ((*compar)(root->data, data) > 0) {
        memcpy(root->left, _delete(root->left, data, size, (*compar)), size);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root->data);
            free(root);
            return NULL;   
        } else if (root->left == NULL || root->right == NULL) {
            tree_node* temp;
            if (root->left == NULL) {
                temp = root->right;
                free(root->right);
            } else {
                temp = root->left;
                free(root->left);
            }

            free(root->data);
            free(root);
            return temp;
        } else {
            tree_node* temp = _find_minimum(root->right);
            temp->data = malloc(sizeof(size));
            memcpy(temp->data, root->data, size);
            root->right = _delete(root->right, temp->data, size, (*compar));
        }
    }
}

tree_node* delete(bst* tree, void* data, size_t size, int (*compar)(const void *, const void*)) {
    return _delete(tree->root, data, size, (*compar));
}

tree_node* _insert(tree_node* root, void* data, size_t size, int (*compar)(const void *, const void*)) {
    if (root == NULL) {
        tree_node* new = malloc(sizeof(tree_node));
        new->data = malloc(sizeof(data));
        memcpy(new->data, data, size);
        return new;
    } else if ((*compar)(root->data, data) < 0) {
        _insert(root->right, data, size, (*compar));
    } else {
        _insert(root->left, data, size, (*compar));
    }

    return root;
}

tree_node* insert(bst* tree, void* data, size_t size, int (*compar)(const void *, const void*)) {
    return _insert(tree->root, data, size, (*compar));
}

void** _inorder(tree_node* root, size_t size, int num_elems) {
    return NULL;
}

void** inorder(bst* tree, size_t size) {
    return _inorder(tree->root, size, tree->size);
}