
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> v;

int main() {
    int n, m;

    cin >> n >> m;

    while (m--) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end(), greater<>());
    int st = 1;
    int ed = v[0];

    int ans=999999;
    while (st <= ed) {
        int mid = (st + ed) / 2;
        int cnt = 0;

        for (int a: v) {
            if (a % mid == 0) {
                cnt += (a / mid);
            } else {
                cnt += (a / mid) + 1;
            }
        }

        if (cnt <= n) {
            ed=mid-1;
            ans=mid;
        } else st = mid+1;
    }
    cout<<ans;

}