//
// Created by Lee SeungJun on 12/20/23.
//

#include<iostream>
#include<vector>

using namespace std;

const int Max = 21;

vector<char> m[Max];
bool check[26];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int ans = 0;
int r, c;

void dfs(int x, int y, int cnt) {
    if (cnt > ans) {
        ans = cnt;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];


        if (nx < 0 || nx >= c || ny < 0 || ny >= r)continue;
        if (check[m[ny][nx] - 'A']) continue;
//        cout<<"next value: "<<m[ny][nx]<<"\n";

        char cur = m[ny][nx]; //방문한 지점
        check[cur - 'A'] = true; //방문한 지점 캐릭터 표시

        dfs(nx, ny, cnt + 1);
        check[cur - 'A'] = false; //방문한 지점 캐릭터 표시
    }
    //갈 곳이 없으면 지금 내 값 return
}


int main() {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char num;
            cin >> num;
            m[i].push_back(num);
        }
    }
    check[m[0][0] - 'A'] = true;
//    cout<<"start value: "<<m[0][0]<<"\n";

    dfs(0, 0, 1);

    cout << ans;


}