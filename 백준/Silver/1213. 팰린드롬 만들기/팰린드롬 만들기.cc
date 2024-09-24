
#include<iostream>
#include<string>
#include<vector>

using namespace std;

char alpha[26];
string name;
int len;

void input() {
    cin >> name;
    for (char c: name) {
        alpha[c - 'A']++;
    }
    len = name.size();
}

void sol() {
    vector<char> v(len);
    if (len % 2 == 0) {
        int idx = 0;
        for (int i = 0; i < 26; i++) {
            if (alpha[i] == 0)continue;
            if (alpha[i] % 2 != 0) {
                cout << "I'm Sorry Hansoo";
                return;
            }
            for (int j = 0; j < alpha[i] / 2; j++) {
                v[idx] = (char) ('A' + i);
                v[len - 1 - idx] = (char) ('A' + i);
                idx++;
            }
        }
        for (auto c: v)cout << c;

    } else {
        int isPalendrom = 0;
        char middle;
        for (int i = 0; i < 26; i++) {
            if (alpha[i] % 2 != 0) {
                isPalendrom++;
                middle = (char) ('A' + i);
            }
        }
        if (isPalendrom!=1) {
            cout << "I'm Sorry Hansoo";
            return;
        }
        int idx = 0;
        int mid = 0 + len / 2;
        v[mid]=middle;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < alpha[i] / 2; j++) {
                v[idx] = (char) ('A' + i);
                v[len - 1 - idx] = (char) ('A' + i);
                idx++;
            }
        }
        for (auto c: v)cout << c;
    }
}

int main() {
input();
sol();

}