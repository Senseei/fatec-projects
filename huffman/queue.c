#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
#include "node.h"

queue *new_queue() {
    queue *q = (queue*) malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;

    return q;
}

bool queue_is_empty(queue *q) {
    return q->size == 0;
}


void enqueue(queue *q, node *n) {
    queueNode *qn = (queueNode*) malloc(sizeof(queueNode));
    if (qn == NULL) {
        free_queue(q);
        return;
    }

    qn->n = n;
    qn->next = NULL;

    if (queue_is_empty(q)) {
        
        q->front = qn;
        q->rear = qn;
    }
    else {
        q->rear->next = qn;
        q->rear = qn;
    }
    q->size++;
}

node *dequeue(queue *q) {
    if (queue_is_empty(q)) {
        return NULL;
    }
    else {
        queueNode *temp = q->front;
        node *n = temp->n;
        q->front = temp->next;
        free(temp);

        if (q->front == NULL)
            q->rear = NULL;

        q->size--;
        
        return n;
    }
}

void sort_queue(queue *q) {
    int changes;
    do {
        changes = 0;
        for (queueNode *qn = q->front; qn->next != NULL; qn = qn->next) {
            if (qn->n->frequency > qn->next->n->frequency) {
                node *temp = qn->n;
                qn->n = qn->next->n;
                qn->next->n = temp;
                changes++;
            }
        }
    } while (changes > 0);
}

void print_queue(queue *q) {
    print_queue_content(q->front);
    printf("%d elements were in queue..\n", q->size);
}

void print_queue_content(queueNode *root) {
    if (root == NULL)
        return;
    printf("queue node: \n");
    print_tree(root->n, 0);
    print_queue_content(root->next);
}

void free_queue_content(queueNode *root) {
    if (root == NULL)
        return;
    free_queue_content(root->next);
    free_tree(root->n);
    free(root);
}

void free_queue(queue *q) {
    free_queue_content(q->front);
    free(q);
}