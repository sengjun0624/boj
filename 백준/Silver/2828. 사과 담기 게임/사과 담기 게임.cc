#include<iostream>
#include<vector>

using namespace std;
vector<int> v;
int arr[10];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        v.push_back(num-1);
    }
    int left{0}, right{left + m - 1};
    int ans = 0;
    for (int num: v) {
        if (num < left) {
            while (left > 0 && left != num) {
                left--;
                ans++;
                right=left+m-1;
            }
        } else if (num > right) {
            while (right < n && right != num) {
                right++;
                ans++;
                left=right-m+1;
            }
        }
    }
    cout<<ans;
}