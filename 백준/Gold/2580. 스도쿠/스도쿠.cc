
//
// Created by Lee SeungJun on 12/19/23.
//

#include<iostream>
#include<vector>

using namespace std;

int m[9][9];
int b[3][3][10];
int r[9][10]; //row
int c[9][10]; //column
vector<pair<int, int>> v;
int Size;
/*
 *  행 열 블록별로 숫자 쓴거 셋팅해두고 0인 칸마다 세로 가로 블록에 가능한수가 같으면 그걸로 넣기.
 */
void run(int idx) {
    if(idx==Size){
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << m[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }
    auto a = v[idx];
    int y = a.first;
    int x = a.second;
    int idx_y = y / 3;
    int idx_x = x / 3;
    for (int i = 1; i <= 9; i++) {
        if (!r[y][i] && !c[x][i] && !b[idx_y][idx_x][i]) {
            m[y][x] = i;
            r[y][i]=1; c[x][i]=1; b[idx_y][idx_x][i]=1;
            run(idx + 1);
            r[y][i]=0; c[x][i]=0; b[idx_y][idx_x][i]=0;
        }
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> m[i][j];
            if (m[i][j] == 0)v.push_back({i, j});
            else {
                r[i][m[i][j]] = 1;
                c[j][m[i][j]] = 1;
                int idx_y = i / 3;
                int idx_x = j / 3;
                b[idx_y][idx_x][m[i][j]] = 1;
            }
        }
    }
    Size=v.size();
   run(0);
}