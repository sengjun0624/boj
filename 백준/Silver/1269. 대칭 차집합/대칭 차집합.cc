#include<iostream>
#include<algorithm>
using namespace std;

int arr1[200001];
int arr2[200001];

int A, B;

int main() {
	cin >> A >> B;

	for (int i = 0; i < A;i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < B; i++) {
		cin >> arr2[i];
	}
	sort(arr1, arr1+A);
	sort(arr2, arr2 + B);

	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < A; i++) {
		int st = 0; int ed = B-1;
		while (st <= ed) {
			int mid = (st + ed) / 2;
			if (arr2[mid] == arr1[i]) {
				cnt ++; 
				break;
			}
			else if (arr2[mid] < arr1[i]) {
				st = mid+1;
			}
			else {
				ed= mid -1;
			}
		}
	}
	ans += A - cnt;
	//cnt = 0;
	//for (int i = 0; i < B; i++) {
	//	int st = 0; int ed = A - 1;
	//	while (st <= ed) {
	//		int mid = (st + ed) / 2;
	//		if (arr1[mid] == arr2[i]) {
	//			cnt++;
	//			break;
	//		}
	//		else if (arr1[mid] < arr2[i]) {
	//			st = mid + 1;

	//		}
	//		else {
	//			ed = mid - 1;
	//		}
	//	}
	//}
	ans += B - cnt;
	cnt = 0;
	cout << ans;

}