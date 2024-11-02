//
// Created by Lee SeungJun on 11/2/24.
//
#include<iostream>
#include<cstring>

using namespace std;
int map[65][65];
int n, cnt;

void transpose(int x) {
    cnt++;
    int newMap[65][65];
    memcpy(newMap, map, sizeof(map));

    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= x; j++) {
            newMap[i][j] = map[j][i];
        }
    }
    memcpy(map, newMap, sizeof(map));
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cnt = 0;
        memset(map, 0, sizeof(map));
        //X를 큰 수부터 각 칸에 맞는 수가 들어갔는지 체크해서 돌리기.
        cin >> n;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> map[i][j];
            }
        }

        for (int x = n; x >= 1; x--) {
            bool shouldTranspose = false;
            for (int i = 1; i <= x; i++) {
                //map[i][j]=(i-1) * n + j;임을 이용
                if (map[x][i] != ((x - 1) * n + i)) {
                    shouldTranspose = true;
                    break;
                }
                if (map[i][x] != (i - 1) * n + x) {
                    shouldTranspose = true;
                    break;
                }
            }
            if (shouldTranspose)transpose(x);
        }
        cout<<cnt<<"\n";
    }
}