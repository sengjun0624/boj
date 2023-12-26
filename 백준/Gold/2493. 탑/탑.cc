
// Created by Lee SeungJun on 12/26/23.
//
#include<iostream>
#include<queue>
#include<stack>

using namespace std;

const int Max = 500001;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
stack<pair<int, int>> s;
int ans[Max];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        s.push({i, val});
    }
    while (!s.empty()) {
        auto a = s.top();
        s.pop();

        //TODO s.top보다 낮은탑은 여기 부딪힘 그거 처리하기
        while (!pq.empty()) {
            if(pq.top().second<=a.second) {
                ans[pq.top().first]=a.first;
                pq.pop();
            }else{
                break;
            }
        }
        pq.push(a);
    }
    while (!pq.empty()) {
        ans[pq.top().first]=0;
        pq.pop();
    }

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}