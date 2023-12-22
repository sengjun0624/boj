//
// Created by Lee SeungJun on 12/22/23.
//
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

priority_queue<pair<int, int>> q;
vector<int>v;
int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int standard=60;

int ans = 0; int des=335;

/*
 * 처음에 1~3/1까지
 */
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int first{0},last{0};
        int a, b, c, d; cin >> a >> b >> c >> d;
        for (int j = 0; j < a - 1; j++) {
            first = first + arr[j];
        } first += b;

        for (int j = 0; j < c - 1; j++) {
            last = last + arr[j];
        } last += d;
        q.push({-first, last});
        v.push_back(-last);
    }
    sort(v.begin(), v.end());

    if(-v[0]<des){ //가장 늦게 지는 꽃의 지는 날이 11/30일보다 전 일때
        cout<<0;
        return 0;
    }
    while (!q.empty()) {
        priority_queue<pair<int,int>>temp;

        if(-q.top().first>standard){ // 다음 필 꽃이 마지막 지는 날 보다 뒤일때
            cout<<0; exit(0);
        }

        while (!q.empty() && -q.top().first <= standard) {
            temp.push({q.top().second,-q.top().first}); q.pop();
        }
        standard=temp.top().first; //기준보다 이르게 피는 꽃중 제일 늦게 지는날로 업데이트
        ans++; //꽃 개수 추가
        if (standard >= des)break; //지는날이 11/30보다 크다면 끝
    }
    cout << ans;
}
