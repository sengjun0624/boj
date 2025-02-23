#include<iostream>
#include<vector>

#define MAX 100001
using namespace std;
int arr[MAX], prefixSum[MAX];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, Q; // N: 배열 크기, Q: 질의 개수
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    while (Q--) {
        int L, R; // L부터 R까지의 구간 합
        cin >> L >> R;
        cout << prefixSum[R] - prefixSum[L - 1] << "\n";
    }
}