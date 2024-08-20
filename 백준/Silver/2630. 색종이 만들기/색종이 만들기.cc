#include<iostream>
#include<vector>
#include<string>

using namespace std;
char font[2] = {'w', 'b'};
//0 is white, 1 is blue
const int Max = 128;
int arr[Max][Max];

string solve(int y, int x, int n) {
    if(n==1)return string(1,font[arr[y][x]]);
    int first = arr[y][x];
    bool is = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[y+i][x+j] != first) {
                is = false;
                break;
            }
        }
        if(!is)break;
    }
    if (is){
        return string(1, font[first]);
    }
    string upperLeft = solve(y, x, n / 2);
    string upperRight = solve(y, x + n / 2, n / 2);
    string lowerLeft = solve(y + n / 2, x, n / 2);
    string lowerRight = solve(y + n / 2, x + n / 2, n / 2);

    return upperLeft+upperRight+lowerLeft+lowerRight;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    string ret=solve(0, 0, n);
    int blue=0;
    int white=0;
    for(char c:ret){
        if(c=='b')blue++;
        else white++;
    }
    cout<<white<<"\n"<<blue;
}