/**
* ChAOS(Chung-ang Algorithm Organization and Study) 회장이 되어 일이 많아진 준석이는 시험기간에도 일 때문에 공부를 하지 못하다가 시험 전 날이 되어버리고 말았다. 다행히도 친절하신 교수님께서 아래와 같은 힌트를 시험 전에 공지해 주셨다. 내용은 아래와 같다.

여러 단원을 융합한 문제는 출제하지 않는다.
한 단원에 한 문제를 출제한다. 단, 그 단원에 모든 내용을 알고 있어야 풀 수 있는 문제를 낼 것이다.
이런 두가지 힌트와 함께 각 단원 별 배점을 적어 놓으셨다. 어떤 단원의 문제를 맞추기 위해서는 그 단원의 예상 공부 시간만큼, 혹은 그보다 더 많이 공부하면 맞출 수 있다고 가정하자. 이때, ChAOS 회장 일로 인해 힘든 준석이를 위하여 남은 시간 동안 공부해서 얻을 수 있는 최대 점수를 구하는 프로그램을 만들어 주도록 하자.

입력
첫째 줄에는 이번 시험의 단원 개수 N(1 ≤ N ≤ 100)과 시험까지 공부 할 수 있는 총 시간 T(1 ≤ T ≤ 10000)가 공백을 사이에 두고 주어진다.

둘째 줄부터 N 줄에 걸쳐서 각 단원 별 예상 공부 시간 K(1 ≤ K ≤ 1000)와 그 단원 문제의 배점 S(1 ≤ S ≤ 1000)가 공백을 사이에 두고 주어진다.
*/
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;
int n, t;
const int COL_MAX = 10001;
const int ROW_MAX = 101;
int dp[ROW_MAX][COL_MAX];
//value[0] => 필요한 시간, value[1]=> 가치
int value[ROW_MAX][2];

void solve() {

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= t; j++) {
            int weight = value[i][0];
            int worth = value[i][1];
            // 이전 아이템까지 선택한 값과 이전 열에 내가 추가하려는 아이템의 무게만큼 뺀값에 현재값 더한것중에 큰것.
            if(j-weight>=0) dp[i][j] = max(dp[i - 1][j], dp[i-1][j - weight] + worth);
            else dp[i][j]=dp[i-1][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> value[i][j];
        }
    }
    solve();
    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j < t; j++) {
            cout<<dp[i][j]<<", ";
        }cout<<endl;
    }*/
    cout<<dp[n][t];
}