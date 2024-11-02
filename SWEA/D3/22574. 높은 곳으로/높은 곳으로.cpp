//
// Created by Lee SeungJun on 11/2/24.
//
#include<iostream>
#include<algorithm>

using namespace std;

int t, n, p;

int main() {
    cin >> t;
    while (t--) {
        int stair = 0;
        //계단 0층부터 시작 다음 가는 스텝이 폭탄만 아니면 됨.
        cin >> n >> p;
        int Min = 0xfffffff;
        //폭탄층이 걸리면 지금까지 지나온 가장 작은 층을빼버리기.
        for (int i = 1; i <= n; i++) {
            if (stair + i == p) {
                if(Min==0xfffffff)continue;
                stair = stair + i - Min;
                continue;
            }
            Min = min(Min, i);
            stair += i;
        }
        cout << stair << "\n";
    }
}