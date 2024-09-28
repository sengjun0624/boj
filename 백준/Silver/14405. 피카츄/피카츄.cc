//
// Created by Lee SeungJun on 9/28/24.
//
#include<iostream>
#include<vector>
#include<stack>

using namespace std;
stack<char> s;

int main() {
    string str;
    cin >> str;
    for (int i = str.size() - 1; i >= 0; i--) {
        s.emplace(str[i]);
    }
    while (!s.empty()) {
        if (s.top() == 'p') {
            s.pop();
            if (!s.empty() && s.top() == 'i')s.pop();
            else {
                cout << "NO";
                return 0;
            }
        } else if (s.top() == 'k') {
            s.pop();
            if (!s.empty() && s.top() == 'a')s.pop();
            else {
                cout << "NO";
                return 0;
            }
        } else if (s.top() == 'c') {
            s.pop();
            if (!s.empty() && s.top() == 'h')s.pop();
            else {
                cout << "NO";
                return 0;
            }
            if (!s.empty() && s.top() == 'u')s.pop();
            else {
                cout << "NO";
                return 0;
            }
        } else {
            cout << "NO";
            return 0;
        }

    }
    cout<<"YES";
}