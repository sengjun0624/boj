//
// Created by Lee SeungJun on 9/21/24.
//
#include<iostream>
#include<vector>
#include<string>
#include <iomanip>
using namespace std;
int arr[2880];

int main() {
    vector<pair<int, int>> v;
    int n;
    cin >> n;
    while (n--) {
        int t;
        string time;
        cin >> t >> time;
        int total = 0;
        int hour{0}, second{0};
        hour = stoi(time.substr(0, 2));
        second = stoi(time.substr(3, 2));
        total = 60 * hour + second;
      
        arr[total] = t;
    }
    int aTime = 0;
    int bTime = 0;
    int a = 0;
    int b = 0;
    for (int i = 0; i < 2880; i++) {
        if (arr[i] != 0) {
            (arr[i] == 1) ? a++ : b++;
        }
        if (a == b)continue;
        if (a > b)aTime++;
        else bTime++;
    }

    int a_hour = aTime / 60;
    int a_sec = aTime % 60;
    int b_hour = bTime / 60;
    int b_sec = bTime % 60;

    // 출력
    std::cout << std::setw(2) << std::setfill('0') << a_hour << ":"
              << std::setw(2) << std::setfill('0') << a_sec << std::endl;

    std::cout << std::setw(2) << std::setfill('0') << b_hour << ":"
              << std::setw(2) << std::setfill('0') << b_sec << std::endl;

}