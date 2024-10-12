#include<iostream>
#include<algorithm>

using namespace std;

int dp[61][61][61];
int hp[4];
int ans = 987654321;
int N;

void solve(int s, int c, int v, int attack) {
    if (s <= 0 && c <= 0 && v <= 0) {
        ans = min(ans, attack);
    }
    s = max(s, 0);
    c = max(c, 0);
    v = max(v, 0);
    if (dp[s][c][v] != 0 && dp[s][c][v] <= attack)return;
    dp[s][c][v] = attack;
    if (N == 1) {
        solve(s - 9, c, v, attack + 1);
    } else if (N == 2) {
        solve(s - 9, c - 3, v, attack + 1);
        solve(s - 3, c - 9, v, attack + 1);
    } else if (N == 3) {
        solve(s - 9, c - 3, v - 1, attack + 1);
        solve(s - 9, c - 1, v - 3, attack + 1);
        solve(s - 3, c - 9, v - 1, attack + 1);
        solve(s - 3, c - 1, v - 9, attack + 1);
        solve(s - 1, c - 9, v - 3, attack + 1);
        solve(s - 1, c - 3, v - 9, attack + 1);
    }
}
int main(){
    cin>>N;
    for (int i = 0; i < N; i++) {
        cin>>hp[i];
    }
    solve(hp[0], hp[1], hp[2], 0);
    cout<<ans;
}