/**
 * Done
 * T.C.: O(n)
 * S.C.: O(1)
 * Author: Vikas Gogia
*/

/**
 * Problem
This problem was asked by Yahoo.

Recall that a full binary tree is one in which each node is either a leaf node, or has two children. Given a binary tree, convert it to a full one by removing nodes with only one child.

For example, given the following tree:

         0
      /     \
    1         2
  /            \
3                 4
  \             /   \
    5          6     7
You should convert it to:

     0
  /     \
5         4
        /   \
       6     7
*/

#include "data_structures/trees/BinaryTree.cpp"
#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

Node* convertToFullBT(Node* root) {
    if(root == NULL || (root->left == NULL && root->right == NULL)) {
        // leaf node
        return root;
    }
    
    if(root->left != NULL && root->right != NULL) {
        root->left = convertToFullBT(root->left);
        root->right = convertToFullBT(root->right);
        return root;
    }
    // if left or right's null, remove the current node by sending 
    // the recursive answer directly to the ancestor node
    return convertToFullBT(root->left == NULL ? root->right : root -> left);
}

int main() {
    BinaryTree tree = BinaryTree();
    tree.createBinaryTree();

    Node* root = convertToFullBT(tree.getRootForEducationalPurposes());
    tree.setRootForEducationalPurposes(root);
    tree.inorderTraversal();
    return 0;
}