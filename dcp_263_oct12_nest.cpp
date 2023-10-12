/**
 * Done
 * T.C.: O(1)
 * S.C.: O(n)
 * Author: Vikas Gogia
*/

/**
 * Problem
This problem was asked by Nest.

Create a basic sentence checker that takes in a stream of characters and determines whether they form valid sentences. If a sentence is valid, the program should print it out.

We can consider a sentence valid if it conforms to the following rules:

1. The sentence must start with a capital letter, followed by a lowercase letter or a space.
2. All other characters must be lowercase letters, separators (,,;,:) or terminal marks (.,?,!,‽).
3. There must be a single space between each word.
4. The sentence must end with a terminal mark immediately following a word.
*/

#include <iostream>
#include <cctype>
using namespace std;

enum State : int {
    BEGIN, UPPER, LOWER, SPACE, SEPERATOR
};

void isSentence() {
    char ch;
    string s = "";
    State state = BEGIN;
    
    while(1) {
        cin.get(ch);
        s += ch;

        if(isupper(ch) && state == BEGIN) state = UPPER;
        else if(islower(ch) && (state == UPPER || state == LOWER || state == SPACE)) state = LOWER;
        else if(ch == ' ' && (state == LOWER || state == UPPER || state == SEPERATOR)) state = SPACE;
        else if((ch == ',' || ch == ';' || ch == ':') && (state == LOWER)) state = SEPERATOR;
        else if((ch == '.' || ch == '!' || ch == '?') && (state == LOWER)) {
            state = BEGIN;
            cout << "Valid string: " << s;
            s = "";
        }
        else s = "";
    }
}

int main() {
    isSentence();
    return 0;
}