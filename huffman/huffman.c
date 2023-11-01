#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "node.h"
#include "queue.h"

bool build_tree(FILE *arq);
void free_frequences(node *arr[], int length);

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

    build_tree(arq);

    fclose(arq);
}

bool build_tree(FILE *arq) {
    node *frequences[256] = {NULL};
    int total_nodes = 0;
    char buffer[1];

    while (fread(buffer, sizeof(char), 1, arq) == 1) {
        char character = buffer[0];
        int index = (int) character;

        if (frequences[index] == NULL) { 
            node *n = new_node(character);

            if (n == NULL) {
                free_frequences(frequences, 256);
                return false;
            }

            frequences[index] = n;
            total_nodes++;
        }
        else
            frequences[index]->frequence++;
    }

    queue *q = new_queue();

    for (int i = 0, next = 0; i < 256; i++) {
        if (frequences[i] != NULL) {
            enqueue(q, frequences[i]);
        }
    }
    sort_queue(q);

    printf("-------------\n");
    while (q->size != 1) {
        node *n1 = dequeue(q);
        node *n2 = dequeue(q);

        node *n = new_node(0);
        n->frequence = n1->frequence + n2->frequence;

        n->left = n1;
        n->right = n2;

        enqueue(q, n);
        sort_queue(q);
    }
    print_queue(q);
    
    free_queue(q);
    return true;
}

void free_frequences(node *arr[], int length) {
    for (int i = 0; i < length; i++)
        free(arr[i]);
}