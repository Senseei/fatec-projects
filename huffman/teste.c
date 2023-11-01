#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
}
node;

void sort(node *root);
void free_list(node *root);
void print_list(node *root);

int main(void) {
    node *root, *temp;

    for (int i = 4; i >= 0; i--) {
        node *n = (node*) malloc(sizeof(node));
        if (n == NULL) {
            free_list(root);
            return -1;
        }
        n->value = i;
        n->next = NULL;

        if (i == 4) {
            root = n;
            temp = n;
        }
        else {
            temp->next = n;
            temp = n;
        }
    }
    print_list(root);
    sort(root);
    printf("\n");
    print_list(root);
    free_list(root);
}

void sort(node *root) {
    int changes;
    do {
        changes = 0;
        for (node *n = root; n->next != NULL; n = n->next) {
            if (n->value > n->next->value) {
                int temp = n->value;
                n->value = n->next->value;
                n->next->value = temp;
                changes++;
            }
        }
    } while (changes > 0);
}

void print_list(node *root) {
    if (root == NULL)
        return;
    printf("%d,", root->value);
    print_list(root->next);
}

void free_list(node *root) {
    if (root == NULL)
        return;
    free_list(root->next);
    free(root);
}