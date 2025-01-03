#include <string>
#include <vector>
#include<iostream>
using namespace std;
int answer[5];
int sol[5];
int words[6]={' ','A','E','I','O','U'};\

int len,cnt,ans;
bool check(){
    for(int num:sol)cout<<num<<" ";
    cout<<"\n";
    for(int i=0;i<5;i++){
        if(sol[i]!=answer[i]) return false;
    }
    return true;
}
void recur(int idx){
    if(idx==5)return;
    for(int i=1;i<=5;i++){
        cnt++;
        sol[idx]=i;
        if(check()){
            ans = cnt;
            return;
        }
        recur(idx+1);
        sol[idx]=0;
    }
}
int solution(string word) {
    len=word.length();
    for(int i=0;i<len;i++){
        for(int j=1;j<6;j++){
            if(word[i]==words[j]){
                answer[i]=j;
                break;
            }
        }
    }
    recur(0);
    return ans;
}