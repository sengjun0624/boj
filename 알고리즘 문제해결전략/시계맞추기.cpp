#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
vector<int> list(10);
int first = 0;
const int Max = 987650000;
int switches[10][5] = {
        {0, 1,  2,  -1, -1},
        {3, 7,  9,  11, -1},
        {4, 10, 14, 15, -1},
        {0, 4,  5,  6,  7},
        {6, 7,  8,  10, 12},
        {0, 2,  14, 15, -1},
        {3, 14, 15, -1, -1},
        {4, 5,  7,  14, 15},
        {1, 2,  3,  4,  5},
        {3, 4,  5,  9,  13}
};

void setTwelve(vector<int> &clocks, int index) {
    //uses만큼 index번째의 스위치들을 가동하거나 역가동
    for (int clock: switches[index]) {
        if(clock==-1)continue;
        clocks[clock] += 3;
        if (clocks[clock] == 15)clocks[clock] = 3;

    }
}
bool isSet12(vector<int>&clocks) {
    for (auto num: clocks)if (num != 12)return false;
    return true;
}
int findMinTwelveTime(vector<int> &clocks, int index) {
    int ret = Max;
    if (index == 10) {
        if (isSet12(clocks)) {
            return 0;
        } else return Max;
    }
    for (int uses = 0; uses < 4; uses++) {
        ret = min(ret , uses+findMinTwelveTime(clocks, index + 1));
        setTwelve(clocks, index);
    }
    return ret;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        vector<int> clocks(16);
        for (int i = 0; i < 16; i++) {
            cin >> clocks[i];
        }
        int ans = findMinTwelveTime(clocks, 0);
        if (ans == Max)cout << -1 << "\n";
        else cout << ans << "\n";
    }
}
