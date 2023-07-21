#include<iostream>
#include<bitset>
using namespace std;
int t, n, cnt,N=0;
int dp[100001];
void init() {
	for (int i = 0; i <= 9; i++) {
		dp[i] |=1<<i;
	}
}
int main() {
	init();
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cnt = 0;
		N = 0;
		cin >> n;
		int set = 0b0000000000;
		while(set != 0b1111111111) {
			N += n;
			cnt++;
			int idx = N;
			int DP = 0b0000000000;
			if (idx<100000&&dp[idx]) {
				set |= dp[idx];
				continue;
			}
			while (idx != 0) {
				int a = idx % 10;
				idx /= 10;
				DP |= dp[a]; 
			}
			if (N <= 100000) {
			dp[N] = DP;
			}
			set |= DP;
		}
		cout <<"#"<<i<<" "<< N <<"\n";

	}
}