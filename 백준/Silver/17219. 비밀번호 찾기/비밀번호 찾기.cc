//
// Created by Lee SeungJun on 12/19/23.
//

#include<iostream>
#include<unordered_map>

using namespace std;

unordered_map<string,string>um;

int main(){
    int n,m; cin>>n>>m;
    while(n--){
        string addr,pwd; cin>>addr>>pwd;
        um[addr]=pwd;
    }
    while(m--){
        string id; cin>>id;
        cout<<um[id]<<"\n";
    }
}