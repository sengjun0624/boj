//
// Created by Lee SeungJun on 9/7/24.
//
#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<algorithm>

using namespace std;

bool comp(string &a, string &b) {
    if (a.size() != b.size())return a.size() < b.size();
    else return a < b;
}

int main() {
    int n;
    cin >> n;

    vector<string> greater;
    while (n--) {
        string number;
        cin >> number;

        string findNum;
        for (int i = 0; i < number.size(); i++) {
            char word = number[i];
            if (isdigit(word)) {
                findNum += word;
            } else {
                if (!findNum.empty()) {
                    while (findNum.length() > 1 && findNum[0] == '0') {
                        findNum.erase(0, 1);
                    }
                    greater.push_back(findNum);
                    findNum = "";
                }
            }
        }
        if (!findNum.empty()) {
            while (findNum.length() > 1 && findNum[0] == '0') {
                findNum.erase(0, 1);
            }
            greater.push_back(findNum);
            findNum = "";
        }
    }
    if (!greater.empty()) {
        sort(greater.begin(), greater.end(), comp);

        for (auto ni: greater)cout << ni << "\n";
    }
}