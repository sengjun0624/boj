#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
const int Max = 100001;
pair<int, int>ans;
vector < pair<int, int>>edge[Max];
bool visit[Max];
int n, a, b, c;
void dfs(int cur,int dist) {
	for (auto k : edge[cur]) {
		int nxt = k.first;
		if (visit[nxt]) {
			continue;
		}
		visit[nxt] = true;
		if (ans.second < dist+k.second) {
			ans = { nxt,dist+k.second };
		}
		dfs(nxt,dist+k.second);
		
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
			cin >> a;
		while (true) {
			cin >> b;
			if (b == -1)break;
			cin >> c;
			edge[a].emplace_back(b, c);
		}
	}
	visit[1] = true;
	dfs(1,0);
	memset(visit, 0, sizeof(visit));
	visit[ans.first] = true;
	dfs(ans.first,0);
	cout << ans.second << "\n";
}

