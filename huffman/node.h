#ifndef NODE_H
#define NODE_H

typedef struct node {
    char character;
    int frequency;
    struct node *left;
    struct node *right;
}
node;

node *new_node(char character);
void print_tree(node *root, int level);
void free_tree(node *root);
bool equals(node *root1, node *root2);

#endif