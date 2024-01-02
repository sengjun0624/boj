//
// Created by Lee SeungJun on 1/2/24.
//
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

const int Max = 1000001;

vector<int> value(Max);
vector<int> F(Max);
vector<int> NGF(Max, -1);

stack<int> s;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> value[i];
        F[value[i]]++;
    }

    for (int i = n; i > 0; i--) {
        if (s.empty()) {
            s.push(value[i]);
            continue;
        }
        while (!s.empty() && F[s.top()] <= F[value[i]]) {
            s.pop();
        }
        NGF[i] = s.empty() ? -1 : s.top();
        s.push(value[i]);
    }
    for (int i = 1; i <= n; i++) {
        cout << NGF[i] << " ";
    }
}