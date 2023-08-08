#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
#define max 100005	
int t, n,from,maxlevel;
vector<vector<int>>graph;
int depth[max];
int dp[max][20];
long long cnt;
queue<int>q;
void init() {
	depth[0] =0;
	from = 1;
	cnt = 0;
	graph.clear();
}
int findLCA(int a, int b) {
	if (b == a)return a;
	//공통부모가 찾기
	int l_root = a;
	int  r_root = b;
	if (depth[a] != depth[b]) {
		if (depth[a] > depth[b]) {
			swap(a, b);
		}
		for (int i = maxlevel; i>=0;i--) {
			if (depth[a] <= depth[dp[b][i]]) {
				b = dp[b][i];
			}
		}
	}
	int lca = a;
	if (a != b) {
		for (int i = maxlevel; i>=0; i--) {
			if (dp[a][i] != dp[b][i]) {
				a = dp[a][i];
				b = dp[b][i];
			}
			lca = dp[a][i];
		}
	}
	return lca;
}
void bfs() {
	q.push(1);
	while (!q.empty()) {
		int to = q.front();
		int lca = findLCA(from, to);
		q.pop();
		cnt += depth[to] - depth[lca];
		cnt += depth[from] - depth[lca];
		for (auto i : graph[to]) {
			if (depth[to] < depth[i]) {
				q.push(i); 
			}
		}
		from = to; //from
	}
}
void sparse() {
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= maxlevel; j++) {
			int tmp = dp[i][j - 1];
			dp[i][j] = dp[tmp][j - 1];
		}
	}
}
int main() {
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		init();
		graph.resize(n + 2);
		for (int i = 2; i <= n; i++) {
			int parent;
			cin >>parent;
			graph[parent].push_back(i);
			graph[i].push_back(parent);
			depth[i] = depth[parent] + 1;
			dp[i][0] = parent;
		}

		maxlevel = (int)floor(log2(n));
		sparse();
		bfs();
		cout << "#" << tc << " " << cnt << "\n";
	}
}
