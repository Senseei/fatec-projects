#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "huffman.h"
#include "node.h"
#include "queue.h"


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

    compress(arq, "output.bin");

    FILE *compressed = fopen("output.bin", "r");
    if (compressed == NULL) {
        printf("error opening the file\n");
        return -1;
    }

    decompress(compressed, "decompressed");

    fclose(compressed);
    fclose(arq);
}

void compress(FILE *arq, char *output) {
    FILE *foutput = fopen(output, "wb");

    if (foutput == NULL) {
        printf("error opening the output file");
        return;
    }
        
    node *huffman_tree = build_tree(arq);
    char *table[256] = {NULL};

    load_table(table, huffman_tree, "");
    serialize_tree(huffman_tree, foutput);

    char buffer[1];
    while (fread(buffer, sizeof(char), 1, arq) == 1) {
        fprintf(foutput, table[buffer[0]]);
    }

    for (int i = 0; i < 256; i++)
        free(table[i]);

    free_tree(huffman_tree);
    fclose(foutput);
}

void decompress(FILE *arq, char* output) {
    node *tree = deserialize_tree(arq);

    char file_name[100];
    if (snprintf(file_name, sizeof(file_name), "%s.txt", output) >= sizeof(file_name)) {
        printf("File name is too long.\n");
        return;
    }

    FILE *decompressed = fopen(file_name, "w");

    char buffer[1];
    node *temp = tree;
    while(fread(buffer, sizeof(char), 1, arq) == 1) {
        if (buffer[0] == '0')
            temp = temp->left;
        else if (buffer[0] == '1')
            temp = temp->right;

        if (temp->left == NULL && temp->right == NULL) {
            fprintf(decompressed, "%c", temp->character);
            temp = tree;
        }
    }
    free_tree(tree);
    fclose(decompressed);
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

    if (q->size == 1) {
        node *n1 = dequeue(q);

        node *n = new_node(0);
        n->frequency = n1->frequency;
        n->left = n1;
        n->right = NULL;
        enqueue(q, n);
    }

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

    fseek(arq, 0, SEEK_SET);
    
    return tree;
}

void load_table(char *table[], node *root, char *currentCode) {
    if (root == NULL)
        return;

    if (root->right == NULL && root->left == NULL) {
        table[root->character] = malloc(strlen(currentCode) + 1);
        strcpy(table[root->character], currentCode);
        return;
    }

    char leftCode[8], rightCode[8];
    strcpy(leftCode, currentCode);
    strcpy(rightCode, currentCode);
    strcat(leftCode, "0");
    strcat(rightCode, "1");

    load_table(table, root->left, leftCode);
    load_table(table, root->right, rightCode);
}

void serialize_tree(node *root, FILE *output) {
    serialize(root, output);
    nodeInfo ni;
    ni.character = 0;
    ni.frequency = 0;
    ni.type = 'E';
    fwrite(&ni, sizeof(nodeInfo), 1, output);
}

void serialize(node *root, FILE *output) {
    if (root == NULL)
        return;

    nodeInfo n;

    if (root->left == NULL && root->right == NULL) {
        n.type = 'L';
        n.character = root->character;
        n.frequency = root->frequency;
        fwrite(&n, sizeof(nodeInfo), 1, output);
        return;
    }

    n.type = 'I';
    n.character = 0;
    n.frequency = root->frequency;
    fwrite(&n, sizeof(nodeInfo), 1, output);

    serialize(root->left, output);
    serialize(root->right, output);
}

node *deserialize_tree(FILE *arq) {
    int end = 0;
    return deserialize(arq, &end);
}

node *deserialize(FILE *arq, int *end) {
    nodeInfo ni;
    if (!(*end) && fread(&ni, sizeof(nodeInfo), 1, arq) == 1) {

        if (ni.type == 'E') {
            end++;
            return NULL;
        }

        node *n = (node*) malloc(sizeof(node));
        if (n == NULL) {
            printf("error allocating memory\n");
            return NULL;
        }
    
        if (ni.type == 'L') {
            n->character = ni.character;
            n->frequency = ni.frequency;
            n->left = NULL;
            n->right = NULL;
        }
        else if (ni.type == 'I') {
            n->character = 0;
            n->frequency = ni.frequency;
            n->left = deserialize(arq, end);
            n->right = deserialize(arq, end);
        }
        return n;
    }
    return NULL;
}

void free_frequencies(node *arr[], int length) {
    for (int i = 0; i < length; i++)
        free(arr[i]);
}