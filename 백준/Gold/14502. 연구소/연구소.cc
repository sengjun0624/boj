#include<iostream>
#include<queue>
#include<vector>

using namespace std;

#define fastio() ios::sync_with_stdio(0); cin.tie(0);

const int Max = 8;
int n, m;
int arr[Max][Max];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int ans = -1;
vector<pair<int, int>> virus;
vector<pair<int, int>> canWall;

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2)virus.emplace_back(make_pair(i, j));
            else if (arr[i][j] == 0)canWall.emplace_back(make_pair(i, j));
        }
    }
}
bool isValid(int y,int x){
    if (y < 0 || y >= n || x < 0 || x >= m)return false;
    return true;
}
void bfs() {
    int cp_map[Max][Max];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cp_map[i][j] = arr[i][j];
        }
    }
    queue<pair<int, int>> q;
    for (auto p: virus)q.emplace(p);
    
    while (!q.empty()) {
        auto f = q.front();
        q.pop();
        int y = f.first;
        int x = f.second;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!isValid(ny,nx))continue;
            if ( cp_map[ny][nx] != 0)continue;
            cp_map[ny][nx] = 2;
            q.emplace(make_pair(ny, nx));
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ( cp_map[i][j] == 0)cnt++;
        }
    }
    if (cnt > ans)ans = cnt;
}

void makeWall() {
    for (int i = 0; i < canWall.size(); i++) {
        for (int j = i + 1; j < canWall.size(); j++) {
            for (int k = j + 1; k < canWall.size(); k++) {
                arr[canWall[i].first][canWall[i].second] = 1;
                arr[canWall[j].first][canWall[j].second] = 1;
                arr[canWall[k].first][canWall[k].second] = 1;
                bfs();
                arr[canWall[i].first][canWall[i].second] = 0;
                arr[canWall[j].first][canWall[j].second] = 0;
                arr[canWall[k].first][canWall[k].second] = 0;
            }
        }
    }
}

int main() {
    fastio();
    input();
    makeWall();
    cout << ans;
}