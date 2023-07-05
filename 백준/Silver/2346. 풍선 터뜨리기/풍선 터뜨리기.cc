#include<iostream>
#include<queue>

using namespace std;
queue<int>q;
int N;
bool check[1000];
int arr[1000];
int main() {
	fill_n(check, 1000, true);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		arr[i] = n;
	}
	int cnt = N;
	int idx = 0;
	while (cnt--) {
		if (cnt == 0) {
			q.push(idx + 1);
			break;
		}
		check[idx] = false;
		q.push(idx+1);
		int tmp = arr[idx];
		if (tmp > 0) {
			while (tmp--) {
				idx = (idx + 1) % N;
				//if (N == 1)break;
				while (!check[idx]) {
					idx = (idx + 1) % N;
				}
			}
		}
		else {
			tmp = -tmp;
			while (tmp--) {
				idx = (idx - 1+N) % N;
				//if (N == 1)break;
				while (!check[idx]) {
					idx = (idx - 1+N) % N;
				}
			}
		}
	}
	while (!q.empty()) {
		cout << q.front()<<" ";
		q.pop();
	}
}