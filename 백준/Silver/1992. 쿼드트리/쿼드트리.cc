//
// Created by Lee SeungJun on 9/7/24.
//
#include<iostream>
#include<string>

using namespace std;
char map[64][64];

string quadTree(int y, int x, int size) {
    char first = map[y][x];
    bool isSame = true;
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (first != map[i][j]) {
                isSame = false;
                break;
            }
        }
        if (!isSame)break;
    }
    string str(1, first);
    if (isSame)return str;

    int half = size / 2;

    string upperLeft = quadTree(y, x, half);
    string upperRight = quadTree(y, x + half, half);
    string lowerLeft = quadTree(y + half, x, half);
    string lowerRight = quadTree(y + half, x + half, half);

    return "(" + upperLeft + upperRight + lowerLeft + lowerRight + ")";
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;
        for (int j = 0; j < cmd.size(); j++) {
            map[i][j] = cmd[j];
        }
    }
    cout << quadTree(0, 0, n);
}