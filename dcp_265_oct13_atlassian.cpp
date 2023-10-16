/**
 * Done
 * T.C.: O(n)
 * S.C.: O(1) [auxillary space consumed is constant]
 * Author: Vikas Gogia
*/

/**
 * Problem
This problem was asked by Atlassian.

MegaCorp wants to give bonuses to its employees based on how many lines of codes they have written. They would like to give the smallest positive amount to each worker consistent with the constraint that if a developer has written more lines of code than their neighbor, they should receive more money.

Given an array representing a line of seats of employees at MegaCorp, determine how much each one should get paid.

For example, given [10, 40, 200, 1000, 60, 30], you should return [1, 2, 3, 4, 2, 1].
*/

/**
 * Solution
 * Bonus is calculated based on both left and right side neighbors e.g. 400 1000 60 (1000's bonus: max(bonus(400), bonus(60)))
 * after left to right: [1 2 3 4 1 1] (since 60 < 1000 so it's still 1, but it's greater than 30, so it should be 2)
 * after right to left: [1 2 3 4 2 1] (1000's max is 4 but during R to L it's calculated 3, so preserve the max i.e. 4)
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> bonusCalculation(int* arr, int n) {
    vector<int> v(n, 1);

    // L to R (identifies the bonus based on the left neighbor)
    for(int i=1; i< n; i++) {
        if(arr[i] > arr[i-1]) {
            v[i] = v[i-1]+1;   
        }
    }

    // R to L (identifies the bonus based on the right neighbor and computes the max bonus of left-based and right-based)
    for(int i=n-2; i>=0; i--) {
        if(arr[i] > arr[i+1]) {
            v[i] = max(v[i], v[i+1]+1);
        }
    }
    return v;
}

int main() {
    int arr[] = {10, 40, 200, 1000, 60, 30};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> v = bonusCalculation(arr, n);
    for(auto i: v) {
        cout << i << ", ";
    }
}