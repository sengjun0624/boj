#include<iostream>
#include<cmath>
using namespace std;
int N, M;
bool check[10];
int is(int num) {
	int cnt=0;
	bool can = true;
	if (num == 0&&check[num]) {
		return 1;
	}
	while (num!=0&&can) {
		int temp = num % 10;
		if (check[temp]) {
			cnt++;
		}
		else {
			can = false;
		}
		num /= 10;
	}
	if (can) {
		return cnt;
	}
	else return 0;
}
int main() {
	cin >> N >> M;
	fill_n(check, 10, true);
	while (M--)
	{
		int a;
		cin >> a;
		check[a] = false;
	}
	int Min = abs(N - 100);
	for (int i = 0; i < 1000000; i++) {
		int a = is(i);
		if (a!=0) {
			int total = abs(N - i) + a;
			Min = min(Min, total);
		}
	}
	cout << Min;
}