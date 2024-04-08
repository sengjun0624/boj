//
// Created by Lee SeungJun on 4/8/24.
//
#include<iostream>
#include<vector>

using namespace std;

vector<int> v;

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        v.push_back(num);
    }

    long long st{1}, ed{(n * 10000) / m + 1};
    int ans;
    while (st <= ed) {
        int cnt = 0;
        int last = 0;
        int mid = (st + ed) / 2;

        for (cnt; cnt < n; cnt++) {

            int sum = 0;
            if (last == n)break;

            for (last; last < n; last++) {

                if (sum + v[last] <= mid) {

                    sum += v[last];
                } else {
                    break;
                }
            }
        }
        if (cnt <= m) {
            ans = mid;
            ed = mid - 1;
        } else st = mid + 1;
    }
    cout << ans;
}