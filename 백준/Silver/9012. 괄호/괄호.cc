//
// Created by Lee SeungJun on 9/22/24.
//
#include<iostream>
#include<stack>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        stack<char>s;
        string str; cin>>str;
        bool is=true;
        for(char c: str){
            if(c=='(')s.push(c);
            else{
                if(!s.empty())s.pop();
                else {
                    is=false;
                    break;
                }
            }
        }
        if(!s.empty()||!is)cout<<"NO\n";
        else cout<<"YES\n";
    }
}