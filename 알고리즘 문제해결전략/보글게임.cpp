#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

char board[5][5];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int alpha[26];
vector<pair<string, bool>> words;

bool isPromising(string s) {
    for (char c: s) {
        if (!alpha[c - 'A'])return false;
    }
    return true;
}

bool bfs(int iy, int ix, string answer) {
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {iy, ix}});

    while (!q.empty()) {
        int y = q.front().second.first;
        int x = q.front().second.second;
        int dist = q.front().first;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 5 || nx >= 5 || ny < 0 || nx < 0)continue;
            //다음 가려는곳이 다음 글자와 다르면 안함.
            if (dist + 1 < answer.length() && board[ny][nx] != answer[dist + 1])continue;
            //다음 이동할곳
            q.push({dist + 1, {ny, nx}});

            if (dist + 1 == answer.length() - 1) {
                return true;
            }
        }
    }
    return false;
}

bool findWordInBoard(string word) {
    if (isPromising(word)) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (board[j][k] == word[0]) {
                    if (word.length() == 1 || bfs(j, k, word)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void init() {
    memset(board, 0, sizeof(board));
    memset(alpha, 0, sizeof(alpha));
    words.clear();
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        init();
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> board[i][j];
                //보드판에 알파벳이 존재하는지 체크
                alpha[board[i][j] - 'A'] = 1;
            }
        }
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            string cmd;
            cin >> cmd;
            if (findWordInBoard(cmd)) {
                cout << cmd << " " << "YES" << "\n";
            } else {
                cout << cmd << " " << "NO" << "\n";
            }
        }
    }
}
