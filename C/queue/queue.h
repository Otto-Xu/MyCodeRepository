#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct QueueNode
{
    struct QueueNode *next;
    int data;
}QueueNode;

typedef struct Queue
{
    QueueNode *front;
    QueueNode *rear;
}Queue;

void QueueInit(Queue *pq);
void QueueDestory(Queue *pq);
QueueNode *BuyQueueNode(int data);
void QueuePush(Queue *pq, int data);
void QueuePop(Queue *pq);
int QueueFront(Queue *pq);
int QueueBack(Queue *pq);
int QueueEmpty(Queue *pq);
int QueueSize(Queue *pq);
void QueuePrint(Queue *pq);
