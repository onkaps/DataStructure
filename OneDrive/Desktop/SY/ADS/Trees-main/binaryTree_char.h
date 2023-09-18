#include "queue.h"
#include "stack.h"
#include<stdio.h>
#include<stdlib.h>

#ifndef binaryTree_char_h
#define binaryTree_char_h

CharNode *Char_root = NULL;


void Char_CreateBT () {
    CharNode *p, *t;
    char x;
    CharQueue q;
    Create_CharQ( &q, 100);

    printf("Enter root Node    : ");
    scanf(" %c", &x);
    Char_root = (CharNode *)malloc(sizeof(CharNode));
    Char_root->data = x;
    Char_root->lchild = Char_root->rchild = NULL;
    enqueue_CharQ( &q, Char_root );

    while ( !isEmpty_CharQ(q) ) {
        p = dequeue_CharQ(&q);

        printf("Enter left child of %c  : ", p->data);
        scanf(" %c", &x);
        if ( x != '$') {
            t = (CharNode *)malloc(sizeof(CharNode));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue_CharQ( &q, t);
        }

        printf("Enter right child of %c : ", p->data);
        scanf(" %c", &x);
        if( x != '$'){
            t = (CharNode *)malloc(sizeof(CharNode));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue_CharQ( &q, t);
        }
    }
}

void CharBT_Preorder_create ( CharNode *p ) {
    if(p){
        printf("%c ", p->data);
        CharBT_Preorder_create( p->lchild);
        CharBT_Preorder_create( p->rchild);
    }
}
void CharBT_Preorder ( CharNode *p ) {
    printf("\nPre-order Traversal of Binary Tree : ");
    CharBT_Preorder_create(p);
    printf("\n");
}

void CharBT_Inorder_create ( CharNode *p ) {
    if(p){
        CharBT_Inorder_create( p->lchild);
        printf("%c ", p->data);
        CharBT_Inorder_create( p->rchild);
    }
}
void CharBT_Inorder ( CharNode *p ) { 
    printf("\nIn-order Traversal of Binary Tree : ");
    CharBT_Inorder_create(p);
    printf("\n");
}

void CharBT_Postorder_create ( CharNode *p ) {
    if(p){
        CharBT_Postorder_create(p->lchild);
        CharBT_Postorder_create( p->rchild);
        printf("%c ", p->data);
    }
}

void CharBT_Postorder ( CharNode *p ) {
    printf("\nPost-order Traversal of Binary Tree : ");
    CharBT_Postorder_create(p);
    printf("\n");
}

void CharBT_Preorder_it ( CharNode *p ) {
    CharStack stk;
    Create_charStk( &stk, 100 );
    printf("\nPre-order Treaversal of Binary Tree using Iteration : ");
    while( p || !isEmpty_charStk(stk)){
        if(p){
            printf("%c ", p->data);
            Push_charStk(&stk, p);
            p = p->lchild;
        }
        else{
            p = Pop_charStk(&stk);
            p = p->rchild;
        }
    }
    printf("\n");
}

void CharBT_Inorder_it ( CharNode *p ) {
    CharStack stk;
    Create_charStk( &stk, 100);
    printf("\nIn-order Traversal of Binary Tree using Iteration : ");

    while( p || !isEmpty_charStk(stk)){
        if(p){
            Push_charStk(&stk,p);
            p = p->lchild;
        }
        else{
            p = Pop_charStk(&stk);
            printf("%c ", p->data);
            p = p->rchild;
        }
    }
    printf("\n");
}

//Postorder Traversal of Int type Binary Tree using Iterations.
// void Postorder_it(CharNode *p){
//     IntStack stk;
//     long int temp;
//     CreateStack( &stk, 100);

//     while( p || !isEmptyStack(stk)){
//         if(p){
//             Push(&stk, p);
//             p = p->lchild;
//         }
//     }
//     else{
//         temp = Pop(&stk);
//         if(temp > 0){
//             Push( &stk, -temp);
//             p = ((CharNode *)temp->)
//         }
//     }
// }

void CharBT_Levelwise_it ( CharNode *p ) { 
    CharQueue q;
    Create_CharQ( &q, 100);
    printf("\nLevelwise Traversal of Binary Tree using Iteration : ");
    printf("%c ", p->data);
    enqueue_CharQ( &q, p);

    while( !isEmpty_CharQ){
        p = dequeue_CharQ(&q);
        if(p->lchild){
            printf("%c ", p->lchild->data);
            enqueue_CharQ(&q, p->lchild);
        }
        if(p->rchild){
            printf("%c ", p->rchild->data);
            enqueue_CharQ(&q, p->rchild);
        }
    }
    printf("\n");
}

