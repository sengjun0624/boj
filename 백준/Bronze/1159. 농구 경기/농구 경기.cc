//
// Created by Lee SeungJun on 3/3/24.
//

#include<iostream>

using namespace std;

int n;
int cnt = 0;
string cmd;
int lst_name[26];

int main() {
    cin >> n;

    while (n--) {
        cin >> cmd;
        lst_name[cmd[0]-'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (lst_name[i] >= 5) {
            cout << (char)('a' + i);
            cnt++;
        }
    }
    if (!cnt)cout << "PREDAJA";
}