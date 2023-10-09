#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node {
        public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

class BinaryTree {
    
    Node* root;
    
    Node* createBinaryTree(Node* root) {
        int data;
        cout << "Enter node's data: ";
        cin >> data;
        root = new Node(data);

        if(data == -1) {
            // it's a leaf node
            return NULL;
        }
        cout << "\n" << data << "'s left - ";
        root->left = createBinaryTree(root->left); // R.R. 1

        cout << "\n" << data << "'s right - ";
        root->right = createBinaryTree(root->right); // R.R. 2
        return root;
    }

    void inorderTraversal(Node* root) {
        if(root == NULL)
            return;
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }

    void preorderTraversal(Node* root) {
        if(root == NULL)
            return;
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }

    void postorderTraversal(Node* root) {
        if(root == NULL)
            return;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }

    public:    
    BinaryTree() {
        root = NULL;
    }

    Node* getRootForEducationalPurposes() {
        return root;
    }

    void setRootForEducationalPurposes(Node* node) {
        this->root = node;
    }

    void createBinaryTree() {
        this->root = createBinaryTree(root);
    }

    void levelOrderTraversal() {
        // always use queue for Breadth First Search like concepts
        // need to use a separator(NULL) for level wise printing 
        queue<Node*> q;
        q.push(this->root);
        q.push(NULL);

        while(!q.empty()) {
            Node* n = q.front();
            q.pop();
            if(n == NULL && !q.empty()) {
                cout << endl;
                q.push(NULL);
                continue;
            }
            cout << n->data << " ";
            if(n->left != NULL) q.push(n->left);
            if(n->right != NULL) q.push(n->right);
        }
    }

    void reverseLevelOrderTraversal() {
        stack<int> s;
        queue<Node*> q;
        q.push(this->root);

        while(!q.empty()) {
            Node* n = q.front();
            q.pop();
            s.push(n->data);
            if(n->right != NULL) 
                q.push(n->right);

            if(n->left != NULL) 
                q.push(n->left);
        }
        while(!s.empty()) {
            int data = s.top();
            s.pop();
            cout << data << " ";
        }
    }

    void inorderTraversal() {
        inorderTraversal(root);
    }

    void inorderIterative() {
        if(root == NULL)
            return;
        stack<Node*> s;
        s.push(root);
        Node* n = root->left;
        
        while(true) {
            if(n != NULL) {
                s.push(n);
                n = n->left;
            } 
            else {
                if(s.empty()) break;
                Node* top = s.top();
                s.pop();
                cout << top->data << " ";
                n = top->right;
            }
        }
    }

    void preorderTraversal() {
        preorderTraversal(root);
    }

    void postorderTraversal() {
        postorderTraversal(root);
    }
};