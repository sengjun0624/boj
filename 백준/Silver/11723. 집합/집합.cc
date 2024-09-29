#include<iostream>
#include<bitset>
using namespace std;

const int MAX = 21;
bitset<MAX>b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m; cin >> m;
	while (m--) {
		string cmd; cin >> cmd;
		if (cmd == "add") {
			int x; cin >> x;
			if (b[x] == 1) continue;
			b[x] = 1;
		}
		else if (cmd == "remove") {
			int x; cin >> x;
			if (b[x] == 0) continue;
			b[x] = 0;
		}
		else if (cmd == "check") {
			int x; cin >> x;
			cout << b[x] << "\n";
		}
		else if (cmd == "toggle") {
			int x; cin >> x;
			b[x] = !b[x];
		}
		else if (cmd == "all") {
			b.set();
		}
		else if (cmd == "empty") {
			b.reset();
		}
	}
}