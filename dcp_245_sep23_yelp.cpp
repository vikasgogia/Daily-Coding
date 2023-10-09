/**
 * In Progress
 * Author: Vikas Gogia
*/
#include<iostream>
#include<limits.h>
using namespace std;

int findMinJumps(int *arr, int n, int i) {
    cout << i << endl;
    // base case
    if(i >= n) return INT_MAX;
    if(i == n-1) return 1;

    // processing
    int value = arr[i];
    int minSteps = INT_MAX;

    for(int j=1; j<= value; j++) {
        // recursive call
        minSteps = min(minSteps, findMinJumps(arr, n, i+j));
    }
    return minSteps+1;
}

int main() {
    int arr[] = {6, 2, 4, 0, 5, 1, 1, 4, 2, 9};
    cout << findMinJumps(arr, 10, 0);
}