#include <stdio.h>
#include <stdlib.h>

#ifndef AVLTree_int_h
#define AVLTree_int_h

typedef struct Int_Node
{
    struct Int_Node *lchild;
    int data;
    int height;
    struct Int_Node *rchild;
} IntAVLNode;

IntAVLNode *Int_AVL_root = NULL;

int IntAVL_NodeHeight(IntAVLNode *p)
{
    int hl, hr;
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return (hl > hr) ? hl + 1 : hr + 1;
}

int IntAVL_BalanceFact(IntAVLNode *p)
{
    int hl, hr;
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl - hr;
}

IntAVLNode *IntAVL_LL_Rotation(IntAVLNode *p)
{
    IntAVLNode *pl = p->lchild;
    IntAVLNode *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = IntAVL_NodeHeight(p);
    pl->height = IntAVL_NodeHeight(pl);
    printf("\ncheck\n");
    if (Int_AVL_root == p)
        Int_AVL_root = pl;

    return pl;
}

IntAVLNode *IntAVL_LR_Rotation(IntAVLNode *p)
{
    IntAVLNode *pl = p->lchild;
    IntAVLNode *plr = p->lchild->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;
    pl->height = IntAVL_NodeHeight(pl);
    p->height = IntAVL_NodeHeight(p);
    plr->height = IntAVL_NodeHeight(plr);

    if (Int_AVL_root == p)
        Int_AVL_root = plr;

    return plr;
}

IntAVLNode *IntAVL_RR_Rotation(IntAVLNode *p)
{
    IntAVLNode *pr = p->rchild;
    IntAVLNode *prl = p->rchild->lchild;

    pr->lchild = p;
    p->lchild = prl;
    p->height = IntAVL_NodeHeight(p);
    pr->height = IntAVL_NodeHeight(pr);

    if (Int_AVL_root == p)
        Int_AVL_root = pr;
    return pr;
}

IntAVLNode *IntAVL_RL_Rotation(IntAVLNode *p)
{
    IntAVLNode *pr = p->rchild;
    IntAVLNode *prl = p->rchild->lchild;

    pr->lchild = prl->rchild;
    p->lchild = prl->lchild;
    prl->lchild = p;
    prl->rchild = pr;
    p->height = IntAVL_NodeHeight(p);
    pr->height = IntAVL_NodeHeight(pr);
    prl->height = IntAVL_NodeHeight(prl);

    if (Int_AVL_root == p)
        Int_AVL_root = prl;
    return prl;
}

IntAVLNode *IntAVL_RInsert(IntAVLNode *p, int key)
{
    IntAVLNode *t = NULL;
    if (p == NULL)
    {
        t = (IntAVLNode *)malloc(sizeof(IntAVLNode));
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
        p->lchild = IntAVL_RInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = IntAVL_RInsert(p->rchild, key);

    p->height = IntAVL_NodeHeight(p);

    if (IntAVL_BalanceFact(p) == 2 && IntAVL_BalanceFact(p->lchild) == 1)
        return IntAVL_LL_Rotation(p);
    else if (IntAVL_BalanceFact(p) == 2 && IntAVL_BalanceFact(p->lchild) == -1)
        return IntAVL_LR_Rotation(p);
    else if (IntAVL_BalanceFact(p) == -2 && IntAVL_BalanceFact(p->rchild) == -1)
        return IntAVL_RR_Rotation(p);
    else if (IntAVL_BalanceFact(p) == -2 && IntAVL_BalanceFact(p->rchild) == 1)
        return IntAVL_RL_Rotation(p);

    return p;
}

void Int_CreateAVL()
{
    int key;
    printf("\nEnter Node value : ");
    scanf("%d", &key);

    if (key == -1)
    {
        return;
    }
    Int_AVL_root = IntAVL_RInsert(Int_AVL_root, key);

    while (1)
    {
        printf("\nEnter Node value : ");
        scanf("%d", &key);

        if (key == -1)
            break;
        IntAVL_RInsert(Int_AVL_root, key);
    }
}

void IntAVL_Preorder_create(IntAVLNode *p)
{
    if (p)
    {
        printf("%d ", p->data);
        IntAVL_Preorder_create(p->lchild);
        IntAVL_Preorder_create(p->rchild);
    }
}
void IntAVL_Preorder(IntAVLNode *p)
{
    if (p)
    {
        printf("\nPre-order traversal : ");
        IntAVL_Preorder_create(p);
        printf("\n");
    }
    else
    {
        printf("\nRoot is Null\n");
    }
}

void IntAVL_Inorder_create(IntAVLNode *p)
{
    if (p)
    {
        IntAVL_Inorder_create(p->lchild);
        printf("%d ", p->data);
        IntAVL_Inorder_create(p->rchild);
    }
}
void IntAVL_Inorder(IntAVLNode *p)
{
    if (p)
    {
        printf("\nIn-order traversal : ");
        IntAVL_Inorder_create(p);
        printf("\n");
    }
    else
    {
        printf("\nRoot is Null\n");
    }
}

void IntAVL_Postorder_create(IntAVLNode *p)
{
    if (p)
    {
        IntAVL_Postorder_create(p->lchild);
        IntAVL_Postorder_create(p->rchild);
        printf("%d ", p->data);
    }
}
void IntAVL_Postorder(IntAVLNode *p)
{
    if (p)
    {
        printf("\nPost-order traversal : ");
        IntAVL_Postorder_create(p);
        printf("\n");
    }
    else
    {
        printf("\nRoot is Null\n");
    }
}

void IntAVL_traverse(IntAVLNode *p)
{
    IntAVL_Preorder(p);
    IntAVL_Inorder(p);
    IntAVL_Postorder(p);
}

#endif /*AVLTree_int_h*/