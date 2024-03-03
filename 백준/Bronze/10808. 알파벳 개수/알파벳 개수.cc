//
// Created by Lee SeungJun on 3/3/24.
//
#include<iostream>
#include<vector>

using namespace std;

int alphabet [26];

int main() {
    string cmd; cin >> cmd;
    for (char c: cmd) {
        alphabet[c-'a']++;
    }
    for (int i = 0; i < 26; i++) {
        cout<<alphabet[i]<<" ";
    }
}



