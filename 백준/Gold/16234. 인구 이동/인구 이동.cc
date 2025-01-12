#include<iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

const int MAX = 51;

struct Union {
    int sum = 0;
    int len = 0;
    vector<pair<int, int>> index;

    void init() {
        this->sum = 0;
        this->len = 0;
        index.clear();
    }
};

int map[MAX][MAX];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
bool visited[MAX][MAX];

vector<Union> unions;
queue<pair<int, int>> q;

int n, l, r;

Union bfs(pair<int, int> start) {
    Union u;
    memset(visited, false, sizeof(visited));
    q.push(start);
    //TODO 왜 unused?
    visited[start.first][start.second] = true;

    u.len++;
    u.sum += map[start.first][start.second];
    u.index.push_back({start});

    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int y = p.first;
        int x = p.second;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            //index 벗어나는지
            if (ny < 1 || ny > n || nx < 1 || nx > n || visited[ny][nx])continue;
            // 갈수있는 영역인지
            int gap = abs(map[y][x] - map[ny][nx]);
            if (gap < l || gap > r)continue;

            visited[ny][nx] = true;
            q.emplace(ny, nx);

            u.sum += map[ny][nx];
            u.len++;
            u.index.emplace_back(ny, nx);
        }
    }

    return u;
}

int main() {
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }


    int day = 2000;
    int answer = 0;
    while (day--) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                Union u;
                if (!visited[i][j])u = bfs({i, j});
                if (u.len == 1)continue;
                unions.emplace_back(u);
            }
        }
        if (unions.empty()) break;
        for (const auto &ele: unions) {

            int avg = (ele.sum == 0) ? ele.sum : ele.sum / ele.len;
            for (auto p: ele.index) {
                map[p.first][p.second] = avg;
            }
        }
        answer++;

        unions.clear();
        memset(visited, false, sizeof(visited));
        /*for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << visited[i][j];
            }
            cout << endl;
        }*/
    }

    cout << answer;
}

