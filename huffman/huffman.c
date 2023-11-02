#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "node.h"
#include "queue.h"

node *build_tree(FILE *arq);
void serialize_tree(node *root);
node *deserialize_tree(const char *serial, int* index);
void free_frequencies(node *arr[], int length);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Invalid arguments.\n");
        printf("usage: ./huffman file_name\n");
        printf("file_name must not have the extension, just the name of the file");
        return -1;
    }
    
    char file_name[100];
    if (snprintf(file_name, sizeof(file_name), "%s.txt", argv[1]) >= sizeof(file_name)) {
        printf("File name is too long.\n");
        return -1;
    }

    FILE *arq = fopen(file_name, "r");

    if (arq == NULL) {
        printf("Error while opening the file");
        return -1;
    }

    node *tree = build_tree(arq);
    print_tree(tree, 0);
    serialize_tree(tree);
    printf("\n");

    const char *serial = "I10I4Lc1Lb3La6";
    printf("deserialized:\n");
    int index = 0;
    node *dtree = deserialize_tree(serial, &index);
    print_tree(dtree, 0);

    free_tree(tree);
    free_tree(dtree);
    fclose(arq);
}

node *build_tree(FILE *arq) {
    node *frequencies[256] = {NULL};
    int total_nodes = 0;
    char buffer[1];

    while (fread(buffer, sizeof(char), 1, arq) == 1) {
        char character = buffer[0];
        int index = (int) character;

        if (frequencies[index] == NULL) { 
            node *n = new_node(character);

            if (n == NULL) {
                free_frequencies(frequencies, 256);
                return false;
            }

            frequencies[index] = n;
            total_nodes++;
        }
        else
            frequencies[index]->frequency++;
    }

    queue *q = new_queue();

    for (int i = 0, next = 0; i < 256; i++) {
        if (frequencies[i] != NULL) {
            enqueue(q, frequencies[i]);
        }
    }
    sort_queue(q);

    while (q->size != 1) {
        node *n1 = dequeue(q);
        node *n2 = dequeue(q);

        node *n = new_node(0);
        n->frequency = n1->frequency + n2->frequency;

        n->left = n1;
        n->right = n2;

        enqueue(q, n);
        sort_queue(q);
    }

    node *tree = dequeue(q);
    free_queue(q);
    
    return tree;
}

void serialize_tree(node *root) {
    if (root->left == NULL && root->right == NULL) {
        printf("L");
        printf("%c%d", root->character, root->frequency);
        return;
    }
    printf("I");
    printf("%d", root->frequency);
    serialize_tree(root->left);
    serialize_tree(root->right);
}

node *deserialize_tree(const char* serial, int* index) {
    if (serial[*index] == '\0')
        return NULL;

    node *n = new_node(0);
    if (n == NULL) {
        printf("error allocating memory");
        return NULL;
    }

    if (serial[*index] == 'I') {
        (*index)++;
        sscanf(&serial[*index], "%d", &n->frequency);
        while(serial[*index] != 'L' && serial[*index] != 'I') {
            (*index)++;
        }
        n->left = deserialize_tree(serial, index);
        n->right = deserialize_tree(serial, index);
    } else if (serial[*index] == 'L') {
        (*index)++;
        n->character = serial[*index];
        (*index)++;
        sscanf(&serial[*index], "%d", &n->frequency);
        while(serial[*index] != 'L' && serial[*index] != 'I' && serial[*index] != '\0') {
            (*index)++;
        }
        n->left = NULL;
        n->right = NULL;
    }
    return n;
}

void free_frequencies(node *arr[], int length) {
    for (int i = 0; i < length; i++)
        free(arr[i]);
}