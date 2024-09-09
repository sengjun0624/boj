//
// Created by Lee SeungJun on 9/9/24.
//

#include<iostream>

using namespace std;

//5단위로 하나씩 늘어나네
//6이면
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int count=0;
        for (int i = 5; N / i >= 1; i *= 5) {
            count += N / i;
        }cout<<count<<"\n";

    }
}