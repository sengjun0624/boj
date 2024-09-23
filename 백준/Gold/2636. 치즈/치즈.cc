#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

#define fastio() ios::sync_with_stdio(0); cin.tie(0);
const int Max = 100;
int n, m;
int arr[Max][Max];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int ans = 0;
int cheese = 0;

queue<pair<int, int>> q;
bool visited[Max][Max];

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
}

bool isValid(int y, int x) {
    if (y < 0 || y >= n || x < 0 || x >= m)return false;
    return true;
}

void bfs() {

    vector<pair<int, int>> v;


    memset(visited, false, sizeof(visited));

    while (!q.empty()) {
        auto f = q.front();
        q.pop();
        int y = f.first;
        int x = f.second;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!isValid(ny, nx))continue;
            if (visited[ny][nx])continue;
            visited[ny][nx] = true;

            if (arr[ny][nx] == 1)v.emplace_back(make_pair(ny, nx));
            else q.emplace(make_pair(ny, nx));
        }
    }
    if (v.empty())return;
    for (int i = 0; i < v.size(); i++) {
        auto it = v[i];
        if (i == 0) {
            q.push(it);
            visited[it.first][it.second]=true;
        }
        arr[it.first][it.second] = 0;
    }
    ans++;
    cheese = v.size();
    bfs();
}


int main() {
    fastio();
    input();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                q.emplace(make_pair(i, j));
                visited[i][j] = true;
                break;
            }
        }
    }
    bfs();
    cout << ans << " " << cheese;
}