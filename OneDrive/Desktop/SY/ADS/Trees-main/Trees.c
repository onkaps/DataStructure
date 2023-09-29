
#include "Trees.h"




int main () {
        // Int_CreateBT();
        // IntBT_Preorder(Int_root);
        // printf("\n");
        // IntBT_Inorder(Int_root);
        // printf("\n");
        // IntBT_Postorder(Int_root);
        // printf("\n");
        // IntBT_Preorder_it(Int_root);
        // printf("\n");
        // IntBT_Inorder_it(Int_root);
        // printf("\n");
        // IntBT_Levelwise_it(Int_root);
        // Levelwise(root);
        // IntBT_Height(Int_root);
        // IntBT_CountNodes(Int_root);
        // IntBT_Deg2_nodes(Int_root);
        // IntBT_SumNodes(Int_root);
        // IntBT_Deg1_nodes(Int_root);
        // IntBT_LeafNodes( Int_root);
        // IntBT_Levelwise(Int_root);

    // Char_CreateBT();
    // CharBT_Preorder(Char_root);

    // Float_CreateBT();
    // FloatBT_Preorder(Float_root);
    // FloatBT_Inorder(Float_root);
    // FloatBT_Postorder(Float_root);
    // FloatBT_Preorder_it(Float_root);
    // FloatBT_Inorder_it(Float_root);
    // FloatBT_Levelwise_it(Float_root);
    // FloatBT_Height(Float_root);
    // FloatBT_CountNodes(Float_root);
    // FloatBT_Levelwise(Float_root);
    // FloatBT_Deg2_nodes(Float_root);
    // FloatBT_Deg1_nodes(Float_root);
    // FloatBT_LeafNodes(Float_root);
    // FloatBT_MirrorImage(Float_root);
    // FloatBT_Preorder(Float_root);
    // FloatBT_Inorder(Float_root);
    // FloatBT_Postorder(Float_root);
    // FloatBT_SumNodes(Float_root);

    // Char_CreateBT();
    // CharBT_Preorder(Char_root);
    // CharBT_Inorder(Char_root);
    // CharBT_Postorder(Char_root);
    // CharBT_Preorder_it(Char_root);
    // CharBT_Inorder_it(Char_root);
    // CharBT_Levelwise_it(Char_root);
    // CharBT_Height(Char_root);
    // CharBT_CountNodes(Char_root);
    // CharBT_Levelwise(Char_root);
    // CharBT_Deg2_nodes(Char_root);
    // CharBT_Deg1_nodes(Char_root);
    // CharBT_LeafNodes(Char_root);
    // CharBT_MirrorImage(Char_root);
    // CharBT_Preorder(Char_root);

    // String_CreateBT();
    // StringBT_Preorder_create(String_root);

    // IntBST_Insert(45);
    // IntBST_Insert(15);
    // IntBST_Insert(79);
    // IntBST_Insert(90);
    // IntBST_Insert(10);
    // IntBST_Insert(55);
    // IntBST_Insert(12);
    // IntBST_Insert(20);
    // IntBST_Insert(50);
    // IntBST_Preorder(Int_BST_root);


    // Int_CreateBT();
    // IntBT_Inorder(Int_root);

    Int_CreateBST();
    IntBST_Inorder(Int_BST_root);

    // Char_CreateBST();
    // CharBST_Inorder(Char_BST_root);

    return 0;
}


/*
ERRORS TO BE FIXED .......=>
1. In binaryTree_int.h, postorder by iterative.
3. In binaryTree_float.h, preorder as well as postorder by iteration having logical error.
4. XOR operator is not executing in binaryTree_int.h file in function "cal_deg1_nodes ()" in int as well as float file.
5.presentation of outputs of each function in files.
7. Error in binaryTree_string.h file.


*/

/*
    DOCUMENTATION

    1. To create a binary tree, nodes having data-types int, float, char, string call the functions 'Int_CreateBT', 'Float_CreateBT', 'Char_CreateBT', String_CreateBT respectively.
        The roots of the Binary Trees created by the above function calls, are named by "Int_root", "Float_root", "Char_root", "String_root" respectively. 

    

*/
