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

void IntBST_Preorder_create ( IntBSTNode *p ) {
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

int IntBST_Height ( IntBSTNode  *p ) {
    int x, y;
    if(p == NULL)
        return 0;
    else {
        x = IntBST_Height(p->lchild);
        y = IntBST_Height(p->rchild);
        if(x>y)
            return x + 1;
        else    
            return y + 1; 
    }
}

IntBSTNode* IntBST_InPre ( IntBSTNode *p ) {
    while(p && p->rchild ) {
        p = p->rchild;
    }
    return p;
}

IntBSTNode* IntBST_InSucc ( IntBSTNode *p ) {
    while(p && p->lchild){
        p = p->lchild;
    }
    return p;
}

IntBSTNode* IntBST_Delete ( IntBSTNode *p, int key ) {

    IntBSTNode* q;

    if( p == NULL)
        return NULL;
    if( p->lchild == NULL && p->rchild == NULL){
        if( p == Int_BST_root)
            Int_BST_root = NULL;
        free(p);
        return NULL; 
    } 

    if( key < p->data )
        p->lchild = IntBST_Delete( p->lchild, key);  
    else if( key > p->data )
        p->rchild = IntBST_Delete( p->rchild, key);
    else{
        if( IntBST_Height( p->lchild) > IntBST_Height(p->rchild)){
            q = IntBST_InPre(p->lchild);
            p->data = q->data;
            p->lchild = IntBST_Delete(p->lchild, q->data);
        }
        else{
            q = IntBST_InSucc(p->rchild);
            p->data = q->data;
            p->rchild = IntBST_Delete(p->rchild, q->data);
        }
    }
}  

void Int_CreateBST () {
    int x;
    do {
        printf("\nEnter Node Values : ");
        scanf("%d", &x);
        if( x == -1)
            break;
        IntBST_Insert(x);
    }while( x != -1);
}

#endif /*binarySearchTree_int_h*/