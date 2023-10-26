#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef binarySearchTree_string_h
#define binarySearchTree_string_h

typedef struct Node_string
{
    struct Node_string *lchild;
    char *data;
    struct Node_string *rchild;
} StringBSTNode;

StringBSTNode *String_BST_root = NULL;

void String_CreateBST()
{
}

void StringBST_Insert(char *key)
{
    StringBSTNode *t = String_BST_root;
    StringBSTNode *p, *q;

    if (String_BST_root == NULL)
    {
        p = (StringBSTNode *)malloc(sizeof(StringBSTNode));
        p->data = (char *)malloc(256 * sizeof(char));
        p->data = key;
        p->lchild = p->rchild = NULL;
        String_BST_root = p;
        return;
    }

    while (t)
    {
        q = t;
        if (strlen(key) < strlen(t->data))
            t = t->lchild;
        else if (strlen(key) >= strlen(t->data))
            t = t->rchild;
    }

    p = (StringBSTNode *)malloc(sizeof(StringBSTNode));
    p->data = (char *)malloc(256 * sizeof(char));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (strlen(p->data) < strlen(q->data))
        q->lchild = p;
    else if (strlen(p->data) >= strlen(q->data))
        q->rchild = p;
}

void StringBST_Inorder_create(StringBSTNode *p)
{
    if (p)
    {
        StringBST_Inorder_create(p->lchild);
        printf("%s ", p->data);
        StringBST_Inorder_create(p->rchild);
    }
}

void String_Inorder

#endif /*binarySearchTree_string_h*/