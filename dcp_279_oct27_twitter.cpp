/**
 * Done
 * T.C.: O(n)
 * auxillary S.C.: O(n)
 * Author: Vikas Gogia
*/

/**
 * Problem
This problem was asked by Twitter.

A classroom consists of N students, whose friendships can be represented in an adjacency list. For example, the following descibes a situation where 0 is friends with 1 and 2, 3 is friends with 6, and so on.

{
 0: [1, 2],
 1: [0, 5],
 2: [0],
 3: [6],
 4: [],
 5: [1],
 6: [3]
} 
Each student can be placed in a friend group, which can be defined as the transitive closure of that student's friendship relations. In other words, this is the smallest set such that no student in the group has any friends outside this group. For the example above, the friend groups would be {0, 1, 2, 5}, {3, 6}, {4}.

Given a friendship list such as the one above, determine the number of friend groups in the class.
*/

#include <iostream>
#include<vector>
using namespace std;

void makeFriendGroup(vector<vector<int>> &adj, vector<bool> &vis, int s) {    
    if(vis[s]) return;
    vis[s] = 1;
    for(int j=0; j< adj[s].size(); j++) {
        int fr = adj[s][j];
        if(vis[fr]) continue;
        makeFriendGroup(adj, vis, fr);
    }
}

int getNoOfFriendGroups(vector<vector<int>> &adj) {
    vector<bool> vis(adj.size(), 0);
    // keeps track of the number of recursive calls
    int count = 0;
    for(int i=0; i< adj.size(); i++) {
        if(vis[i]) continue;
        makeFriendGroup(adj, vis, i);
        count++;
    }
    return count;
}

int main() {
    vector<vector<int>> adj;
    int n, element;
    cout << "Enter number of students: ";
    cin >> n;
    for(int i=0; i< n; i++) {
        cout << "Enter friends of " << i << " : ";
        cin >> element;
        vector<int> v;
        while(element != -1) {
            v.push_back(element);
            cin >> element;
        }
        adj.push_back(v);
    }
    cout << getNoOfFriendGroups(adj);
    return 0;
}