/**
 * Done
 * T.C.: O(n*k)
 * S.C.: O(1)
 * Author: Vikas Gogia
*/

/**
 * Problem
This problem was asked by PayPal.

Given a string and a number of lines k, print the string in zigzag form. In zigzag, characters are printed out diagonally from top left to bottom right until reaching the kth line, then back up to top right, and so on.

For example, given the sentence "thisisazigzag" and k = 4, you should print:

t     a     g
 h   s z   a
  i i   i z
   s     g
*/

#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

string zigzagPattern(string s, int n, int k) {
    string ans = "";
    if(k <= 1) {
        return "\tk should be greater than 1\n\ttry again!";
    }

    for(int i=0; i< k; i++) {

        // front spaces loop
        for(int j=0; j< i; j++) {
            ans += " ";
        }

        // loop for finding next character in the same line
        int counter = i;
        bool isDec = 1;
        for(int j=i; j<n; j++) {
            if(counter == i) ans += s[j];
            else ans += " ";

            if(counter == k-1) {
                isDec = 0; // now ascending trend starts
            } else if(counter == 0) {
                isDec = 1; // now decreasing starts
            }
            counter += isDec ? 1 : (-1);
        }
        ans += "\n";
    }
    return ans;
}

int main() {
    string ans = zigzagPattern("thisisazigzag", 13, 1);
    cout << ans;
    return 0;
}