#include <string>
#include <vector>
#include <map>
using namespace std;
map<string,int>m;
int solution(vector<vector<string>> clothes) {
    for(int i=0;i<clothes.size();i++){
        m[clothes[i][1]]++;
    }
    int answer = 1;
    for(auto pair : m)answer*=pair.second+1;
    
    return answer-1;
}