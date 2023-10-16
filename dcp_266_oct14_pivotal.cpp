/**
 * Done
 * T.C.: O(k * nlogn)
 * S.C.: O(k)
 * Author: Vikas Gogia
*/

/**
 * Problem
This problem was asked by Pivotal.

A step word is formed by taking a given word, adding a letter, and anagramming the result. For example, starting with the word "APPLE", you can add an "A" and anagram to get "APPEAL".

Given a dictionary of words and an input word, create a function that returns all valid step words.
*/

/**
 * Solution
 * Make a hashmap of string->string where key is sorted: <"aelpp", "apple">
 * Iterate all uppercase chars and append to input string
 * Sort it
 * Match with the hashmap keys and if match is founf you got the anagram with an additional character
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>
using namespace std;

unordered_map<string, string> dictionaryMap(vector<string> dict) {
    unordered_map<string, string> umap;
    for(auto i: dict) {
        string s = i;
        sort(s.begin(), s.end());
        umap[s] = i;
    }
    return umap;
}

vector<string> findValidStepWords(vector<string> dict, string input) {
    unordered_map<string, string> dictMap = dictionaryMap(dict);
    vector<string> v;
    for(int i=65; i< 93; i++) {
        string s = input + (char) i;
        sort(s.begin(), s.end());
        if(dictMap.find(s) != dictMap.end())
            v.push_back(dictMap[s]);
    }
    return v;
} 

int main() {
    vector<string> dict {"APPEAL", "VDNSDN", "DSFBSADBFB", "LEABPP"};
    string input = "APPLE";

    vector<string> ans = findValidStepWords(dict, input);
    for(auto i: ans) {
        cout << i << ", ";
    }
}