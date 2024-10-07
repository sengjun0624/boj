//
// Created by Lee SeungJun on 10/7/24.
//
#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<algorithm>

using namespace std;
vector<char> v;
vector<char> numbers;
vector<string> ans;
int k;
bool visited[10];

bool check(int dist, int len) {
    if (len == 0)return true;
    char temp = v[len - 1]; //기호

    if (temp == '<') {
        return numbers.back() - '0' < dist;
    } else if (temp == '>') {
        return numbers.back() - '0' > dist;
    }
}

void solve(int len) {
    if (len == k + 1) {
        string tmp;
        for (char c: numbers) tmp += c;
        ans.push_back(tmp);
    }
    for (int i = 0; i < 10; i++) {
        //비어있거나(첫 원소이거나) 연산이 올바르지 않은경우
        if (visited[i] || !check(i, len))continue;
        numbers.push_back(i + '0');
        visited[i] = true;
        //for (char c: numbers)cout << c;
        //cout << "\n\n";
        solve(len + 1);
        numbers.pop_back();
        visited[i] = false;
    }
}

int main() {

    cin >> k;
    v.resize(k + 1);
    for (int i = 0; i < k; i++) {
        cin >> v[i];
    }
    solve(0);
    sort(ans.begin(), ans.end());

    cout << ans.back() << "\n" << ans.front();
}