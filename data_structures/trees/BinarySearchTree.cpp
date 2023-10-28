#include <iostream>
#include<vector>
using namespace std;

class Node {
    public:
    Node *left, *right;
    int data;

    Node(int data) {
        left = right = NULL;
        this -> data = data;
    } 
};

class BinarySearchTree {
    Node *root;

    Node* insertToBST(Node *node, int data) {
         
        if(node == NULL) {
            node = new Node(data);
            return node;
        }

        if(data <= node -> data) {
            // left subtree
            node -> left = insertToBST(node -> left, data);
        } 
        else {
            // right subtree
            node -> right = insertToBST(node -> right, data);
        }
        return node;
    }

    Node* deleteFromBST(Node *node, int x) {

        if(node == NULL) {
            return NULL;
        }

        // delete
        if(node -> data == x) {
    
            // case: no of child = 0
            if(node-> right == NULL && node->left == NULL) {
                delete node;
                return NULL;
            }
            // case: no of child = 1
            else if(node-> right == NULL && node->left != NULL) {
                Node *temp = node->left;
                delete node;
                return temp;
            } 
            else if(node-> right != NULL && node->left == NULL) {
                Node *temp = node->right;
                delete node;
                return temp;
            } 
            // case: no of child = 2
            else if(node-> right != NULL && node->left != NULL) {
                Node *mini = findMin(node->right);
                node->right = deleteFromBST(node->right, mini->data);
                node->data = mini -> data;
                return node;
            }
        }

        if(node -> data < x) {
            // in right subtree
            node -> right = deleteFromBST(node -> right, x);
        }
        else {
            // in left subtree
            node -> left = deleteFromBST(node -> left, x);
        }
        return node;
    }

    void traversalInOrder(Node* node, vector<int> &v) {
        // LNR
        if(node == NULL) {
            return;    
        }    
        traversalInOrder(node->left, v);
        v.push_back(node->data);
        traversalInOrder(node->right, v);
    }

    Node* findMin(Node* node) {

        Node *temp = node;
        while(temp -> left != NULL) {
            temp = temp -> left;
        }
        return temp;
    }

    Node* findMax(Node* node) {

        Node *temp = node;
        while(temp -> right != NULL) {
            temp = temp -> right;
        }
        return temp;
    }

    public:
    BinarySearchTree() {
        root = NULL;
    }

    Node* getRootForEducationalPurposes() {
        return root;
    }

    void insertToBST(int data) {
        root = insertToBST(root, data);
    }

    void deleteFromBST(int x) {
        root = deleteFromBST(root, x);
    }
};
