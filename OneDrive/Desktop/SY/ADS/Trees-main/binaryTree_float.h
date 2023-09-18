#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
#include "stack.h"

#ifndef binaryTree_float_h
#define binaryTree_float_h

FloatNode *Float_root = NULL;

void Float_CreateBT () {
    FloatNode *p, *t;
    float x;
    FloatQueue q;
    Create_FloatQ ( &q, 100 );

    printf("Enter root Node : ");
    scanf("%f", &x);
    Float_root = (FloatNode *)malloc(sizeof(FloatNode));
    Float_root->data = x;
    Float_root->lchild = Float_root->rchild = NULL;
    enqueue_FloatQ( &q, Float_root);
    
    while( !isEmpty_FloatQ(q)) {
        p = dequeue_FloatQ(&q);

        printf("Enter left child of %.3f  : ", p->data);
        scanf("%f", &x);
        if( x != -1){
            t = (FloatNode *)malloc(sizeof(FloatNode));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue_FloatQ( &q, t);
        }

        printf("Enter right child of %.3f : ", p->data);
        scanf("%f", &x);
        if( x != -1){
            t = (FloatNode *)malloc(sizeof(FloatNode));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue_FloatQ( &q, t);
        }
    }
}

void FloatBT_Preorder_create ( FloatNode *p ) {
    if(p){
        printf("%.3f ", p->data);
        FloatBT_Preorder_create( p->lchild);
        FloatBT_Preorder_create( p->rchild);
    }
}
void FloatBT_Preorder ( FloatNode *p ) {
    printf("\n\nPre-order Traversal of Binary Tree : ");
    FloatBT_Preorder_create(p);
    printf("\n");
}

void FloatBT_Inorder_create ( FloatNode *p ) {
    if(p){
        FloatBT_Inorder_create( p->lchild);
        printf("%.3f ", p->data);
        FloatBT_Inorder_create( p->rchild);
    }
}
void FloatBT_Inorder ( FloatNode *p ) {
    printf("\n\nIn-order Traversal of Binary Tree : ");
    FloatBT_Inorder_create(p);
    printf("\n");
}

void FloatBT_Postorder_create ( FloatNode *p ) {
    if(p){
        FloatBT_Postorder_create( p->lchild);
        FloatBT_Postorder_create( p->rchild);
        printf("%.3f ", p->data);
    }
}
void FloatBT_Postorder ( FloatNode *p ) {
    printf("\n\nPost-order Traversal of Binary Tree : ");
    FloatBT_Postorder_create(p);
    printf("\n");
}

void FloatBT_Preorder_it ( FloatNode *p ) {
    FloatStack stk;
    Create_floatStk ( &stk, 100);
    printf("\nPre-order Traveral of Binary Tree using Iteration : ");

    while( p || !isEmpty_floatStk ){
        if(p){
            printf("%.3f ", p->data);
            Push_floatStk( &stk, p);
            p = p->lchild;
        }
        else{
            p = Pop_floatStk( &stk);
            p = p->rchild;
        }
    }
    printf("\n");
}

void FloatBT_Inorder_it ( FloatNode *p) {
    FloatStack stk;
    Create_floatStk( &stk, 100);
    printf("\nIn-order Traveral of Binary Tree using Iteration : ");

    while( p || !isEmpty_floatStk(stk)){
        if(p){
            Push_floatStk( &stk, p);
            p = p->lchild;
        }
        else{
            p = Pop_floatStk(&stk);
            printf("%.3f ", p->data);
            p = p->rchild;
        }
    }
    printf("\n");
}
//Postorder Traversal of Int type Binary Tree using Iterations.
// void Postorder_it(FloatNode *p){
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
//             p = ((FloatNode *)temp->)
//         }
//     }
// }

void FloatBT_Levelwise_it( FloatNode *p){
    FloatQueue q;
    Create_FloatQ( &q, 100);
    printf("\n\nLevel-wise Traversal of Binary Tree using Iteration : ");
    printf("%.3f ",p->data);
    enqueue_FloatQ( &q, p);

    while(!isEmpty_FloatQ(q)){
        p = dequeue_FloatQ(&q);
        if(p->lchild){
            printf("%.3f ",p->lchild->data);
            enqueue_FloatQ(&q, p->lchild);
        } 
        if(p->rchild){
            printf("%.3f ",p->rchild->data);
            enqueue_FloatQ(&q, p->rchild);
        }
    }
    printf("\n");
}

