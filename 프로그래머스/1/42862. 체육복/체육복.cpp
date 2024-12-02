#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
   
        vector<int>arr (n+1 ,1);
        int answer = 0;
    
        for(int i=0;i<lost.size();i++){
            arr[lost[i]]--;
        }
        for(int i=0;i<reserve.size();i++){
            arr[reserve[i]]++;
        }
        for(int i=1;i<arr.size();i++){
            if(arr[i]<1){
                if(arr[i-1]>1){
                        arr[i]++;
                        arr[i-1]--;
                        answer++;
                      
                    }
                else if(i+1<arr.size()){
                    if(arr[i+1]>1){
                        arr[i]++;
                        arr[i+1]--;
                        answer++;
                      
                    }
                }
                continue;
            }
            answer++;
        }
    return answer;
    
}