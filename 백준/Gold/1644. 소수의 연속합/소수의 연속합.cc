//
// Created by Lee SeungJun on 1/13/24.
//
//TODO: 에라토스테네스의 체로 n의 제곱근까지만 값을 구하고 투포인터로 소수의 합의 가지수를 구한다.

#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>

using namespace std;

const int Max = 4000001;
bool prime[Max];

int main() {
    int n;
    cin >> n;
    memset(prime, true, sizeof(prime));

    for (int i = 2; i <= sqrt(n) + 1; i++) {
        if (!prime[i])continue;
        int j = 2;
        while (i * j <= n) {
            prime[i * j] = false;
            j++;
        }
    }
    vector<int> p;
    for (int i = 2; i <= n; i++) {
        if (prime[i])p.emplace_back(i);
    }

    int ed{0}, cnt{0}, sum{0};
    for (int st = 0; st < p.size(); st++) {
        while (ed < p.size() && sum < n) {
            sum += p[ed];
            ed++;
        }
        if (sum >= n) {
            if (sum == n)cnt++;
            sum -= p[st];
        }
    }
    cout << cnt;
}