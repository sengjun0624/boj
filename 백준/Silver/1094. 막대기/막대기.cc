//
//
// Created by Lee SeungJun on 9/25/24.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>

using namespace std;

int n;
int arr[65];
int sum = 64;

void input() {
    cin >> n;
}

/*
 * 설계다시해보자 음 일단 1부터 64까지임 0,1,2,4,8,16,32,64 7비트 그 비트가 있는지 보고
 */
int main() {
    input();
    int sticks = 0b1000000; //64
    arr[sticks]++;
    while (sum != n) {
        int minLen = 1;
        for (; minLen <= 64; minLen <<= 1) {
            // 최소막대 찾기
            if ((minLen & sticks) == minLen){
                break;
            }
        }
        //막대 자르기
        int half = minLen / 2;
        //자르기전 길이의 막대 개수 낮추기 0개면 bitmasking해서 없애줘야함.
        arr[minLen]--;
        if (!arr[minLen]) {
            sticks &= 127 - minLen;
        }
        //자른후 길이 막대 개수 늘려주기 원래 0개였으면 만들어줘야함.
        if (!arr[half]) {
            sticks |= half;
        }
        arr[half] += 2;


        //총합이 X보다 크거나 같으면 반쪽을 버림.
        if (sum - half >= n) {
            sum -= half;
            arr[half]--;
        }

    }
    int ans = 0;
    for (auto stick: arr) {
        ans += stick;
    }
    cout << ans;
}