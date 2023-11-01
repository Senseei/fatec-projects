#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

typedef struct queueNode {
    node *n;
    struct queueNode *next;
}
queueNode;

typedef struct queue {
    queueNode *front;
    queueNode *rear;
    int size;
}
queue;

void free_queue_content(queueNode *root);
void free_queue(queue *q);
queue *new_queue();
bool queue_is_empty(queue *q);
void enqueue(queue *q, node *n);
node *dequeue(queue *q);
void sort_queue(queue *q);
void print_queue(queue *q);
void print_queue_content(queueNode *root);

#endif