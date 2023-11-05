#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "node.h"

typedef struct nodeInfo {
    char type;
    char character;
    int frequency;
}
nodeInfo;

node *build_tree(FILE *arq);
void load_table(char *table[], node *root, char *currentCode);
void serialize_tree(node *root, FILE *output);
void serialize(node *root, FILE *output);
node *deserialize_tree(FILE *arq);
void compress(FILE *input, char *output);
void decompress(FILE *input, char *output);

#endif