#include<stdio.h>
#include<stdlib.h>

#ifndef binarySearchTree_float_h
#define binarySearchTree_float_h

typedef struct Node_floatBST 
{
    struct Node_floatBST *lchild;
    float data;
    struct Node_floatBST *rchild;
}FloatBSTNode;

FloatBSTNode* Float_BST_root = NULL;


void FloatBST_Insert ( float key ) {
    FloatBSTNode *t = Float_BST_root;
    FloatBSTNode *p, *q;

    if( Float_BST_root == NULL){
        p = (FloatBSTNode *)malloc(sizeof(FloatBSTNode));
        p->data = key;
        p->lchild = p->rchild = NULL;
        Float_BST_root = p;
        return;
    }  

    while (t) {
        q = t;
        if( key < t->data)
            t = t->lchild;
        else if( key >= t->data)
            t = t->rchild;
    }

    p = (FloatBSTNode *)malloc(sizeof(FloatBSTNode));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if(p->data < q->data)
        q->lchild = p;
    else if ( p->data >= q->data)
        q->rchild = p;  
}

void FloatBST_Preorder_create ( FloatBSTNode *p ) {
    if(p){
        printf("%.2f ", p->data);
        FloatBST_Preorder_create(p->lchild);
        FloatBST_Preorder_create(p->rchild);
    }
}

void FloatBST_Preorder ( FloatBSTNode *p ) {
    if(p){
        printf("\nPre-order traversal : ");
        FloatBST_Preorder_create(p);
        printf("\n");
    }
    else{
        printf("\nRoot is Null\n");
    }
}

void FloatBST_Inorder_create ( FloatBSTNode *p ) {
    if(p) {
        FloatBST_Inorder_create(p->lchild);
        printf("%.2f ", p->data);
        FloatBST_Inorder_create(p->rchild);
    }
}

void FloatBST_Inorder ( FloatBSTNode *p ) {
    if(p){
        printf("\nIn-order traversal : ");
        FloatBST_Inorder_create(p);
        printf("\n");
    }
    else{
        printf("\nRoot is Null\n");
    }
}

void FloatBST_Postorder_create ( FloatBSTNode *p ) {
    if(p) {
        FloatBST_Postorder_create(p->lchild);
        FloatBST_Postorder_create(p->rchild);
        printf("%.2f ", p->data);
    }
}

void FloatBST_Postorder ( FloatBSTNode *p ) {
    if(p){
        printf("\nPost-order traversal : ");
        FloatBST_Postorder_create(p);
        printf("\n");
    }
    else{
        printf("\nRoot is Null\n");
    }
}

FloatBSTNode* FloatBST_RInsert ( FloatBSTNode *p, float key ) {
    FloatBSTNode *t;
    if( p == NULL){
        t = (FloatBSTNode *)malloc(sizeof(FloatBSTNode));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if( key < p->data )
        p->lchild = FloatBST_RInsert(p->lchild, key);
    else if( key >= p->data)
        p->rchild = FloatBST_RInsert(p->rchild, key);
    return p;
}

int FloatBST_Height ( FloatBSTNode *p ) {
    int x, y;
    if(p == NULL)
        return 0;
    else {
        x = FloatBST_Height(p->lchild);
        y = FloatBST_Height(p->rchild);
        if(x>y)
            return x + 1;
        else    
            return y + 1; 
    }
}

FloatBSTNode* FloatBST_InPre ( FloatBSTNode *p ) {
    while(p && p->rchild ) {
        p = p->rchild;
    }
    return p;
}

FloatBSTNode* FloatBST_InSucc ( FloatBSTNode *p) {
    while(p && p->lchild){
        p = p->lchild;
    }
    return p;
}

FloatBSTNode* FloatBST_Delete ( FloatBSTNode *p, float key ) {

    FloatBSTNode* q;

    if( p == NULL)
        return NULL;
    if( p->lchild == NULL && p->rchild == NULL){
        if( p == Float_BST_root)
            Float_BST_root = NULL;
        free(p);
        return NULL; 
    } 

    if( key < p->data )
        p->lchild = FloatBST_Delete( p->lchild, key);  
    else if( key > p->data )
        p->rchild = FloatBST_Delete( p->rchild, key);
    else{
        if( FloatBST_Height( p->lchild) > FloatBST_Height(p->rchild)){
            q = FloatBST_InPre(p->lchild);
            p->data = q->data;
            p->lchild = FloatBST_Delete(p->lchild, q->data);
        }
        else{
            q = FloatBST_InSucc(p->rchild);
            p->data = q->data;
            p->rchild = FloatBST_Delete(p->rchild, q->data);
        }
    }
}  

void Float_CreateBST () {
    float x;
    do {
        printf("\nEnter Node Values : ");
        scanf(" %f", &x);
        if( x == -1)
            break;
        FloatBST_Insert(x);
    }while( x != -1);
}

#endif /*binarySearchTree_float_h*/