/**
 * Done
 * Author: Vikas Gogia
*/

/**
 * Problem
This problem was asked by Palantir.

The ancient Egyptians used to express fractions as a sum of several terms where each numerator is one. For example, 4 / 13 can be represented as 1 / 4 + 1 / 18 + 1 / 468.

Create an algorithm to turn an ordinary fraction a / b, where a < b, into an Egyptian fraction.
*/

#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> findDenominators(int num, int den) {
    vector<int> ans;
    int d = 0;

    while(num > 0) {
        d = ceil((float)den/num);
        ans.push_back(d);

        num = num * d - den;
        den *= d;
    }
    return ans;
}

int main() {
    int num = 4;
    int den = 13;
    vector<int> ans = findDenominators(num, den);
    for(int i=0; i< ans.size(); i++) {
        cout << "1/" << ans[i] << ", ";
    }
    return 0;
}