//
// Created by Lee SeungJun on 1/13/24.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

const int Max = 51; // 축의 최대길이

int house, ox, oy, n; //집의수, 시작점 x,y주소 , 맵의 n

char m[Max][Max]; //맵
int s[Max][Max]; //경사
bool visited[Max][Max]; //bfs 방문 체크
vector<int> f; // 경사값의 중복 제거 , 정렬용 배열

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool bfs(int l, int h) { //low부터 high까지
    int val=s[oy][ox]; int delivery=0;

    if(val>f[h]||val<f[l])return false;
    queue<pair<int,int>>q;
    q.push({oy,ox}); visited[oy][ox]=1;

    while (!q.empty()) {
        int y=q.front().first; int x=q.front().second; q.pop();

        for (int i = 0; i < 8; i++) {
            int ny=y+dy[i]; int nx=x+dx[i]; int nval=s[ny][nx];
            if(visited[ny][nx] || nval > f[h] || nval< f[l])continue;
            visited[ny][nx]=1;
            q.push({ny, nx});
            if(m[ny][nx]=='K')delivery++;
        }
    }
    if(delivery==house)return true;
    if(delivery!=house)return false;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> m[i][j];
            if (m[i][j] == 'P') {
                ox = j;
                oy = i;
            } else if (m[i][j] == 'K')house++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> s[i][j];
            f.emplace_back(s[i][j]);
        }
    }
    sort(f.begin(), f.end());
    f.erase(unique(f.begin(), f.end()), f.end());

    int ans = 0x7fffffff; int ed=0; int st=0;

    while (st < f.size()) {
        memset(visited, false, sizeof(visited));
        if(bfs(st,ed)){ //집을 찾음
            int temp=f[ed]-f[st];
            ans = min(temp,ans);
            st++;
        }else{
            if(ed<f.size())ed++;
            else break;
        }
    }
    cout<<ans;
}