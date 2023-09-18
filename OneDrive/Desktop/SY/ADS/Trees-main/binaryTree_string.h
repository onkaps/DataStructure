#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "queue.h"

#ifndef binaryTree_string_h
#define binaryTree_string_h


StringNode *String_root = NULL;

void String_CreateBT () {
    StringNode *p, *t;
    char x[50];

    StringQueue q;
    Create_StringQ( &q, 100);

    printf("Enter Root Node   : ");
    fflush(stdout);
    scanf("%[^\n]", String_root->data);
    fflush(stdin);
    printf("check 1 !");
    String_root = (StringNode *)malloc(sizeof(StringNode));
    strcpy(String_root->data, x);
    String_root->lchild = String_root->rchild = NULL;
    enqueue_StringQ( &q, String_root );

    while( !isEmpty_StringQ(q) ){
    printf("check 2 !");

        p = dequeue_StringQ(&q);
        printf("check 3 !");

        printf("Enter left child of %s  : ", p->data);
        fflush(stdout);
        scanf("%s", x);
        if( strcmp( x, "-1")){
            t = (StringNode *)malloc(sizeof(StringNode));
            strcpy(t->data,x);
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue_StringQ( &q, t);
        }

        printf("Enter right child of %s : ", p->data);
        fflush(stdout);
        scanf("%s", x);
        if( strcmp( x, "-1")){
            t = (StringNode *)malloc(sizeof(StringNode));
            strcpy(t->data,x);
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue_StringQ( &q, t);
        }
    }
}

void StringBT_Preorder_create ( StringNode *p ) {
    if(p){
        printf("%s ", p->data);
        StringBT_Preorder_create(p->lchild);
        StringBT_Preorder_create(p->rchild);
    }
}
void StringBT_Preorder ( StringNode *p ) {
    printf("\n\nPre-order Traversal of Binary Tree : ");
    StringBT_Preorder_create(p);
    printf("\n");
}

// void StringBT_Inorder_create ( StringNode *p ) {
//     if(p){
//     StringBT_Inorder_create(p->lchild);
//     printf("%s ", p->data);
//     StringBT_Inorder_create(p->rchild);
//     }
// }
// void StringBT_Inorder ( StringNode *p ) {
//     printf("\n\nIn-order Traversal of Binary Tree : ");
//     StringBT_Inorder_create(p);
//     printf("\n");
// }

// void StringBT_Postorder_create ( StringNode *p ) {
//     if(p){
//     StringBT_Postorder_create(p->lchild);
//     StringBT_Postorder_create(p->rchild);
//     printf("%s ", p->data);        
//     }
// }
// void StringBT_Postorder ( StringNode *p ) {
//     printf("\n\nPost-order Traversal of Binary Tree : ");
//     StringBT_Postorder_create(p);
//     printf("\n");

// }




#endif /*binaryTree_string_h*/