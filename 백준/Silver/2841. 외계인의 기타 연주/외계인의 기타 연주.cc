//
// Created by Lee SeungJun on 12/19/23.
//
#include<iostream>
#include<vector>

using namespace std;

int n, p;

vector<int> v[500001];


int main() {
    cin >> n >> p;
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int line, plat;
        cin >> line >> plat;
        if(v[line].empty()){
            v[line].emplace_back(plat);
            ans++;
            continue;
        }
        while(!v[line].empty()&&v[line].back()>plat){
            v[line].pop_back();
            ans++;
        }
        if(v[line].back()==plat) continue;

        v[line].push_back(plat);
        ans++;
    }
    cout<<ans;
}