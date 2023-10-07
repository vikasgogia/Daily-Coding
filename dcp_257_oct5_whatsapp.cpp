/**
 * Done
 * T.C.: O(n)
 * S.C.: O(1)
 * Author: Vikas Gogia
*/

/**
 * Problem
This problem was asked by WhatsApp.

Given an array of integers out of order, determine the bounds of the smallest window that must be sorted in order for the entire array to be sorted. For example, given [3, 7, 5, 6, 9], you should return (1, 3).
*/

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

// this function checks for a breaking point and finds for endIdx (hard logic)
// finds startIdx by running a loop from 0 to assumed startIdx
pair<int, int> minSubarrayToBeSorted(vector<int> v, int n) {
    int min = INT_MAX;
    int max = INT_MIN, tempMax = INT_MIN;
    bool isBroken = 0;
    int startIdx = -1, endIdx = -1;

    for(int i=0; i< n; i++) {
        if(v[i] > v[i+1] && !isBroken && i != n-1) {
            // breaking point
            max = v[i];
            tempMax = v[i];
            min = v[i+1];
            startIdx = i;
            endIdx = i+1;
            isBroken = 1;
        }

        else if(isBroken) {
            if(v[i] > tempMax) tempMax = v[i];

            else if((v[i]< max && v[i] > min) || v[i] < min) {
                max = tempMax;
                endIdx = i;
            }

            if(v[i] < min) min = v[i];
        }
    }

    for(int i=0; i< startIdx; i++) {
        if(v[i]< max && v[i] > min) {
            startIdx = i;
            break;
        }
    }
    return make_pair(startIdx, endIdx);
}

// this function simply finds endIdx by finding the last min element that is greater than the max element before it
// and finds startIdx by finding the first min element that is greater than minimum before it
pair<int, int> minSubarrayToBeSorted2(vector<int> v, int n) {
    int startIdx = -1, endIdx = -1;
    int maxSeen = INT_MIN;
    int minSeen = INT_MAX;

    // right to left to find first min element to minSeen
    for(int i=n-1; i>= 0; i--) {
        minSeen = min(v[i], minSeen);
        if(v[i] > minSeen) startIdx = i;
    }

    // left to right to find last min element to maxSeen
    for(int i=0; i< n; i++) {
        maxSeen = max(maxSeen, v[i]);
        if(v[i] < maxSeen) endIdx = i;
    }

    return make_pair(startIdx, endIdx);
}


int main() {
    vector<int> v{2, 3, 7, 5, 8, 6, 10, 1, 9};
    // vector<int> v{3, 7, 15, 16, 19};
    pair<int, int> p = minSubarrayToBeSorted2(v, v.size());
    cout << "(" << p.first << ", " << p.second << ")";
    return 0;
}