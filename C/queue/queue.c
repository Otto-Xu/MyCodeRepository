#include "queue.h"

void QueueInit(Queue *pq)
{
    assert(pq);
    pq->front = NULL;
    pq->rear = NULL;
}

void QueueDestory(Queue *pq)
{
    assert(pq);
    QueueNode *tmp;
    while(pq->front)
    {
        tmp = pq->front;
        pq->front = tmp->next;
        free(tmp);
    }
}

void QueuePush(Queue *pq, int data)
{
    assert(pq);
    QueueNode *cur = (QueueNode *)calloc(1, sizeof(QueueNode));
    cur->data = data;
    if(pq->front == NULL)
    {
        pq->front = pq->rear = cur;
    }
    cur->next = NULL;
    pq->rear->next = cur;
    pq->rear = cur;
}

void QueuePop(Queue *pq)
{
    assert(pq);
    QueueNode *tmp;
    tmp = pq->front;
    pq->front = tmp->next;
    free(tmp);
}

int QueueFront(Queue *pq)
{
    assert(pq);
    return pq->front->data;
}

int QueueBack(Queue *pq)
{
    assert(pq);
    return pq->rear->data;
}

int QueueEmpty(Queue *pq)
{
    assert(pq);
    return pq->front == NULL;
}

int QueueSize(Queue *pq)
{
    assert(pq);
    QueueNode *cur = pq->front;
    int count = 0;
    while(cur)
    {
        ++count;
        if(cur == pq->rear)
        {
            break;
        }
        cur = cur->next;
    }
    return count;
}

void QueuePrint(Queue *pq)
{
    assert(pq);
    for(QueueNode *cur = pq->front; cur; cur = cur->next)
    {
        printf("%d ", cur->data);
        if(cur == pq->rear)
        {
            break;
        }
    }

    printf("\n");
}
