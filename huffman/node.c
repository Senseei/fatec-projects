#include <stdio.h>
#include <stdlib.h>
#include "node.h"

node *new_node(char character) {
    node *n = (node*) malloc(sizeof(node));

    if (n == NULL) {
        return NULL;
    }

    n->character = character;
    n->frequence = 1;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void print_tree(node *root, int level) {
    if (root == NULL)
        return;
    print_tree(root->right, level + 1);

    for (int i = 0; i < level; i++)
        printf("  ");
    printf("(%c->%d)\n", root->character, root->frequence);

    print_tree(root->left, level + 1);
}

void free_tree(node *root) {
    if (root == NULL)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}