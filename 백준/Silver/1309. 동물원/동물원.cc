#include<iostream>

using namespace std;
int n;
const int MAX = 100001;
int dp[MAX];

/**
 * 문제
어떤 동물원에 가로로 두칸 세로로 N칸인 아래와 같은 우리가 있다.
이 동물원에는 사자들이 살고 있는데 사자들을 우리에 가둘 때, 가로로도 세로로도 붙어 있게 배치할 수는 없다. 이 동물원 조련사는 사자들의 배치 문제 때문에 골머리를 앓고 있다.

동물원 조련사의 머리가 아프지 않도록 우리가 2*N 배열에 사자를 배치하는 경우의 수가 몇 가지인지를 알아내는 프로그램을 작성해 주도록 하자.
사자를 한 마리도 배치하지 않는 경우도 하나의 경우의 수로 친다고 가정한다.
 * 풀이
 * 열이 맨 윗줄에 하나씩 추가될 때 (N이 증가할 때) 새로 추가된 열에 놓을 수 있는 경우의수는 3가지다, 공백 , 왼쪽블럭 , 오른쪽블럭
 * 새로추가된 열이 공백일때 -> N-1일때의 경우의수와 같다. 맨 윗줄이 공백이므로 아랫줄은 어떻게 놓든 이전과 동일하다.
 * 새로 추가된 열의 왼쪽 블럭에 사자를 놓았을 때 -> N-1일때의 공백의 경우의수 + 오른쪽 블럭에 놓는 경우의 수와 같다.
 *      N-1일때의 공백의 경우의 수는 N-1열이 비었다는 의미로 새로 추가된 블럭이 왼쪽이든 오른쪽이든 관계없다. 또한 오른쪽 블럭을 선택했던 경우의 수 역시 동일하게 가져올 수 있다.
 * 새로 추가된 열의 오른쪽 블럭에 사자를 놓았을 때  -> 왼쪽과 동일하다.
 * 정리하면 N 열의 경우의수는 N-1열의 경우의 수 + N-1 열의 공백의 경우의수 + N-1 열의 오른쪽 경우의 수 + N-1 열의 공백의 경우의수 + N-1 열의 왼쪽 경우의 수이다.
 * N-1 열의 경우의수가 곧 N-1열의 공백, 왼쪽, 오른쪽의 합이므로 정리하면 (N-1열의 공백+왼쪽+오른쪽)*2 + N-1열의 공백을 더한것과 같다.
 * N-1 열의 공백수는 N-2열의 전체 경우의수와 같으므로,
 * dp[i]= dp[i-1] * 2 + dp[i-2] => n-1열의 공백 경우의 수가 된다.
 */
int main() {
    cin >> n;
    dp[1] = 3;
    dp[2] = 7;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
    }
    cout<<dp[n];
}