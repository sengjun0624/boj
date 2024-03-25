#include<iostream>

using namespace std;

int n, k;
int arr[100001];
int Max = -9999999999;
int main() {

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int l = 0;
	int ed = 1;
	int total = 0;
	for (int st = 1; st <= n; st++) {
		while (l < k && ed <= n) {
			total += arr[ed];
			ed++;
			l++;
		}
		if (l == k) {
			if (total > Max) {
				Max = total;
			}
		}
		total -= arr[st]; l--;
	}
	cout << Max;
}