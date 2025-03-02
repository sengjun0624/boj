#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
#define fastio()  cin.tie(0);    ios::sync_with_stdio(0);
#define MAX 1000000

int n, m, k;
vector<ll> v;
vector<ll> tree(4 * MAX);

void input();
void solve();
ll build(int node, int left, int right);
void update(int node, int index, int left, int right, ll newValue);
ll sum(int node, int left, int right, int start, int end);

int main() {
    fastio();
    input();
    solve();
}

void input() {
    cin >> n >> m >> k;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    build(1, 0, n - 1);
}

void solve() {
    ll cmd, b, c;
    for (int i = 0; i < m + k; i++) {
        cin >> cmd >> b >> c;
        if (cmd == 1) {
            update(1, b - 1, 0, n - 1, c);  // 1-based → 0-based 인덱스 변환
            v[b - 1] = c; // 벡터 값도 업데이트
        } else if (cmd == 2) {
            cout << sum(1, 0, n - 1, b - 1, c - 1) << "\n"; // 1-based → 0-based 변환
        }
    }
}

ll build(int node, int left, int right) {
    if (left == right) return tree[node] = v[left];

    int mid = (left + right) / 2;
    return tree[node] = build(node * 2, left, mid) + build(node * 2 + 1, mid + 1, right);
}

void update(int node, int index, int left, int right, ll newValue) {
    if (index < left || index > right) return; // 범위 밖이면 return

    if (left == right) {  
        tree[node] = newValue;  // 리프 노드에서 직접 변경
        return;
    }

    int mid = (left + right) / 2;
    update(node * 2, index, left, mid, newValue);
    update(node * 2 + 1, index, mid + 1, right, newValue);

    tree[node] = tree[node * 2] + tree[node * 2 + 1]; // 부모 노드 갱신
}

ll sum(int node, int left, int right, int start, int end) {
    if (start > right || end < left) return 0; // 구간 밖이면 0 반환
    if (start <= left && right <= end) return tree[node]; // 포함되면 노드 값 반환

    int mid = (left + right) / 2;
    return sum(node * 2, left, mid, start, end) + sum(node * 2 + 1, mid + 1, right, start, end);
}
