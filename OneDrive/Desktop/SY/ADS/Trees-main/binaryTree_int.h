#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
#include "stack.h"

#ifndef binaryTree_int_h
#define binaryTree_int_h


IntNode *Int_root = NULL;



//Creates Int-type Binary Tree of Nodes having 'int' data type
void Int_CreateBT () {
    IntNode *p, *t;
    int x;
    IntQueue q;
    Create_IntQ ( &q, 100 );

    printf("Enter root Node    : ");
    scanf("%d",&x);
    Int_root = (IntNode *)malloc(sizeof(IntNode));
    Int_root->data = x;
    Int_root->lchild = Int_root->rchild = NULL;
    enqueue_IntQ ( &q, Int_root );

    while( !isEmpty_IntQ(q) ) {

        p = dequeue_IntQ(&q);

        printf("Enter left child of %d  : ", p->data);
        scanf("%d",&x);
        if( x != -1){
            t = (IntNode *)malloc(sizeof(IntNode));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue_IntQ(&q, t);
        }

        printf("Enter right child of %d : ",p->data);
        scanf("%d",&x);
        if( x != -1){
            t = (IntNode *)malloc(sizeof(IntNode));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue_IntQ (&q, t);
        }
    }
}

//Preorder Traversal of Int-type Binary Tree using Recursion.
void IntBT_Preorder_create (IntNode *p) {
    if(p){
        printf("%d ",p->data);
        IntBT_Preorder_create(p->lchild);
        IntBT_Preorder_create(p->rchild);
    }
}
//Function to print the Pre-order Traversal of Int-type Binary Tree.
void IntBT_Preorder ( IntNode *p ){
    printf("\n\nPre-order Traversal of Binary Tree : ");
    IntBT_Preorder_create(p);
    printf("\n");
}

//Inorder Traversal of Int-type Binary Tree using Recursion.
void IntBT_Inorder_create (IntNode *p) {
    if(p){
        IntBT_Inorder_create(p->lchild);
        printf("%d ",p->data);
        IntBT_Inorder_create(p->rchild);
    }
}
//Function to print the In-order Traversal of Int-type Binary Tree.
void IntBT_Inorder ( IntNode *p ) {
    printf("\n\n    Pre-order Traversal of Binary Tree : ");
    IntBT_Inorder_create(p);
    printf("\n");
}

//Postorder Traversal of Int-type Binary Tree using Recursion.
void IntBT_Postorder_create (IntNode *p) {
    if(p){
        IntBT_Postorder_create(p->lchild);
        IntBT_Postorder_create(p->rchild);
        printf("%d ",p->data);
    }
}
//Function to print the In-order Traversal of Int-type Binary Tree.
void IntBT_Postorder ( IntNode *p){
    printf("\nPost-order Traversal of Binary Tree : ");
    IntBT_Postorder_create(p);
    printf("\n");    
}

//Postorder Traversal of Int type Binary Tree using Iterations.
void IntBT_Preorder_it(IntNode *p){
    IntStack stk;
    Create_intStk( &stk, 100);
    printf("\nPre-order Traveral of Binary Tree using Iteration : ");

    while( p || !isEmpty_intStk(stk)){
        if(p){
            printf("%d ",p->data);
            Push_intStk( &stk, p);
            p = p->lchild;
        }
        else{
            p = Pop_intStk(&stk);
            p = p->rchild;
        }
    }
}

