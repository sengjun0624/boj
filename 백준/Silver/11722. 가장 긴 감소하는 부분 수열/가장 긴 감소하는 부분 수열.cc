/**
* 수열 A가 주어졌을 때, 가장 긴 감소하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 30, 10, 20, 20, 10} 인 경우에 가장 긴 감소하는 부분 수열은 A = {10, 30, 10, 20, 20, 10}  이고, 길이는 3이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)
*/
#include<iostream>
#include <cstring>

const int MAX = 1001;
int dp[MAX];
int value[MAX];
int n;
using namespace std;

int main() {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> value[i];
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j <= i; j++) {
            //i가 마지막이라는걸 인지. i의 최대길이는 j에서 하나더한것 혹은 이미 기존의 값.
            if (value[i] < value[j])dp[i] = max(dp[i], dp[j] + 1);//j까지의값이잖아.
        }
    }
    int answer=0;
    for(auto a:dp)answer = max(answer, a);
    cout << answer;
}