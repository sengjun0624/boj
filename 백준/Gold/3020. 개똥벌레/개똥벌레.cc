//
// Created by Lee SeungJun on 1/13/24.
//

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> odd; //홀수
vector<int> even; //짝수
int idx_2, idx_1;

int main() {
    int n, h;
    cin >> n >> h;
    vector<int> ans(h + 1, 0);

    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        if (i % 2) { //odd
            odd.emplace_back(num);
        } else {
            even.emplace_back(num);
        }
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end(), greater<int>());

    int o = odd.size()-1;
    int e = even.size()-1;

    ans[1]=n/2;
    ans[h]=n/2;

    for (int i = 2; i < h; i++) { //구간

        while (idx_1 < odd.size()) {
//            cout<<"idx_1 : "<<idx_1<<" "<<odd[idx_1]<<"\n";
            if (odd[idx_1]>=i)break; //i보다 작은애 바로 다음거.
            idx_1++;
        }
        while (idx_2 < odd.size()) {
//            cout<<"idx_2 : "<<idx_2<<" "<<even[idx_2]<<"\n";
            if(even[idx_2]<h-i+1)break; //i에 닿는 종유석 마지막 지점 찾기.
            idx_2++;
        }

        ans[i] += o-idx_1+1;
        ans[i] += idx_2;
    }

//    for(int test: ans) {
//        cout<<test <<" ";
//    }
//    cout<<"\n";

    sort(ans.begin(), ans.end());
    int cnt=0;
    for (int i = 1; i <= h; i++) {
        if(ans[i]!=ans[1])break;
        cnt++;
    }
    cout<<ans[1]<<" "<<cnt;
}