#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cctype>
#include <map>
#include <stack>
#include <queue>

using namespace std;
#define MAX 10002
#define fastio()  cin.tie(0);    ios::sync_with_stdio(0);
#define INF 987654321
vector<int> dist(MAX);
int n, d;
priority_queue<pair<int, int>> pq;
vector<vector<pair<int, int>>> edge(MAX);
// pq -weight,node
/**
 * 시작점 0
 * 각 지점들 다 초기화 하고
 * 엣지 방문마다 거리 배열 업데이트
 * 도착점 D
 */

void input();

void solve();

int main() {
    fastio();
    input();
    solve();
}

void input() {
    cin >> n >> d;
    for (int i = 1; i <= d; i++) {
        dist[i] = INF;
    }

    int st, ed, w;
    for (int i = 1; i <= n; i++) {
        cin >> st >> ed >> w;
        if (ed - st < w)continue;
        edge[st].push_back({w, ed});
    }
}

void solve() {
    // 첨부터 끝까지 돌고 지름길 체크, 업데이트
    for (int i = 0; i < d; i++) {
        dist[i + 1] = min(dist[i + 1], dist[i] + 1);

        for (auto p: edge[i]) {
            int weight = p.first;
            int next = p.second;
            if (dist[i] + weight >= dist[next])continue;
            dist[next] = dist[i] + weight;
        }
    }
    cout << dist[d];
}
