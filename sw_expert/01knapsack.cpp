#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
vector<pii>item; // 아이템 배열
int dp[1001][101]; //i=item수,  j=무게수
int t, n, k;
int zeroOneKnapSack() {
	for (int i = 1; i <= k; i++) {
		dp[i][0] = 0;
	}
	for (int j = 1; j <= n; j++) {
		dp[0][j] = 0;
	}
	for (int i = 1; i <= k; i++) {
    		for (int j = 1; j <= n; j++) {
       			 dp[i][j] = dp[i][j - 1];  // 현재 아이템을 선택하지 않는 경우
        
        		// 현재 아이템을 선택할 수 있는 경우(무게가 충분한 경우)
        		if (item[j - 1].second <= i) {
            		// max(선택X, 선택O)
           			 dp[i][j] = max(dp[i][j - 1], 
                          	dp[i - item[j - 1].second][j - 1] + item[j - 1].first);
       		 }
   	 }
	}
	return dp[k][n];
}
int main() {
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			int v, c;
			cin >> c >> v;
			item.push_back({ v,c });
		}
		sort(item.begin(), item.end());
		int ret=zeroOneKnapSack();
		cout << "#" << tc << " " << ret << "\n";
		item.clear();
	}
	return 0;
}


