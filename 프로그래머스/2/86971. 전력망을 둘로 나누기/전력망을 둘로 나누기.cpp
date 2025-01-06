#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include<iostream>
using namespace std;

const int MAX = 101;

vector<int> edge[101];
queue<int> q;

bool visit[MAX];

int bfs() {
    int cnt = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if(edge[cur].empty())continue;
        for (int next: edge[cur]) {
            if (visit[next])continue;
            visit[next] = true;
            q.push(next);
            cnt++;
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;

    for (int i = 0; i < wires.size(); i++) {
        //0부터 len-1까지 돌면서 엣지리스트에서 하나 삭제
        for (int j = 0; j < wires.size(); j++) {
            // 삭제한 엣지 제외하고 그래프 만들기
            if (j == i)continue;
            int a = wires[j][0];
            int b = wires[j][1];
            
            edge[a].emplace_back(b);
            edge[b].emplace_back(a);
        }
        vector<int> result;
       // start 노드부터 n번 노드까지 
        for (int start = 1; start <= n; start++) {
            // 방문하지 않은 노드부터 시작해서 bfs
            if (!visit[start]) {
                q.push(start);
                visit[start] = true;
                result.push_back(bfs());
                
            }
        }
        answer=min(answer,abs(result[0]-result[1]));
        //엣지 초기화
        for(int i=1;i<=n;i++){
            edge[i].clear();
        }
        memset(visit, false, sizeof(visit));
        
    }
    return answer;
}