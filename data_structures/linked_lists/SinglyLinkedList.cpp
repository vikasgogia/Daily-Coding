#include<iostream>
using namespace std;

/**
* LL Node
* (data, next)
**/
class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    ~Node() {
        // before deleting current node, delete the next if not null
        if(next != NULL) {
            delete next;    
            this -> next = NULL;
        }
    }
};

class SinglyLinkedList {
    int length;
    Node* head;
    Node* tail; 

    public:
    SinglyLinkedList() {
        length = 0;
        head = NULL;
        tail = NULL;
    }

    /**
     * print a LL 
     * O(n)
    **/
    void print() {
        cout << endl;

        Node* temp = head;
        while(temp != NULL) {
            cout << temp -> data << " -> ";
            temp = temp -> next;
        }
        cout << "\nsize: " << length << endl << endl;
    }

    /**
     * insert a node at head/ start 
     * O(1)
    **/
    void insertAtHead(int data) {
        Node* newNode = new Node(data);
        newNode -> next = head;

        if(head == NULL && tail == NULL) {
            tail = head = newNode;
        }
        else {
            head = newNode;
        }
        length++;
    }

    /**
     * insert a node at tail/ end 
     * O(1)
    **/
    void insertAtTail(int data) {
        Node* newNode = new Node(data);

        if(head == NULL && tail == NULL) {
            tail = head = newNode;
        }
        else {
            tail -> next = newNode;
            tail = newNode;
        }
        length++;
    }

    /**
     * insert a node at any position in a LL (1-indexed) 
     * O(n)
    **/
    void insertAt(int position, int data) {
        // index out of bounds
        if(position > length + 1 || position <= 0) {
            return;
        }
        
        Node* temp = head;
        
        if(position == 1) {
            insertAtHead(data);
        } 
        else {
            // traverse until temp->next node's position == position
            for(int i=1; i< position-1; i++) {
                temp = temp -> next;
            }
            if(temp->next == NULL) {
                // insert at tail
                insertAtTail(data);
            } 
            else {
                Node* newNode = new Node(data);
                newNode -> next = temp -> next;
                temp -> next = newNode;
                length++;
            }
        }
    }

    /**
     * delete a node at head/ start
     * O(1)
    **/
    void deleteAtHead() {
        if(head == NULL) {
            return;
        }

        Node* curr = head;
        if(head == tail) {
            tail = NULL;
        } 
        head = head -> next;

        // delete the node
        curr -> next  = NULL;
        delete curr;
        length--;
    }

    /**
     * delete a node at any position 
     * O(n)
    **/
    void deleteAt(int position) {
        Node* curr = head;
        Node* prev = NULL;

        if(position > length) {
            return;
        }

        if(position == 1) {
            deleteAtHead();
            return;
        }
        // traverse until curr's node position == position
        for(int i=1; i< position; i++) {
            prev = curr;
            curr = curr -> next;
        }
        if(curr -> next == NULL) {
            // deletion at tail
            tail = prev;    
        }
        prev -> next = curr -> next;
        
        // delete the node
        curr -> next = NULL;
        delete curr;
        length--;
    }

    /**
     * returns LL length 
     * O(1)
    **/
    int size() {
        return length;
    }

    Node* getHeadForEducationalPurposes() {
        return head;
    }
};