int Cal_Height_CharBT ( CharNode *p ) {
    int lHeight = 0, rHeight = 0;
    if ( p == NULL)
        return 0;
    else{
        lHeight = Cal_Height_CharBT(p->lchild);
        rHeight = Cal_Height_CharBT(p->rchild);
        if(lHeight > rHeight)
            return lHeight + 1;
        else
            return rHeight + 1;
    }
}

void CharBT_Height ( CharNode *p ) {
    printf("\nThe Height of the Binary Tree is : %d ", Cal_Height_CharBT(p) - 1);
    printf("\n");
}


int Cal_Nodes_CharBT ( CharNode *p ) {
    int x, y;
    if(p){
        x = Cal_Nodes_CharBT(p->lchild);
        y = Cal_Nodes_CharBT(p->rchild);
        return (x + y + 1);
    }
    return 0;
}
//function to print no. of nodes in Binary Tree.
void CharBT_CountNodes ( CharNode *p ) {
    printf("\nNumber of Nodes in Binary Tree are : %d ", Cal_Nodes_CharBT(p));
    printf("\n");
}

void CharBT_PrintLevel ( CharNode *p, int level ) { 
    if( !p)
        return ;
    
    if( level == 0)
        printf("%c ", p->data);
    else{
        CharBT_PrintLevel( p->lchild, level - 1);
        CharBT_PrintLevel( p->rchild, level - 1);
    }
}
//( secondary function to print level wise using recursion)
void CharBT_Levelwise ( CharNode *p ) {
    int i, height = Cal_Height_CharBT(p);
    printf("Level-wise Traversal of Binary Tree : \n");
    for ( i = 0; i < height; i++){
        printf("Level [%d] : ", i + 1);
        CharBT_PrintLevel( p, i);
        printf("\n");
    }
    printf("\n");
}

int cal_Deg2_Nodes_CharBT ( CharNode *p ) {
    int x, y;
    if(p){
        x = cal_Deg2_Nodes_CharBT( p->lchild);
        y = cal_Deg2_Nodes_CharBT( p->rchild);
        if( p->lchild && p->rchild){
            printf("%c ", p->data);
            return (x + y + 1);
        }
        else
            return (x + y);
    }
    return 0;
}
void CharBT_Deg2_nodes ( CharNode *p ) {
    printf("\n\nNumber of Nodes having Degree 2 : %d ", cal_Deg2_Nodes_CharBT(p));
    printf("\n");
}

int cal_Deg1_Nodes_CharBT ( CharNode *p ) {
    int x, y;
    if(p){
        x = cal_Deg1_Nodes_CharBT( p->lchild);
        y = cal_Deg1_Nodes_CharBT( p->rchild);
        if( ( p->lchild && !p->rchild) || ( !p->lchild && p->rchild) ){
            printf("%c ", p->data);
            return ( x + y + 1);
        }
        else    
            return x + y;
    }
    return 0;
}
void CharBT_Deg1_nodes ( CharNode *p ) {
    printf("\n\nNumber of Nodes having Degree 1 : %d ", cal_Deg1_Nodes_CharBT(p));
    printf("\n");
}


int cal_Deg0_Nodes_CharBT ( CharNode *p ) {
    int x, y;
    if(p){
        x = cal_Deg0_Nodes_CharBT( p->lchild);
        y = cal_Deg0_Nodes_CharBT( p->rchild);
        if( !p->lchild && ! p->rchild){
            printf("%c ", p->data);
            return ( x + y + 1 );
        }
        else
            return ( x + y );
    }
    return 0;
}
void CharBT_LeafNodes ( CharNode *p ) { 
    printf("\n\nNumber of Nodes having Degree 0 i.e. Leaf Nodes : %d ", cal_Deg0_Nodes_CharBT(p));
    printf("\n");
}

void CharBT_MirrorImage ( CharNode *p ) {
    CharNode *temp;
    if( p == NULL)
        return;
    else{
        CharBT_MirrorImage(p->lchild);
        CharBT_MirrorImage(p->rchild);
        temp = p->lchild ;
        p->lchild = p->rchild;
        p->rchild = temp;
    }
}

#endif /*binaryTree_char_h*/
