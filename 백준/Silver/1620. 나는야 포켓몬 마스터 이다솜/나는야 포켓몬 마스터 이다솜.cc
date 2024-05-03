#include<iostream>
#include<unordered_map>

using namespace std;
unordered_map<string, int>m1;
unordered_map<int, string>m2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n;i++) {
		string cmd;
		cin >> cmd;
		m1.insert( { cmd, i });
		m2.insert({ i, cmd });
	}

	for (int i = 1; i <= k; i++) {
		string cmd;
		cin >> cmd;
		if (atoi(cmd.c_str()) == 0) {
			cout << m1[cmd] << "\n";
		}
		else {

			cout << m2[atoi(cmd.c_str())] << "\n";
		}
	}
}