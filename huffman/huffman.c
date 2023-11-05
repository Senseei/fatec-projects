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

    FILE *compressed = fopen("output.bin", "rb");
    if (compressed == NULL) {
        printf("error opening the file\n");
        return -1;
    }

    decompress(compressed, "decompressed");

    fclose(compressed);
    fclose(arq);
}

void compress(FILE *input, char *output) {
    FILE *foutput = fopen(output, "wb");

    if (foutput == NULL) {
        printf("error opening the output file");
        return;
    }
        
    node *huffman_tree = build_tree(input);
    char *table[256] = {NULL};

    load_table(table, huffman_tree, "");
    serialize_tree(huffman_tree, foutput);

    char buffer[1];
    unsigned char current_byte = 0;
    int bit_position = 7;

    while (fread(buffer, sizeof(char), 1, input) == 1) {
        char *huffman_code = table[buffer[0]];
        for (int i = 0; huffman_code[i]; i++) {
            unsigned char bit = huffman_code[i] - '0';
            current_byte |= (bit << bit_position);
            bit_position--;

            if (bit_position < 0) {
                fwrite(&current_byte, sizeof(unsigned char), 1, foutput);
                current_byte = 0;
                bit_position = 7;
            }
        }
    }

    if (bit_position != 7) {
        fwrite(&current_byte, sizeof(unsigned char), 1, foutput);
    }

    for (int i = 0; i < 256; i++)
        free(table[i]);

    free_tree(huffman_tree);
    fclose(foutput);
}

void decompress(FILE *input, char* output) {
    node *tree = deserialize_tree(input);

    char file_name[100];
    if (snprintf(file_name, sizeof(file_name), "%s.txt", output) >= sizeof(file_name)) {
        printf("File name is too long.\n");
        return;
    }

    FILE *decompressed = fopen(file_name, "w");

    unsigned char buffer = 0;
    int buffer_position = 0;
    node *temp = tree;

    while (fread(&buffer, sizeof(unsigned char), 1, input) == 1) {
        for (int i = 7; i >= 0; i--) {
            unsigned char bit = (buffer >> i) & 1; // Extract one bit
            if (bit == 0)
                temp = temp->left;
            else if (bit == 1)
                temp = temp->right;

            if (temp->left == NULL && temp->right == NULL) {
                fprintf(decompressed, "%c", temp->character);
                temp = tree;
            }
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
                for (int i = 0; i < 256; i++) {
                    if (frequencies[i] != NULL)
                        free(frequencies[i]);
                }
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
        node *n2 = new_node(0);
        n2->frequency = 0;

        node *n = new_node(0);
        n->frequency = n1->frequency;
        n->left = n1;
        n->right = n2;
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

    char leftCode[256], rightCode[256];
    strcpy(leftCode, currentCode);
    strcpy(rightCode, currentCode);
    strcat(leftCode, "0");
    strcat(rightCode, "1");

    load_table(table, root->left, leftCode);
    load_table(table, root->right, rightCode);
}

void serialize_tree(node *root, FILE *output) {
    serialize(root, output);
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
    nodeInfo ni;
    if (fread(&ni, sizeof(nodeInfo), 1, arq) == 1) {
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
            n->left = deserialize_tree(arq);
            n->right = deserialize_tree(arq);
        }
        return n;
    }
    return NULL;
}