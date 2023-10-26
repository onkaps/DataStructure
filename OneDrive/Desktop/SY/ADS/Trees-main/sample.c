#include "binarySearchTree_string.h"

int main()
{
  // String_CreateBST();
  StringBST_Insert("onkar");
  StringBST_Insert("on");
  StringBST_Insert("kapuskari");
  inorder(String_BST_root);

  return 0;
}

/*

   A
 /  \
B    C

      A
     / \
    /   \
   B     C
  / \   / \
 D   E F   G

          A
      /      \
     /        \
    /          \
    B           C
   / \         / \
  /   \       /   \
  D   E       F    G


*/

/*

*/