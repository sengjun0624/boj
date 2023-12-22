//
// Created by Lee SeungJun on 12/20/23.
//
#include<iostream>


using namespace std;

const int Max = 301;


int dp[Max];
int value[Max];


int main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        value[i] = num;
    }
    dp[1] = value[1];
    dp[2] = max(value[1] + value[2], value[2]);
    dp[3] = max(value[1] + value[3], value[2] + value[3]);

    for (int i = 4; i <= n; i++) {
        dp[i] = max(dp[i - 3] + value[i - 1] + value[i], dp[i - 2] + value[i]);
    }
    cout << dp[n];
}