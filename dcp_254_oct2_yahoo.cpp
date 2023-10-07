#include "data_structures/trees/BinaryTree.cpp"
#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

Node* convertToFullBT(Node* root, Node* parent, bool isLeft) {
    
    if(root -> left == NULL && root -> right != NULL) {
        // 1 child
        Node* temp = root -> right;
        if(isLeft) parent -> left = temp;
        else parent -> right = temp;
        root -> right = NULL;
        convertToFullBT(temp, parent, isLeft);
    }
    else if(root -> right == NULL && root -> left != NULL) {
        // 1 child
        Node* temp = root -> left;
        if(isLeft) parent -> left = temp;
        else parent -> right = temp;
        root -> left = NULL;
        convertToFullBT(temp, parent, isLeft);
    }
    convertToFullBT(root -> left, root, 1);
    convertToFullBT(root -> right, root, 0);
}

int main() {
    BinaryTree tree = BinaryTree();
    return 0;
}