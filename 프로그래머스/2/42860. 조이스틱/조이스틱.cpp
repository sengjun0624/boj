#include <string>
#include <vector>
#include<iostream>
using namespace std;

int dp[26] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1};
int solution(string name) {
    int answer = 0;
    for(auto c:name)answer+=dp[c-'A'];
    int len=name.length();
    int gap=len-1;
    for(int i=0;i<name.length();i++){
        int n_i=i+1;
        while(n_i<len&&name[n_i]=='A'){
            n_i++;
        }
        gap=min(gap, i + len - n_i+min(i, len-n_i));
    }
    cout<<gap;
    answer+=gap;
    return answer;
}