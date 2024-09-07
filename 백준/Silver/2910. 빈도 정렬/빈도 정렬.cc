#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

unordered_map<int, int> um;
vector<pair<int, int>> v;

bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first < p2.first)return false;
    else if (p1.first > p2.first)return true;
    else {
        //그 수의 인덱스가 누가 더빠른지
        // 맵에서 그 숫자를 찾고 그 숫자의 index(second)
        return um.find(p1.second)->second < um.find(p2.second)->second;
    }
}

int main() {
    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (um.find(num) == um.end()) {
            v.emplace_back(1, num);
            um[num] = v.size() - 1;
        } else {
            int idx = um.find(num)->second;
            v[idx].first++;
        }
    }
    sort(v.begin(), v.end(), comp);
    for (auto it: v) {
        for (int i = 0; i < it.first; i++) {
            cout<<it.second<<" ";
        }
    }

}
