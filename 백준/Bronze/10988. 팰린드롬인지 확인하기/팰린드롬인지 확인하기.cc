//
// Created by Lee SeungJun on 3/3/24.
//

#include<iostream>
#include<algorithm>

using namespace std;

string cmd;

int main() {
    cin>>cmd;
    string s = cmd;
    reverse(cmd.begin(),cmd.end());
    for (int i = 0; i < cmd.length(); i++) {
        if(cmd[i]!=s[i]) {
            cout<<0;
            return 0;
        }
    }
    cout<<1;
}