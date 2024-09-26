#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;

vector<int> AAA(vector<int> &v) {
    //올림해주고 단 최고자리수는 빼고
    for (ll i = 0; i < v.size() - 1; i++) {
        v[i + 1] += v[i] / 10;
        v[i] = v[i] % 10;
    }
    // 하나남을때까지 0을빼줌.
    while (v.size() > 1) {
        if (v.back() != 0)break;
        v.pop_back();
    }
    //뒤집어주고
    reverse(v.begin(), v.end());
    return v;
}

vector<int> addTo(vector<int> &v1, vector<int> &v2) {
    if (v1.size() < v2.size())return addTo(v2, v1);
    vector<int> ret(max(v1.size(), v2.size()) + 1, 0);
    ll minLen = min(v1.size(), v2.size());

    ret = v1;
    for (ll i = 0; i < minLen; i++) {
        ret[i] += v2[i];
    }

    return AAA(ret);
}

int main() {
    string A, B;
    cin >> A >> B;
    vector<int> v1, v2;

    for (ll i = A.size() - 1; i >= 0; i--) {
        v1.push_back(A[i] - '0');
    }
    for (ll i = B.size() - 1; i >= 0; i--) {
        v2.push_back(B[i] - '0');
    }

    for (auto n: addTo(v1, v2))cout << n;
}