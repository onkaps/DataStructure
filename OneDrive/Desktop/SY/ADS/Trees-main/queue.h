#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef queue_h
#define queue_h

typedef struct Node_int
{
    struct Node_int *lchild;
    int data;
    struct Node_int *rchild;

} IntNode;

typedef struct Node_char
{
    struct Node_char *lchild;
    char data;
    struct Node_char *rchild;
} CharNode;

typedef struct Node_float
{
    struct Node_float *lchild;
    float data;
    struct Node_float *rchild;
} FloatNode;

typedef struct Node_string
{
    struct Node_string *lchild;
    char *data;
    data = (char *)malloc(256 * sizeof(char));
    struct Node_string *rchild;
} StringNode;

//--------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------

typedef struct Queue_int
{
    int size;
    int front;
    int rear;
    IntNode **Q;
} IntQueue;

typedef struct Queue_char
{
    int size;
    int front;
    int rear;
    CharNode **Q;
} CharQueue;

typedef struct Queue_float
{
    int size;
    int front;
    int rear;
    FloatNode **Q;
} FloatQueue;

typedef struct Queue_string
{
    int size;
    int front;
    int rear;
    StringNode **Q;
} StringQueue;

//------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------
void Create_IntQ(IntQueue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (IntNode **)malloc(q->size * sizeof(IntNode *));
}

void Create_CharQ(CharQueue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (CharNode **)malloc(q->size * sizeof(CharNode *));
}

void Create_FloatQ(FloatQueue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (FloatNode **)malloc(q->size * sizeof(FloatNode *));
}

void Create_StringQ(StringQueue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (StringNode **)malloc(q->size * sizeof(StringNode *));
}

//-------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------
void enqueue_IntQ(IntQueue *q, IntNode *b)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue is full");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = b;
    }
}

void enqueue_CharQ(CharQueue *q, CharNode *b)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue is full");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = b;
    }
}

void enqueue_FloatQ(FloatQueue *q, FloatNode *b)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue is full");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = b;
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------

IntNode *dequeue_IntQ(IntQueue *q)
{
    IntNode *x = NULL;

    if (q->rear == q->front)
        printf("Queue is Empty");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

CharNode *dequeue_CharQ(CharQueue *q)
{
    CharNode *x = NULL;

    if (q->rear == q->front)
        printf("Queue is Empty");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

FloatNode *dequeue_FloatQ(FloatQueue *q)
{
    FloatNode *x = NULL;

    if (q->rear == q->front)
        printf("Queue is Empty");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

//-------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------

int isEmpty_IntQ(IntQueue q)
{
    return q.front == q.rear;
}

int isEmpty_CharQ(CharQueue q)
{
    return q.front == q.rear;
}

int isEmpty_FloatQ(FloatQueue q)
{
    return q.front == q.rear;
}

//-------------------------------------------------------------------------------------------------------------------------------------------

#endif /*queue_h*/
