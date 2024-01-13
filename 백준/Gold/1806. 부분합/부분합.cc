//
// Created by Lee SeungJun on 1/13/24.
//

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> v;


int ed, l{100001}, sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.emplace_back(num);
    }
    for (int st = 0; st < n; st++) {
        while (ed < n && sum < s) {
            sum += v[ed];
            ed++;
        }
        if (sum >= s) {
            l = (l > ed - st) ? ed - st : l;
            sum -= v[st];
        }
    }
    if (l == 100001)cout << 0;
    else cout << l;
}
