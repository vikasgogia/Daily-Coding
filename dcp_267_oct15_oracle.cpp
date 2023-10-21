#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>
using namespace std;

unordered_map<char, pair<int, int>> getPiecesPositions(char inp[8][8]) {
    unordered_map<char, pair<int, int>> umap;

    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            char ch = inp[i][j];
            if(ch != '.')
                umap[ch] = make_pair(i, j);
        }
    }
    return umap;
}

bool checkPawn(int i, int j, int ki, int kj) {
    if(i == 0 || j == 0 || j == 7) return false;
    return ((i-1 == ki) && (j+1 == kj || j-1 == kj));
}

bool checkKnight(int i, int j, int ki, int kj) {
    int ti = i;
    int tj = j;
    
}

void checkCheck(char inp[8][8]) {
    unordered_map<char, pair<int, int>> umap = getPiecesPositions(inp);
    pair<int, int> kingPosition = umap['K'];
    bool isCheck = 0;


}

int main() {
    return 0;
}