/**
 * Done
 * T.C.: O(n)
 * S.C.: O(1)
 * Author: Vikas Gogia
*/

/**
 * Problem
This problem was asked by Fitbit.

Given a linked list, rearrange the node values such that they appear in alternating low -> high -> low -> high ... form. For example, given 1 -> 2 -> 3 -> 4 -> 5, you should return 1 -> 3 -> 2 -> 5 -> 4.
*/

#include "data_structures/linked_lists/SinglyLinkedList.cpp"
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

// example: 7 6 10 5 2 1 3

// maintain prev and curr pointers where prev, curr, currNext are taken into consideration at a time
// prev is needs to be low, curr is high, & currNext is low again
void alternatingLowHigh(Node* head) {
    Node* prev = head;
    Node* curr = head->next;
    Node* currNext = NULL;

    while(curr != NULL) {
        if(prev->data > curr->data) {
            // swap (7 > 6)
            int temp = curr->data;
            curr->data = prev->data;
            prev->data = temp;
        }

        if(curr -> next == NULL) return;

        currNext = curr->next;
        if(currNext->data > curr->data) {
            // swap (10 > 7)
            int temp = curr->data;
            curr->data = currNext->data;
            currNext->data = temp;
        }

        // after 1st iteration: 6 10 7 5 2 1 3
        prev = curr->next; // 7
        curr = curr->next->next; // 5
    } 
}

int main() {
    SinglyLinkedList* ll = new SinglyLinkedList();

    int value;
    cout << "Enter Linked List Nodes: ";
    while(true) {
        cin >> value;
        if(value == -1) break;
        ll -> insertAtTail(value);
    }

    alternatingLowHigh(ll->getHeadForEducationalPurposes());
    ll->print();
    return 0;
}