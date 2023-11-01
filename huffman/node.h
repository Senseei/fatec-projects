#ifndef NODE_H
#define NODE_H

typedef struct node {
    char character;
    int frequence;
    struct node *left;
    struct node *right;
}
node;

node *new_node(char character);
void print_tree(node *root, int level);
void free_tree(node *root);

#endif