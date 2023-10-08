/**
 * Done
 * T.C.: O(n)
 * S.C.: O(n)
 * Author: Vikas Gogia
*/

/**
 * Problem
This problem was asked by Morgan Stanley.

In Ancient Greece, it was common to write text with the first line going left to right, the second line going right to left, and continuing to go back and forth. This style was called "boustrophedon".

Given a binary tree, write an algorithm to print the nodes in boustrophedon order.

For example, given the following tree:

       1
    /     \
  2         3
 / \       / \
4   5     6   7
You should return [1, 3, 2, 4, 5, 6, 7]
*/

#include "data_structures/trees/BinaryTree.cpp"
#include<iostream>
#include <stack>
using namespace std;

void boustrophedonOrderTraversal(Node* root) {
    stack<Node*> odd;
    stack<Node*> even;

    even.push(root);

    while(!even.empty() || !odd.empty()) {
        while(!even.empty()) {
            Node* top = even.top();
            even.pop();
            cout << top -> data << " ";
            if(top -> left != NULL) odd.push(top -> left);
            if(top -> right != NULL) odd.push(top -> right);
        }
        while(!odd.empty()) {
            Node* top = odd.top();
            odd.pop();
            cout << top -> data << " ";
            if(top -> right != NULL) even.push(top -> right);
            if(top -> left != NULL) even.push(top -> left);
        }
    }
}

int main() {
    BinaryTree tree = BinaryTree();
    tree.createBinaryTree();
    boustrophedonOrderTraversal(tree.getRootForEducationalPurposes());
    return 0;
}