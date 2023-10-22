/**
 * Done
 * T.C.: O(logn)
 * S.C.: O(1)
 * Author: Vikas Gogia
*/

/**
 * Problem
This problem was asked by Apple.

A fixed point in an array is an element whose value is equal to its index. Given a sorted array of distinct elements, return a fixed point, if one exists. Otherwise, return False.

For example, given [-6, 0, 2, 40], you should return 2. Given [1, 5, 7, 8], you should return False.
*/

#include <iostream>
#include <vector>
using namespace std;

// modified binary search algorithm
int getFixedPoint(vector<int> v) {
    int s=0, e=v.size()-1;
    int m = -1;
    while(s<=e) {
        m = (s+e)/2;
        if(v[m] == m) return m;
        else if(v[m] > m) e = m-1;
        else s = m+1;
    }
    return -1;
}

int main() {
    vector<int> v {-1, 1};
    int idx=getFixedPoint(v);
    cout << (idx == -1 ? "Not found! " : "Index = ") << idx;
    return 0;
}