//
// Created by Lee SeungJun on 4/8/24.
//

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v1;
vector<int> v2;


int lowerBound(int st, int ed, int k) {
    int a = -1;
    while (st < ed) {
        int mid = (st + ed) / 2;

        if (v2[mid] < k) {
            st = mid + 1;
            a = mid;
        } else ed = mid ;
    }
    return a;
}

int n, m;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int ans = 0;
        v1.clear();
        v2.clear();

        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            v1.push_back(num);
        }
        for (int i = 0; i < m; i++) {
            int num;
            cin >> num;
            v2.push_back(num);
        }

        sort(v2.begin(), v2.end());

        //A를 하나씩 보면서 B의 원소의 lowerBound를 이분탐색으로 search
        for (int i = 0; i < n; i++) {
            int low = lowerBound(0, m, v1[i]);

            ans += low + 1;
        }
        cout << ans<<"\n";
    }

}