int Cal_height_FloatBT ( FloatNode *p) {
    int lHeight = 0, rHeight = 0;
    if( p == NULL )
        return 0;
    else{
        lHeight = Cal_height_FloatBT( p->lchild);
        rHeight = Cal_height_FloatBT( p->rchild);
        if( lHeight > rHeight)
            return lHeight + 1;
        else
            return rHeight + 1;
    }
}
void FloatBT_Height( FloatNode *p){
    printf("\nThe Height of the Binary Tree is : %d ", Cal_height_FloatBT(p) - 1);
    printf("\n");
}

int Cal_Nodes_FloatBT ( FloatNode *p) {
    int x, y;
    if(p){
        x = Cal_Nodes_FloatBT(p->lchild);
        y = Cal_Nodes_FloatBT(p->rchild);
        return (x + y + 1);
    }
    return 0;
}
void FloatBT_CountNodes ( FloatNode *p) {
    printf("\nNumber of Nodes in Binary Tree are : %d ", Cal_Nodes_FloatBT(p));
    printf("\n");
}

void FloatBT_PrintLevel ( FloatNode *p, int level ){ 
    if( !p)
        return ;

    if( level == 0)
        printf("%.3f ", p->data);
    else{
        FloatBT_PrintLevel( p->lchild, level - 1);
        FloatBT_PrintLevel( p->rchild, level - 1);
    }
}
//( secondary function to print level wise using recursion)
void FloatBT_Levelwise ( FloatNode *p) {
    int i, height = Cal_height_FloatBT(p);
    printf("Level-wise Traversal of Binary Tree : \n");
    for ( i = 0; i < height; i++){
        printf("Level [%d] : ", i + 1);
        FloatBT_PrintLevel( p, i);
        printf("\n");
    }
    printf("\n");
}


int cal_Deg2_Nodes_FloatBT (FloatNode *p ){
    int x, y;
    if(p){
        x = cal_Deg2_Nodes_FloatBT( p->lchild);
        y = cal_Deg2_Nodes_FloatBT( p->rchild);
        if( p->lchild && p->rchild){
            printf("%.3f ", p->data);
            return (x + y + 1);
        }
        else
            return (x + y);
    }
    return 0;
}
void FloatBT_Deg2_nodes ( FloatNode *p) {
    printf("\n\nNumber of Nodes having Degree 2 : %d ", cal_Deg2_Nodes_FloatBT(p));
    printf("\n");
}

int cal_Deg1_Nodes_FloatBT ( FloatNode *p ) {
    int x, y;
    if(p){
        x = cal_Deg1_Nodes_FloatBT( p->lchild);
        y = cal_Deg1_Nodes_FloatBT( p->rchild);
        if( ( p->lchild && !p->rchild) || ( !p->lchild && p->rchild) ){
            printf("%.3f ", p->data);
            return ( x + y + 1);
        }
        else    
            return x + y;
    }
    return 0;
}
void FloatBT_Deg1_nodes ( FloatNode *p) {
    printf("\n\nNumber of Nodes having Degree 1 : %d ", cal_Deg1_Nodes_FloatBT(p));
    printf("\n");
}


int cal_Deg0_Nodes_FloatBT ( FloatNode *p) {
    int x, y;
    if(p){
        x = cal_Deg0_Nodes_FloatBT( p->lchild);
        y = cal_Deg0_Nodes_FloatBT( p->rchild);
        if( !p->lchild && ! p->rchild){
            printf("%.3f ", p->data);
            return ( x + y + 1 );
        }
        else
            return ( x + y );
    }
    return 0;
}
void FloatBT_LeafNodes ( FloatNode *p) { 
    printf("\n\nNumber of Nodes having Degree 0 i.e. Leaf Nodes : %d ", cal_Deg0_Nodes_FloatBT(p));
    printf("\n");
}

float cal_SumOfNodes_FloatBT ( FloatNode *p) {
    float x, y;
    if( p){
        x = cal_SumOfNodes_FloatBT( p->lchild);
        y = cal_SumOfNodes_FloatBT( p->rchild);
        return ( x + y + p->data);
    }
    return 0;
}
void FloatBT_SumNodes ( FloatNode *p){
    printf("\n\nSum of Nodes of  Binary Tree : %.3f ", cal_SumOfNodes_FloatBT(p));
    printf("\n");
}


void FloatBT_MirrorImage (FloatNode *p) {
    FloatNode *temp;
    if( p == NULL)
        return;
    else{
        FloatBT_MirrorImage(p->lchild);
        FloatBT_MirrorImage(p->rchild);
        temp = p->lchild ;
        p->lchild = p->rchild;
        p->rchild = temp;
    }
}



#endif /*binaryTree_float_h*/