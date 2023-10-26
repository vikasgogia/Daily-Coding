/**
 * Done
 * T.C.: O(n)
 * S.C.: O(1)
 * Author: Vikas Gogia
*/

/**
 * Problem
This problem was asked by Google.

UTF-8 is a character encoding that maps each symbol to one, two, three, or four bytes.

For example, the Euro sign, €, corresponds to the three bytes 11100010 10000010 10101100. The rules for mapping characters are as follows:

For a single-byte character, the first bit must be zero.
For an n-byte character, the first byte starts with n ones and a zero. The other n - 1 bytes all start with 10.
Visually, this can be represented as follows.

 Bytes   |           Byte format
-----------------------------------------------
   1     | 0xxxxxxx
   2     | 110xxxxx 10xxxxxx
   3     | 1110xxxx 10xxxxxx 10xxxxxx
   4     | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

Write a program that takes in an array of integers representing byte values, and returns whether it is a valid UTF-8 encoding.
*/

#include <iostream>
#include<vector>
using namespace std;

bool isUTFEncoded(int* arr, int len) {
    int first = arr[0];
    int count = -1;

    // check for the first byte
    if ((first >> 7) == 0) count = 0;
    else if ((first >> 5) == 0b110) count = 1;
    else if ((first >> 4) == 0b1110) count = 2;
    else if ((first >> 3) == 0b11110) count = 3;
    else return false;

    // check for rest of the bytes 
    for (int i = 1; i < len; ++i) {
        int byt = arr[i];
        if ((byt >> 6) == 0b10)count -= 1;
        else return false;
    }

    return count == 0;
}

int main() {
    int arr[] = {246, 172, 175, 172};
    cout << isUTFEncoded(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
