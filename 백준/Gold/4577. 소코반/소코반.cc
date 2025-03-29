#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAX 20
#define fastio()  cin.tie(0)->sync_with_stdio(0)

char board[MAX][MAX];
int n, m;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
pair<int, int> player;
vector<pair<int, int>> goals;
int game_cnt = 0;

bool valid(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < m;
}

void move(char dir, bool &finished) {
    int d;
    if (dir == 'U') d = 0;
    else if (dir == 'R') d = 1;
    else if (dir == 'D') d = 2;
    else d = 3;

    int y = player.first;
    int x = player.second;
    int ny = y + dy[d], nx = x + dx[d];
    int nny = ny + dy[d], nnx = nx + dx[d];

    if (!valid(ny, nx)) return;

    char next = board[ny][nx];

    if (next == '.' || next == '+') {
        board[ny][nx] = (next == '+') ? 'W' : 'w';
        board[y][x] = (board[y][x] == 'W') ? '+' : '.';
        player = {ny, nx};
    }
    else if (next == 'b' || next == 'B') {
        if (!valid(nny, nnx)) return;
        char next_box = board[nny][nnx];
        if (next_box == '.' || next_box == '+') {
            // 박스 이동
            board[nny][nnx] = (next_box == '+') ? 'B' : 'b';
            board[ny][nx] = (next == 'B') ? 'W' : 'w';
            board[y][x] = (board[y][x] == 'W') ? '+' : '.';
            player = {ny, nx};
        }
    }

    // 게임 종료 여부 확인
    int box_on_goal = 0;
    for (auto [gy, gx] : goals) {
        if (board[gy][gx] == 'B') box_on_goal++;
    }
    if (box_on_goal == goals.size()) finished = true;
}

void restore_goals() {
    for (auto [gy, gx] : goals) {
        if (board[gy][gx] == '.') board[gy][gx] = '+';
        if (board[gy][gx] == 'w') board[gy][gx] = 'W';
        if (board[gy][gx] == 'b') board[gy][gx] = 'B';
    }
}

void solve() {
    string cmd;
    cin >> cmd;

    bool finished = false;
    for (char c : cmd) {
        if (!finished) move(c, finished);
    }

    restore_goals();
    cout << "Game " << ++game_cnt << ": " << (finished ? "complete" : "incomplete") << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

int main() {
    fastio();
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        goals.clear();
        for (int i = 0; i < n; i++) {
            string line;
            cin >> line;
            for (int j = 0; j < m; j++) {
                board[i][j] = line[j];
                if (line[j] == 'W' || line[j] == 'w') player = {i, j};
                if (line[j] == '+' || line[j] == 'B' || line[j] == 'W') goals.emplace_back(i, j);
            }
        }

        solve();
    }
    return 0;
}
