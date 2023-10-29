/**
 * Done
 * T.C.: O(n + k)
 * auxillary S.C.: O(k)
 * Author: Vikas Gogia
*/

/**
 * Problem
This problem was asked by Dropbox.

Implement an efficient string matching algorithm.

That is, given a string of length N and a pattern of length k, write a program that searches for the pattern in the string with less than O(N * k) worst-case time complexity.

If the pattern is found, return the start index of its location. If not, return False.
*/

#include <iostream>
#include<vector>
using namespace std;

/* https://www.youtube.com/watch?v=4jY57Ehc14Y */

vector<int> computeLPSArray(string pattern) {
    vector<int> lps(pattern.length(), 0);
    int len = 0;

    for(int i=1; i< lps.size();) {
        if(pattern[i] == pattern[len]) {
            // if there's a match assign the longest prefix length
            lps[i++] = len+1;
            len++;
        } 
        else {
            if(len == 0)
                lps[i++] = 0;
            else {
                // checking will now start from the index after longest prefix for the last index
                len = lps[len-1];
            }
        }
    }
    return lps;
}

int KMPSearch(string input, string pattern) {
    vector<int> lps = computeLPSArray(pattern); // compute prefix and suffix
    int j = 0;

    for(int i=0; i< input.length();) {
        if(pattern[j] == input[i]) {
            i++;
            j++;
        } else {
            if(j == 0)
                i++;
            else 
                j = lps[j-1];
        }
        if(j == pattern.length())
            return i-j;
    }
    return -1;
}

int main() {
    // string input = "onionionspl";
    string input = "aaabaac";
    string pattern = "aac";
    // string pattern = "onions";
    cout << "index = " << KMPSearch(input, pattern);
    return 0;
}