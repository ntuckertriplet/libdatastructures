#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "binarysearchtree.h"

/**
 * A helper method for binary search trees that 
 * will find the minimum value node in a tree
 * 
 * @param root the struct root of a binary search tree
 * 
 * @returns the minimum value node in the binary search tree
 */
tree_node* _find_minimum(tree_node* root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left != NULL) {
        return _find_minimum(root->left);
    }

    return root;
}

/**
 * Recursive search method for a binary search tree
 * @param root the root node of the binary search tree
 * @param data the void * data to search for
 * @param compar a custom comparator to be passed in.
 *               format for comparators can be found in comparator.c
 * 
 * @returns a tree node with the value that equals the passed in data.
 * NOTE: this will return the FIRST occurrence of the data, not all, not the last
 */ 
tree_node* _search(tree_node* root, void* data, int (*compar)(const void *, const void*)) {
    if (root == NULL || (*compar)(root->data, data) == 0) {
        return root;
    } else if ((*compar)(root->data, data) < 0) {
        return _search(root->right, data, (*compar));
    } else {
        return _search(root->left, data, (*compar));
    }
}

/**
 * Search method for a binary search tree
 * @param tree the tree you would like to search in
 * @param data the void * data to search for
 * @param compar a custom comparator to be passed in.
 *               format for comparators can be found in comparator.c
 * 
 * @returns a tree node with the value that equals the passed in data.
 * NOTE: this will return the FIRST occurrence of the data, not all, not the last
 * NOTE: this will call _search, a helper, recursive method to search properly
 */ 
tree_node* search(bst* tree, void* data, int (*compar)(const void *, const void*)) {
    return _search(tree->root, data, (*compar));
}

/**
 * Recursive method that deletes a node that contains the particluar data passed in
 * @param root the root node of the binary search tree
 * @param data the void * data to delete from the tree
 * @param compar a custom comparator to be passed in.
 *               format for comparators can be found in comparator.c
 * 
 * @returns a deleted tree node with the value that equals the passed in data.
 * NOTE: this will delete the FIRST occurrence of the data, not all.
 *       repeat calls to _delete are required if you want to delete every occurrence of the data
 */ 
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

/**
 * Method that deletes a node that contains the particluar data passed in
 * @param tree the bst that you wish to remove the data from
 * @param data the void * data to delete from the tree
 * @param compar a custom comparator to be passed in.
 *               format for comparators can be found in comparator.c
 * 
 * @returns a deleted tree node with the value that equals the passed in data.
 * NOTE: this will delete the FIRST occurrence of the data, not all.
 *       repeat calls to delete are required if you want to delete every occurrence of the data
 * NOTE: this will call the helper _delete method to recurse through the tree
 */ 
tree_node* delete(bst* tree, void* data, size_t size, int (*compar)(const void *, const void*)) {
    tree->size--;
    return _delete(tree->root, data, size, (*compar));
}

/**
 * Recursive method that inserts a node in the binary search tree
 * @param root the root node of the tree that you wish to add to
 * @param data the void * data to add to the tree
 * @param compar a custom comparator to be passed in.
 *               format for comparators can be found in comparator.c
 * 
 * @returns an added tree node with the value that equals the passed in data.
 */ 
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

/**
 * Method that inserts a node in the binary search tree
 * @param tree the binary search tree that you wish to add to
 * @param data the void * data to add to the tree
 * @param compar a custom comparator to be passed in.
 *               format for comparators can be found in comparator.c
 * 
 * @returns an added tree node with the value that equals the passed in data.
 * NOTE: this will call the helper _insert method to recurse through the tree
 */ 
tree_node* insert(bst* tree, void* data, size_t size, int (*compar)(const void *, const void*)) {
    tree->size++;
    return _insert(tree->root, data, size, (*compar));
}

/**
 * TODO Recursive method that does an inorder traversal of the tree
 * @param root the root node of the bst that you wish to yield data from
 * @param size the size_t of the data in the tree
 * @param num_elems the number of nodes in the tree
 * 
 * @returns a *void[] containing all the data of the tree inorder
 */ 
void** _inorder(tree_node* root, size_t size, int num_elems) {
    return NULL;
}

/**
 * TODO Method that does an inorder traversal of the tree
 * @param root the root node of the bst that you wish to yield data from
 * @param size the size_t of the data in the tree
 * 
 * @returns a *void[] containing all the data of the tree inorder
 */ 
void** inorder(bst* tree, size_t size) {
    return _inorder(tree->root, size, tree->size);
}