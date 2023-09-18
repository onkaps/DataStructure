#include<stdio.h>
#include<stdlib.h>

#ifndef binarySearchTree_int_h
#define binarySearchTree_int_h

typedef struct Node_intBST 
{
    struct Node_intBST *lchild;
    int data;
    struct Node_intBST *rchild;
}IntBSTNode;

IntBSTNode* Int_BST_root = NULL;


void IntBST_Insert ( int key ) {
    IntBSTNode *t = Int_BST_root;
    IntBSTNode *p, *q;

    if( Int_BST_root == NULL){
        p = (IntBSTNode *)malloc(sizeof(IntBSTNode));
        p->data = key;
        p->lchild = p->rchild = NULL;
        Int_BST_root = p;
        return;
    }  

    while (t) {
        q = t;
        if( key < t->data)
            t = t->lchild;
        else if( key >= t->data)
            t = t->rchild;
    }

    p = (IntBSTNode *)malloc(sizeof(IntBSTNode));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if(p->data < q->data)
        q->lchild = p;
    else if ( p->data >= q->data)
        q->rchild = p;  
}

void IntBST_Preorder_create ( IntBSTNode *p) {
    if(p){
        printf("%d ", p->data);
        IntBST_Preorder_create(p->lchild);
        IntBST_Preorder_create(p->rchild);
    }
}

void IntBST_Preorder ( IntBSTNode *p ) {
    if(p){
        printf("\nPre-order traversal : ");
        IntBST_Preorder_create(p);
        printf("\n");
    }
    else{
        printf("\nRoot is Null\n");
    }
}

void IntBST_Inorder_create ( IntBSTNode *p ) {
    if(p) {
        IntBST_Inorder_create(p->lchild);
        printf("%d ", p->data);
        IntBST_Inorder_create(p->rchild);
    }
}

void IntBST_Inorder ( IntBSTNode *p ) {
    if(p){
        printf("\nIn-order traversal : ");
        IntBST_Inorder_create(p);
        printf("\n");
    }
    else{
        printf("\nRoot is Null\n");
    }
}

void IntBST_Postorder_create ( IntBSTNode *p ) {
    if(p) {
        IntBST_Postorder_create(p->lchild);
        IntBST_Postorder_create(p->rchild);
        printf("%d ", p->data);
    }
}

void IntBST_Postorder ( IntBSTNode *p ) {
    if(p){
        printf("\nPost-order traversal : ");
        IntBST_Postorder_create(p);
        printf("\n");
    }
    else{
        printf("\nRoot is Null\n");
    }
}

IntBSTNode* IntBST_RInsert ( IntBSTNode *p, int key ) {
    IntBSTNode *t;
    if( p == NULL){
        t = (IntBSTNode *)malloc(sizeof(IntBSTNode));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if( key < p->data )
        p->lchild = IntBST_RInsert(p->lchild, key);
    else if( key >= p->data)
        p->rchild = IntBST_RInsert(p->rchild, key);
    return p;
}




#endif /*binarySearchTree_int_h*/