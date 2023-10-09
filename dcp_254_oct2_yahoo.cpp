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