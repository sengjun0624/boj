#include <iostream>
#include <vector>

using namespace std;
const int MAX = 100005;

int n;
int last;
vector<pair<int, int> > v(MAX);

void inorder_traversal(int node) {
    if (v[node].first != -1)inorder_traversal(v[node].first);
    last = node;
    if (v[node].second != -1)inorder_traversal(v[node].second);
}

int cnt = 0;
int ans;

void simmilar_inorder_traversal(int node) {
    if (v[node].first != -1) {
        cnt++;
        simmilar_inorder_traversal(v[node].first);
    }
    if (v[node].second != -1 ) {
        cnt++;
        simmilar_inorder_traversal(v[node].second);
    }
    if (node == last) {
        ans = cnt;
        return;
    }
    cnt++;
    return;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a] = make_pair(b, c);
    }
    inorder_traversal(1);
    simmilar_inorder_traversal(1);
    cout << ans;
}