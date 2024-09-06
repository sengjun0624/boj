#include<iostream>
#include<queue>
using namespace std;
const int Max=50;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

int main(){
    int t; cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int map[Max][Max]={0};
        for(int i=0;i<k;i++){
            int y,x;
            cin>>y>>x;
            map[y][x]=1;
        }
        bool visit[Max][Max] = {false};
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j]==1&&!visit[i][j]){
                    ans++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    visit[i][j]=true;
                    while(!q.empty()){
                        auto it = q.front();
                        q.pop();
                        int y=it.first; int x=it.second;
                        for(int i=0;i<4;i++){
                            int ny=y+dy[i];
                            int nx=x+dx[i];
                            if(ny<0||ny>n-1||nx<0||nx>m-1||visit[ny][nx])continue;
                            if(map[ny][nx]==0)continue;
                            q.push({ny,nx});
                            visit[ny][nx]=true;
                        }
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
}