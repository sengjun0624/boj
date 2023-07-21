#include<iostream>
#include<bitset>
#include<cmath>
using namespace std;
int t, n, m;
int main() {
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> m;
		int mask = pow(2, n)-1;
		bitset<27>my_b(mask);
		if ((m & mask) == mask) {
			cout <<"#" <<i<< " ON\n";
		}
		else cout <<"#" <<i<< " OFF\n";
	}
}