#include <iostream>
#include <queue>
#include<vector>
#include<algorithm>

using namespace std;
priority_queue<int,vector<int>,greater<>>q;

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int pi;
        cin>>pi;
        q.push(pi);
    }
    int res=0;
    int total_cnt=0;

    while (!q.empty()) {
        int num=q.top();
        q.pop();
        res+=total_cnt+num;
        total_cnt+=num;
    }
    cout<<res<<"\n";
    return 0;
}