//Inorder Traversal of Int type Binary Tree using Iterations.
void IntBT_Inorder_it(IntNode *p){
    IntStack stk;
    Create_intStk( &stk, 100);
    printf("\nIn-order Traveral of Binary Tree using Iteration : ");

    while( p || !isEmpty_intStk(stk)){
        if(p){
            Push_intStk( &stk, p);
            p = p->lchild;
        }
        else{
            p = Pop_intStk(&stk);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
    
}

//Postorder Traversal of Int type Binary Tree using Iterations.
// void Postorder_it(IntNode *p){
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
//             p = ((IntNode *)temp->)
//         }
//     }
// }

//Level-wise Traversal of Int type Binary Tree using Iteration
void IntBT_Levelwise_it( IntNode *p){
    IntQueue q;
    Create_IntQ( &q, 100);

    printf("%d ",p->data);
    enqueue_IntQ( &q, p);

    while(!isEmpty_IntQ(q)){
        p = dequeue_IntQ(&q);
        if(p->lchild){
            printf("%d ",p->lchild->data);
            enqueue_IntQ(&q, p->lchild);
        } 
        if(p->rchild){
            printf("%d ",p->rchild->data);
            enqueue_IntQ(&q, p->rchild);
        }
    }
}

// Function calculates Height of Int type Binary Tree 
int Cal_Height_IntBT ( IntNode *p) {
    int lHeight = 0, rHeight = 0;
    if( p == NULL )
        return 0;
    else{
        lHeight = Cal_Height_IntBT( p->lchild);
        rHeight = Cal_Height_IntBT( p->rchild);
        if( lHeight > rHeight)
            return lHeight + 1;
        else
            return rHeight + 1;
    }
}
//Function to Print Height of the Int type Binary Tree.
void IntBT_Height( IntNode *p){
    printf("\n\nThe Height of the Binary Tree is : %d ", Cal_Height_IntBT(p) - 1);
    printf("\n");
}

//Function to calculate no. of nodes present in Binary tree.
int Cal_Nodes_IntBT ( IntNode *p) {
    int x, y;
    if(p){
        x = Cal_Nodes_IntBT(p->lchild);
        y = Cal_Nodes_IntBT(p->rchild);
        return (x + y + 1);
    }
    return 0;
}
//function to print no. of nodes in Binary Tree.
void IntBT_CountNodes ( IntNode *p) {
    printf("\nNumber of Nodes in Binary Tree are : %d ", Cal_Nodes_IntBT(p));
    printf("\n");
}


//Function printing nodes level-wise Traversal using recursion( primary function)
void IntBT_PrintLevel ( IntNode *p, int level ){ 
    if( !p)
        return ;
    
    if( level == 0)
        printf("%d ", p->data);
    else{
        IntBT_PrintLevel( p->lchild, level - 1);
        IntBT_PrintLevel( p->rchild, level - 1);
    }
}
//( secondary function to print level wise using recursion)
void IntBT_Levelwise ( IntNode *p) {
    int i, height = Cal_Height_IntBT(p);
    printf("Level-wise Traversal of Binary Tree : \n");
    for ( i = 0; i < height; i++){
        printf("Level [%d] : ", i + 1);
        IntBT_PrintLevel( p, i);
        printf("\n");
    }
    printf("\n");
}

int cal_Deg2_Nodes_IntBT (IntNode *p ){
    int x, y;
    if(p){
        x = cal_Deg2_Nodes_IntBT( p->lchild);
        y = cal_Deg2_Nodes_IntBT( p->rchild);
        if( p->lchild && p->rchild){
            printf("%d ", p->data);
            return (x + y + 1);
        }
        else
            return (x + y);
    }
    return 0;
}
void IntBT_Deg2_nodes ( IntNode *p) {
    printf("\n");
    printf("\nNumber of Nodes having Degree 2 : %d ", cal_Deg2_Nodes_IntBT(p));
}

int cal_Deg1_Nodes_IntBT ( IntNode *p ) {
    int x, y;
    if(p){
        x = cal_Deg1_Nodes_IntBT( p->lchild);
        y = cal_Deg1_Nodes_IntBT( p->rchild);
        if( ( p->lchild && !p->rchild) || ( !p->lchild && p->rchild) ){
            printf("%d ", p->data);
            return ( x + y + 1);
        }
        else    
            return x + y;
    }
    return 0;
}
void IntBT_Deg1_nodes ( IntNode *p) {
    printf("\n");
    printf("\nNumber of Nodes having Degree 1 : %d ", cal_Deg1_Nodes_IntBT(p));
}

int cal_Deg0_Nodes_IntBT ( IntNode *p) {
    int x, y;
    if(p){
        x = cal_Deg0_Nodes_IntBT( p->lchild);
        y = cal_Deg0_Nodes_IntBT( p->rchild);
        if( !p->lchild && ! p->rchild){
            printf("%d ", p->data);
            return ( x + y + 1 );
        }
        else
            return ( x + y );
    }
    return 0;
}
void IntBT_LeafNodes ( IntNode *p) { 
    printf("\n");
    printf("\nNumber of Nodes having Degree 0 i.e. Leaf Nodes : %d ", cal_Deg0_Nodes_IntBT(p));
}


int cal_SumOfNodes_IntBT ( IntNode *p) {
    int x, y;
    if( p){
        x = cal_SumOfNodes_IntBT( p->lchild);
        y = cal_SumOfNodes_IntBT( p->rchild);
        return ( x + y + p->data);
    }
    return 0;
}
void IntBT_SumNodes ( IntNode *p){
    printf("\nSum of Nodes of  Binary Tree : %d ", cal_SumOfNodes_IntBT(p));
    printf("\n");
}

void IntBT_MirrorImage (IntNode *p) {
    IntNode *temp;
    if( p == NULL)
        return;
    else{
        IntBT_MirrorImage(p->lchild);
        IntBT_MirrorImage(p->rchild);
        temp = p->lchild ;
        p->lchild = p->rchild;
        p->rchild = temp;
    }
}

#endif /*binaryTree_int_h*/