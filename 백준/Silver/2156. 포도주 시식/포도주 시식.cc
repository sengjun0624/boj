#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> wine(n + 1, 0); 
    vector<int> dp(n + 1, 0);   

    for (int i = 1; i <= n; i++) {
        cin >> wine[i];
    }

   
    dp[1] = wine[1];
    if (n > 1) {
        dp[2] = wine[1] + wine[2];
    }


    for (int i = 3; i <= n; i++) {
        dp[i] = max({dp[i - 1],                // i번째 잔을 마시지 않는 경우
                     dp[i - 2] + wine[i],      // i번째 잔만 마시는 경우
                     dp[i - 3] + wine[i - 1] + wine[i]}); // i번째와 i-1번째를 마시는 경우
    }

    
    cout << dp[n] << endl;
    return 0;
}
