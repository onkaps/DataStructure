#include<stdio.h>
#include<stdlib.h>

#ifndef binarySearchTree_char_h
#define binarySearchTree_char_h

typedef struct Node_charBST 
{
    struct Node_charBST *lchild;
    char data;
    struct Node_charBST *rchild;
}CharBSTNode;

CharBSTNode* Char_BST_root = NULL;


void CharBST_Insert ( char key ) {
    CharBSTNode *t = Char_BST_root;
    CharBSTNode *p, *q;

    if( Char_BST_root == NULL){
        p = (CharBSTNode *)malloc(sizeof(CharBSTNode));
        p->data = key;
        p->lchild = p->rchild = NULL;
        Char_BST_root = p;
        return;
    }  

    while (t) {
        q = t;
        if( key < t->data)
            t = t->lchild;
        else if( key >= t->data)
            t = t->rchild;
    }

    p = (CharBSTNode *)malloc(sizeof(CharBSTNode));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if(p->data < q->data)
        q->lchild = p;
    else if ( p->data >= q->data)
        q->rchild = p;  
}

void CharBST_Preorder_create ( CharBSTNode *p) {
    if(p){
        printf("%c ", p->data);
        CharBST_Preorder_create(p->lchild);
        CharBST_Preorder_create(p->rchild);
    }
}

void CharBST_Preorder ( CharBSTNode *p ) {
    if(p){
        printf("\nPre-order traversal : ");
        CharBST_Preorder_create(p);
        printf("\n");
    }
    else{
        printf("\nRoot is Null\n");
    }
}

void CharBST_Inorder_create ( CharBSTNode *p ) {
    if(p) {
        CharBST_Inorder_create(p->lchild);
        printf("%c ", p->data);
        CharBST_Inorder_create(p->rchild);
    }
}

void CharBST_Inorder ( CharBSTNode *p ) {
    if(p){
        printf("\nIn-order traversal : ");
        CharBST_Inorder_create(p);
        printf("\n");
    }
    else{
        printf("\nRoot is Null\n");
    }
}

void CharBST_Postorder_create ( CharBSTNode *p ) {
    if(p) {
        CharBST_Postorder_create(p->lchild);
        CharBST_Postorder_create(p->rchild);
        printf("%c ", p->data);
    }
}

void CharBST_Postorder ( CharBSTNode *p ) {
    if(p){
        printf("\nPost-order traversal : ");
        CharBST_Postorder_create(p);
        printf("\n");
    }
    else{
        printf("\nRoot is Null\n");
    }
}

CharBSTNode* CharBST_RInsert ( CharBSTNode *p, int key ) {
    CharBSTNode *t;
    if( p == NULL){
        t = (CharBSTNode *)malloc(sizeof(CharBSTNode));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if( key < p->data )
        p->lchild = CharBST_RInsert(p->lchild, key);
    else if( key >= p->data)
        p->rchild = CharBST_RInsert(p->rchild, key);
    return p;
}

int CharBST_Height ( CharBSTNode *p ) {
    int x, y;
    if(p == NULL)
        return 0;
    else {
        x = CharBST_Height(p->lchild);
        y = CharBST_Height(p->rchild);
        if(x>y)
            return x + 1;
        else    
            return y + 1; 
    }
}

CharBSTNode* CharBST_InPre ( CharBSTNode *p ) {
    while(p && p->rchild ) {
        p = p->rchild;
    }
    return p;
}

CharBSTNode* CharBST_InSucc ( CharBSTNode *p) {
    while(p && p->lchild){
        p = p->lchild;
    }
    return p;
}

CharBSTNode* CharBST_Delete ( CharBSTNode *p, int key ) {

    CharBSTNode* q;

    if( p == NULL)
        return NULL;
    if( p->lchild == NULL && p->rchild == NULL){
        if( p == Char_BST_root)
            Char_BST_root = NULL;
        free(p);
        return NULL; 
    } 

    if( key < p->data )
        p->lchild = CharBST_Delete( p->lchild, key);  
    else if( key > p->data )
        p->rchild = CharBST_Delete( p->rchild, key);
    else{
        if( CharBST_Height( p->lchild) > CharBST_Height(p->rchild)){
            q = CharBST_InPre(p->lchild);
            p->data = q->data;
            p->lchild = CharBST_Delete(p->lchild, q->data);
        }
        else{
            q = CharBST_InSucc(p->rchild);
            p->data = q->data;
            p->rchild = CharBST_Delete(p->rchild, q->data);
        }
    }
}  

void Char_CreateBST () {
    char x;
    do {
        printf("\nEnter Node Values : ");
        scanf(" %c", &x);
        if( x == '$')
            break;
        CharBST_Insert(x);
    }while( x != '$');
}

#endif /*binarySearchTree_char_h*/