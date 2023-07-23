#include<iostream>
using namespace std;
using ll = long long;
int t;
string supervisor;
ll dp[10000][16];
void init() {
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 16; j++) {
            dp[i][j] = 0;
        }
    }
}
int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) {
        init();

        cin >> supervisor;
        for (int day = 0; day < supervisor.size(); day++) {
            int manager = 1 << (supervisor.at(day) - 'A');
            for (int j = 1; j < 16; j++) {
                if (day == 0) {
                    //Ã¹³¯
                    if ((j & 1) != 0 && (j & manager) != 0) {
                        dp[day][j] = 1;
                    }
                }
                else {
                    if (dp[day - 1][j] != 0) {
                        for (int k = 1; k < 16; k++) {
                            if ((j & k) != 0 && (k & manager) != 0) {
                                dp[day][k] += dp[day - 1][j];
                                dp[day][k] %= 1000000007;
                            }
                        }
                    }
                }
            }
        }
        ll cnt = 0;
        for (int i = 0; i < 16; i++) {
            cnt += dp[supervisor.size() - 1][i];
            cnt %= 1000000007;
        }
        cout << "#" << i << " " << cnt << "\n";

    }
}

