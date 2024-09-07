//
// Created by Lee SeungJun on 9/7/24.
//
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
#define fastio() ios::sync_with_stdio(0); cin.tie(0);
const int Max = 100;

int main() {
    fastio();
    int n, m, k;
    cin >> n >> m >> k;
    // 0=blank 1= rectangle
    int map[Max][Max] = {0};
    bool visit[Max][Max] = {false};

    while (k--) {
        int l_x, l_y, r_x, r_y;
        cin >> l_x >> l_y >> r_x >> r_y;
        for (int i =  n-1-l_y; i > n-1-r_y; i--) {
            for (int j = l_x; j < r_x; j++) {
                map[i][j] = 1;
            }
        }
    }

    int ans = 0;
    vector<int> greater;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0 && !visit[i][j]) {
                int size = 1;
                ans++;
                visit[i][j] = true;
                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty()) {
                    auto it = q.front();
                    q.pop();
                    int y = it.first;
                    int x = it.second;
                    for (int dir = 0; dir < 4; dir++) {
                        int ny = y + dy[dir];
                        int nx = x + dx[dir];
                        if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1 || visit[ny][nx])continue;
                        if(map[ny][nx]==1)continue;
                        visit[ny][nx] = true;
                        q.push(make_pair(ny, nx));
                        size++;
                    }
                }
                greater.push_back(size);
            }
        }
    }
    cout << ans << "\n";
    sort(greater.begin(), greater.end());
    for (auto num: greater)cout << num << " ";

}