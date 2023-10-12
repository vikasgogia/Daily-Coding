/**
 * Done
 * T.C.: O(n2)
 * S.C.: O(n)
 * Author: Vikas Gogia
*/

/**
 * Problem
This problem was asked by Yelp.

You are given an array of integers, where each element represents the maximum number of steps that can be jumped going forward from that element. Write a function to return the minimum number of jumps you must take in order to get from the start to the end of the array.

For example, given [6, 2, 4, 0, 5, 1, 1, 4, 2, 9], you should return 2, as the optimal solution involves jumping from 6 to 5, and then from 5 to 9.
*/
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

// memoized approach reducing complexity from O(N!) to O(N2)
int findMinJumps(int *arr, int n, int i, vector<int> &minJumps) {
    if(i == n-1) minJumps[i] = 0;
    else if(arr[i] == 0) minJumps[i] = -1;

    if(minJumps[i] != -2) return minJumps[i];

    int value = arr[i];
    int minSteps = INT_MAX;

    for(int j=1; j<= value; j++) {
        if(i+j >= n) break;
        int steps = findMinJumps(arr, n, i+j, minJumps);
        minSteps = steps != -1 ? min(minSteps, steps) : minSteps;
    }
    minJumps[i] = minSteps + 1;
    return minJumps[i];
}

int main() {
    // int arr[] = {2, 3, 0, 1, 4, 5};
    int arr[] = {6, 2, 4, 0, 5, 1, 1, 4, 2, 9};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    vector<int> minJumps(arrSize, -2);
    cout << findMinJumps(arr, arrSize, 0, minJumps)<< endl;
}