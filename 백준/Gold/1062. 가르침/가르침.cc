#include<iostream>
#include<bitset>
#include<algorithm>
/*
 * 남극에 사는 김지민 선생님은 학생들이 되도록이면 많은 단어를 읽을 수 있도록 하려고 한다.
 * 그러나 지구온난화로 인해 얼음이 녹아서 곧 학교가 무너지기 때문에,
 * 김지민은 K개의 글자를 가르칠 시간 밖에 없다. 김지민이 가르치고 난 후에는,
 * 학생들은 그 K개의 글자로만 이루어진 단어만을 읽을 수 있다.
 * 김지민은 어떤 K개의 글자를 가르쳐야 학생들이 읽을 수 있는 단어의 개수가 최대가 되는지 고민에 빠졌다.
    남극언어의 모든 단어는 "anta"로 시작되고, "tica"로 끝난다.
    남극언어에 단어는 N개 밖에 없다고 가정한다. 학생들이 읽을 수 있는 단어의 최댓값을 구하는 프로그램을 작성하시오.
 */
using namespace std;
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// 필요한거 일단 마스크로 쓸거, 그다음 k개 고르면 단어랑 비교하기. 단어 비트셋으로 하면 좋을듯?

const int MAX = 50;
int N, K;
bitset<26> words[MAX];
bitset<26> mask;
int ans = 0;


void solve(int idx, int len) {
    if (len == K - 5) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if ((mask | words[i]) == mask)cnt++;
        }
        ans = max(ans, cnt);
        return;
    }
    for (int i = idx; i < 26; i++) {
        if (mask[i] == 1)continue;
        mask[i] = 1;
        solve(i + 1, len + 1);
        mask[i] = 0;
    }
}

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        for (char c: word) {
            words[i][c - 'a'] = 1;
        }
    }

    mask['a' - 'a'] = 1;
    mask['c' - 'a'] = 1;
    mask['t' - 'a'] = 1;
    mask['n' - 'a'] = 1;
    mask['i' - 'a'] = 1;
   // cout << mask << "\n";
    solve(0, 0);
    cout << ans;
}
