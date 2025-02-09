#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX 21

struct Cell {
    int x;
    int y;
    int dist;

    Cell(int x, int y, int dist) : x(x), y(y), dist(dist) {};
};

void input();

void solve();

void bfs();

void init();

int n, eatTime;

vector<vector<int>> map(MAX, vector<int>(MAX));
bool visited[MAX][MAX];
pair<int, int> sharkPos;
pair<int, int> shark = {2, 0};

int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};

int main() {
    input();
    solve();
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                sharkPos = {i, j};
            }
            //상어의 위치
        }
    }
}

bool check(int ny, int nx) {
    if (ny < 1 || ny > n || nx < 1 || nx > n)return false;
    if (visited[ny][nx])return false;
    if (shark.first < map[ny][nx])return false;
    return true;
}

void bfs() {
    queue<Cell> q;
    q.emplace(sharkPos.second, sharkPos.first, 0);
    vector<pair<int, pair<int, int>>> fishes;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            int ndist = cur.dist + 1;

            if (!check(ny, nx))continue;
            visited[ny][nx] = true;
            q.emplace(nx, ny, ndist);
            if (map[ny][nx] < shark.first && map[ny][nx] != 0) {
                fishes.push_back({ndist, {ny, nx}});
            }
        }
    }
    if (!fishes.empty()) {
        sort(fishes.begin(), fishes.end());
        int ny = fishes[0].second.first;
        int nx = fishes[0].second.second;
        int ndist = fishes[0].first;

        map[ny][nx] = 9;
        shark.second++;
        map[sharkPos.first][sharkPos.second] = 0;
        sharkPos = {ny, nx};
        // 사이즈 업
        if (shark.second == shark.first) {
            shark.first++;
            shark.second = 0;
        }
        eatTime += ndist;
    }

}

void solve() {
    while (true) {
        //before
        int old = eatTime;
//        cout << sharkPos.first << sharkPos.second<<endl;
//        cout<<map[sharkPos.first][sharkPos.second]<<endl;
        visited[sharkPos.first][sharkPos.second] = true;

        bfs();
        //after
        if (eatTime == old) break;
        init();
    }
    cout << eatTime;
}

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            visited[i][j] = false;
        }
    }
}
