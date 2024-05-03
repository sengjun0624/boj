#include<iostream>
#include<map>
#include<vector>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		multimap<string, string>m;
		vector<string>keys;
		cin >> n;
		while (n--) {
			string value, key;
			cin >> value >> key;
			if (!m.count(key)) { keys.push_back(key);}
			m.insert({ key,value });
		}
		int add{ 1 };
		for (int i = 0; i < keys.size(); i++) {
			int cnt = m.count(keys[i])+1;
			add *= cnt;
		}
		cout << add -1<<"\n";
	}

}