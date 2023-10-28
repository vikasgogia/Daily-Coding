/**
 * Done
 * T.C.: O(n*(2^n)) each tree takes O(n) time and there can be 2^n trees possible --> catalan numbers
 * S.C.: O(n*(2^n))
 * Author: Vikas Gogia
*/

/**
 * Problem
This problem was asked by Amazon.

Given an integer N, construct all possible binary search trees with N nodes.
*/

#include <iostream>
#include<vector>
using namespace std;

class Node {
    public:
    Node *left, *right;
    int data;

    Node(int data, Node* left, Node* right) {
        this -> left = left;
        this -> right = right;
        this -> data = data;
    } 
};

void preOrderTraversal(Node* root) {
    // base case
    if(root == NULL) {
        cout << "NULL -> ";
        return;
    }

    cout << root->data << " -> ";
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);
}

vector<Node*> constructAllPossibleBSTs(int s, int e) {
    vector<Node*> trees;

    // base case
    if(s > e) {
        trees.push_back(NULL);
        return trees;
    }

    for(int i=s; i <= e; i++) {
        vector<Node*> leftSubtree = constructAllPossibleBSTs(s, i-1);
        vector<Node*> rightSubtree = constructAllPossibleBSTs(i+1, e);
        for(Node* l: leftSubtree) {
            for (Node* r: rightSubtree) {
                trees.push_back(new Node(i, l, r));
            }
        }
    }
    return trees;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<Node*> trees = constructAllPossibleBSTs(1, n);
    for (Node* tree: trees) {
        preOrderTraversal(tree);
        cout << endl;
    }
    return 0;
}