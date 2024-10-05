//
// Created by Lee SeungJun on 10/5/24.
//
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

#define pii pair<int,int>

const int MAX = 10;

int N;
int map[MAX][MAX];
bool flowers[MAX][MAX];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

vector<pii > v;
int Min = INT_MAX;

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            v.push_back({i, j});
        }
    }
}

bool isValid(int y, int x) {
    if (flowers[y][x])return false;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (flowers[ny][nx])return false;
    }
    return true;
}

int placeFlowers(pii a, int mode) {
    int y = a.first;
    int x = a.second;
    int rent = map[y][x];

    //심기
    if (mode == 0) {
        if (!isValid(y, x))return 987654321;
        flowers[y][x] = true;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            flowers[ny][nx] = true;
            rent += map[ny][nx];
        }
        return rent;
    } else {
        flowers[y][x] = false;
        //뽑기
        int ret = 0;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            flowers[ny][nx] = false;
            rent += map[ny][nx];
        }
        return rent;
    }
}

void solve() {
    for (int i = 0; i < v.size(); i++) {
        int sum = 0;
        int ret1 = placeFlowers(v[i], 0);
        if (ret1 == 987654321)continue;
        sum += ret1;
        for (int j = i + 1; j < v.size(); j++) {
            int ret2 = placeFlowers(v[j], 0);
            if (ret2 == 987654321)continue;
            sum += ret2;
            for (int k = j + 1; k < v.size(); k++) {
                int ret3 = placeFlowers(v[k], 0);
                if (ret3 == 987654321)continue;
                sum += ret3;
                Min = min(Min, sum);

                sum -= placeFlowers(v[k], 1);
            }
            sum -= placeFlowers(v[j], 1);
        }
        sum -= placeFlowers(v[i], 1);
    }
    cout << Min;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

}
