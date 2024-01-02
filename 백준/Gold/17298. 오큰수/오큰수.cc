#include<iostream>
#include<stack>
#include<vector>
#define p cin.tie(0)->ios_base::sync_with_stdio
using namespace std;
stack <int>last;
vector<int>num_list;
int main()
{
	p;
	int N;
	cin >> N;
vector<int>answer(N,-1);
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		num_list.push_back(num);
	}
	for (int i = N - 1; i >= 0; i--) {
		if (last.empty()) {
			last.push(num_list[i]);
		}
		else {
			if (last.top() > num_list[i]) {
				answer[i] = last.top();
			}
			else {
				while (!last.empty()) {
					if (last.top() > num_list[i]) {
						answer[i] = last.top();
						break;
					}
					last.pop();
				}
			}
				last.push(num_list[i]);
		}
	}
	for (int i = 0; i <N-1; i++) {
		cout << answer[i] << " ";
	}
	cout << answer[N-1] << "\n";

}