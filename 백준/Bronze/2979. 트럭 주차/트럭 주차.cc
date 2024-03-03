//
// Created by Lee SeungJun on 3/3/24.
//

#include<iostream>

using namespace std;
int park[101];
int cost[4];

int main() {
    for (int i = 1; i <= 3; i++) {
        cin >> cost[i];
    }
    for (int i = 0; i < 3; i++) {
        int st, ed;
        cin >> st >> ed;
        while (st < ed) {
            park[st]++;
            st++;
        }
    }

    int sum = 0;

    for (int i = 1; i <= 100; i++) {
        switch (park[i]) {
            case 1:
                sum += cost[1] * 1;
                break;
            case 2:
                sum += cost[2]*2;
                break;
            case 3:
                sum += cost[3]*3;
                break;
        }
    }
    cout<<sum;
}