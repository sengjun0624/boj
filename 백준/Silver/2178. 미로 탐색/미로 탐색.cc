#include<iostream>
#include<vector>
#include<queue>
using namespace std;
queue<pair<int, int>>Q;
pair<int, int>p;
bool arr[101][101];
int dis[101][101];
int direction_x[] = { 0, 0, 1 ,-1 }; //위 아래 오른쪽 왼쪽
int direction_y[] = { -1 ,1 ,0 ,0 };
int X, Y;
void bfs(int x,int y) {
	arr[y][x] = false;
	dis[y][x] = 1;
	p = make_pair(x, y);
	Q.push(p);

	while (!Q.empty()) {
		int a = Q.front().first;
		int b = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int real_x = a + direction_x[i];
			int real_y = b + direction_y[i];
			if (real_x >= 1 && real_x <= X && real_y >= 1 && real_y <= Y && arr[real_y][real_x] == true) {
				arr[real_y][real_x] = false;
				dis[real_y][real_x] = dis[b][a] + 1;
				if (real_y == Y && real_x == X) {
					cout << dis[real_y][real_x];
					exit(0);
				}
				p = make_pair(real_x, real_y);
				Q.push(p);
			}
		}
	}
}
int main() {
	cin >> Y >> X;
	string cmd;
	for (int i = 1; i <= Y;i++) {
		cin >> cmd;
		for (int j = 0; j < X; j++) {
			arr[i][j+1] = cmd[j] - '0';
		}
	}
   bfs(1,1);
}