#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include "node.h"

node *new_node(char character) {
    node *n = (node*) malloc(sizeof(node));

    if (n == NULL) {
        return NULL;
    }

    n->character = character;
    n->frequency = 1;
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
    printf("(%c->%d)\n", root->character, root->frequency);

    print_tree(root->left, level + 1);
}

void free_tree(node *root) {
    if (root == NULL)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

bool equals(node *root1, node *root2) {
    if (root1 == root2)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    if (root1->character != root2->character || root1->frequency != root2->frequency)
        return false;

    return equals(root1->left, root2->left) && equals(root1->right, root2->right);
}