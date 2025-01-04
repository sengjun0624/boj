#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

const int MAX=10000000;
int answer = 0;

int prime[MAX];
bool check[7];
bool CHECK[MAX];
string s="";
string numbers;

void eratos() {
    prime[0]=1;
    prime[1]=1;
    for(int i=2;i<=sqrt(MAX);i++){
        if(prime[i]==1)continue;
        for(int j=i+i;j<MAX;j+=i){
            prime[j] = 1;
        }
    }
}
void recursive(int idx,int len){
    if(idx==len){
        //TODO 여기서 문자열 답으로 처리
        int temp=stoi(s); cout<<s<<"\n";
        if(CHECK[temp])return;
        CHECK[temp]=true;
        if(prime[temp]==0)answer++;
        return;
    }
    for(int i=0;i<numbers.length();i++){
        if(check[i])continue;
        s += numbers[i];
        check[i]=true;
        recursive(idx+1,len);
        check[i]=false;
        s = s.substr(0,s.length()-1);
    }
}
int solution(string arg) {
    numbers=arg;
    eratos();
    for(int i=0;i<arg.length();i++){
        recursive(0,i+1);
    }
    return answer;
}