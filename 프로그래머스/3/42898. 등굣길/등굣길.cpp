#include <string>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;
const int MAX=101;
const int MASK=1000000007;
int dp[MAX][MAX];
int m,n;
int dy[2]={0,1};
int dx[2]={1,0};

int dfs(int y ,int x){
    if (dp[y][x] != INT_MAX) return dp[y][x]; 
    dp[y][x]=0;
    for(int i=0;i<2;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            
            if(ny==n&&nx==m){
                dp[y][x]++;
                dp[y][x]%=MASK;
                continue;
            }
            if(nx<1||nx>m||ny<1||ny>n)continue; //인덱스 벗어남
            if(dp[ny][nx]==-1)continue; //웅덩이
            if(dp[ny][nx]!=INT_MAX)dp[y][x]+=dp[ny][nx];
            else dp[y][x]+=dfs(ny,nx);
        }
    return dp[y][x]%=MASK;
}
//dp[i][j]는 그 블럭에 도달하기위한 최단 이동횟수.
int solution(int _m, int _n, vector<vector<int>> puddles) {
    n=_n;m=_m;
    for (int i = 1; i <MAX; i++) {
        for (int j = 1; j < MAX; j++) {
            dp[i][j] = INT_MAX;
        }
    }
   if(!puddles[0].empty()){
       for(int i=0;i<puddles.size();i++){
               dp[puddles[i][1]][puddles[i][0]]=-1;
       }
   }
    return dfs(1,1)%MASK;
}