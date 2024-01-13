#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int>odd(500001);
vector<int>even(500001);
int main(){
    int n,h; cin>>n>>h;

    for(int i=1;i<=n/2;i++){
        int a, b; cin>>a >>b;
        odd[a]++;
        even[h-b+1]++;
    }
    for (int i = h; i > 0; i--) {
        odd[i]+=odd[i+1];
    }
    for(int i=1;i<=h;i++){
        even[i]+=even[i-1];
    }
    vector<int>ans(h+1,0);

    for (int i = 1; i <= h; i++) {
        ans[i]=odd[i]+even[i];
    }
    sort(ans.begin(), ans.end());

    int cnt=0;
    for (int i=1;i<=h;i++) {
        if(ans[i]==ans[1])cnt++;
        else break;
    }
    cout<<ans[1]<<" "<<cnt;
}
