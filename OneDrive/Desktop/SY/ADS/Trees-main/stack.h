#include<stdio.h>
#include<stdlib.h>


#include "queue.h"

#ifndef stack_h
#define stack_h


typedef struct Stack_int 
{
    int size;
    int top; 
    IntNode **S;   
}IntStack;

typedef struct Stack_float
{
    int size;
    int top;
    FloatNode **S;
}FloatStack;

typedef struct Stack_char
{
    int size;
    int top;
    CharNode **S;
}CharStack;

typedef struct Stack_string
{
    int size;
    int top;
    StringNode **S;
}StringStack;

//------------------------------------------------------------------------------------------------------------------------------------------------
void Create_intStk ( IntStack *st, int size ) {
    st->size = size;
    st->top = -1;
    st->S = (IntNode **)malloc( st->size * sizeof(IntNode *));
}

void Create_floatStk ( FloatStack *st, int size ) {
    st->size = size;
    st->top = -1;
    st->S = (FloatNode **)malloc( st->size * sizeof(FloatNode *));
}

void Create_stringStk ( StringStack *st, int size ) {
    st->size = size;
    st->top = -1;
    st->S = (StringNode **)malloc( st->size * sizeof(StringNode *));
}

void Create_charStk ( CharStack *st, int size ) {
    st->size = size;
    st->top = -1;
    st->S = (CharNode **)malloc( st->size * sizeof(CharNode *));
}

//----------------------------------------------------------------------------------------------------------------------------------------------
void Push_intStk ( IntStack *st, IntNode *b ) {
    if( st->top == st->size - 1)
        printf("Stack Overflow\n");
    else{
        st->S[++st->top] = b;
    }
}

void Push_floatStk ( FloatStack *st, FloatNode *b ) {
    if( st->top == st->size - 1)
        printf("Stack Overflow\n");
    else{
        st->S[++st->top] = b;
    }
}

void Push_stringStk ( StringStack *st, StringNode *b ) {
    if( st->top == st->size - 1)
        printf("Stack Overflow\n");
    else{
        st->S[++st->top] = b;
    }
}

void Push_charStk ( CharStack *st, CharNode *b ) {
    if( st->top == st->size - 1)
        printf("Stack Overflow\n");
    else{
        st->S[++st->top] = b;
    }
}
//----------------------------------------------------------------------------------------------------------------------------------------------
IntNode *Pop_intStk ( IntStack *st) {
    IntNode *x = NULL;

    if( st->top == -1)
        printf("Stack Underflow\n");
    else{
        x = st->S[st->top--];
    }
    return x;
}

FloatNode *Pop_floatStk ( FloatStack *st) {
    FloatNode *x = NULL;

    if( st->top == -1)
        printf("Stack Underflow\n");
    else{
        x = st->S[st->top--];
    }
    return x;
}

StringNode *Pop_stringStk ( StringStack *st) {
    StringNode *x = NULL;

    if( st->top == -1)
        printf("Stack Underflow\n");
    else{
        x = st->S[st->top--];
    }
    return x;
}

CharNode *Pop_charStk ( CharStack *st) {
    CharNode *x = NULL;

    if( st->top == -1)
        printf("Stack Underflow\n");
    else{
        x = st->S[st->top--];
    }
    return x;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------
int isEmpty_intStk ( IntStack st ) {
    return  st.top == -1;
}

int isEmpty_floatStk ( FloatStack st ) {
    return  st.top == -1;
}

int isEmpty_stringStk ( StringStack st  ) {
    return  st.top == -1;
}

int isEmpty_charStk ( CharStack st  ) {
    return  st.top == -1;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
#endif /*stack_h*/