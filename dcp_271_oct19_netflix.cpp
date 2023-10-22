/**
 * Done
 * T.C.: O(logn)
 * S.C.: O(n)
 * Author: Vikas Gogia
*/

/**
 * Problem
This problem was asked by Netflix.

Given a sorted list of integers of length N, determine if an element x is in the list without performing any multiplication, division, or bit-shift operations.

Do this in O(log N) time.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> getFibSequence(int n) {
    vector<int> fib;
    int a=0, b=1;
    fib.push_back(a);
    while(a < n) {
        int temp=a;
        a=b;
        b=temp+b;
        fib.push_back(a);
    }
    return fib;
}

int fibonacciSearch(vector<int> v, int s) {
    int n = v.size();
    vector<int> fib = getFibSequence(n);
    int offset = -1, k = fib.size()-1;
    int i=0;
    if(fib[k] == 0) return -1;
    while(k > 0) {
        i = min(offset + fib[k-2], n-1);
        if(s == v[i]) return i;
        else if(s > v[i]) {
            k--;
            offset=i;
        }
        else k-=2;
    }
    return -1;
}

int main() {
    vector<int> v {4, 7, 11, 16, 27, 45, 55, 65, 80, 100};
    int s=4;
    int idx=fibonacciSearch(v, s);
    cout << (idx == -1 ? "Not found! " : "Index = ") << idx;
    return 0;
}