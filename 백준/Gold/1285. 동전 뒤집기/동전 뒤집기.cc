#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int n;
int MinTailCoin = 0;
const int MAX = 20;
int arr[MAX][MAX];

void countTail() {
    int TailCoin = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (arr[row][col] == 1)TailCoin++;
        }
    }
    if (TailCoin < MinTailCoin)MinTailCoin = TailCoin;
}

void turnCoin(int cnt) {
    if (cnt == (n)) {
/*
        for(int i=0;i<n;i++){
            for (int j = 0; j < n; j++) {
                cout<<arr[i][j]<<",";
            }
            cout<<'\n';
        }            cout<<'\n';
*/

        //열을 뒤집을지 말지 결정함.
        vector<int>cols;

        for (int i = 0; i < n; i++) { //열
            int temp = 0;
            for (int j = 0; j < n; j++) { //행
                if (arr[j][i] == 1)temp++;
            }
            if (temp >= n / 2) {
                for (int j = 0; j < n; j++) {
                    if (arr[j][i] == 1)arr[j][i]= 0;
                    else arr[j][i] = 1;
                }
                cols.push_back(i);
            }
        }
        countTail();
        for (int i : cols) {
            for (int j = 0; j < n; j++) {
                if (arr[j][i] == 1)arr[j][i] = 0;
                else arr[j][i] = 1;
            }
        }
        return;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            //행
            int cur = arr[cnt][j];
            // 동전 뒤집기
            if (cur == 0)arr[cnt][j] = 1;
            else arr[cnt][j] = 0;
        }
        turnCoin(cnt + 1);
    }

}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == 'H')arr[i][j] = 0;
            else {
                arr[i][j] = 1;
                MinTailCoin++;
            }
        }
    }
    turnCoin(0);
    cout << MinTailCoin;
}