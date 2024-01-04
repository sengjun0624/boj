//
// Created by Lee SeungJun on 1/4/24.
//
#include<iostream>
#include<stack>

using namespace std;

stack<char> s;

/*
 * 1. char는 무조건 출력.
 * 2. +가 stack에 들어갈때는 안에 있는 기호 모두 나옴
 * 3. *가 stack에 들어갈때는 +- 빼고 다 빼버림
 * 4. ( 가 있는경우 스택에 (를 넣고 )까지 똑같이 한 후에 )를 만나면 (까지의 모든 기호를 출력
 */
int main() {

    string cmd;
    cin >> cmd;
    for (char cur: cmd) {

        if (cur == '+' || cur == '-') {


            while (!s.empty()) {
                if(s.top()=='(')break;
                cout << s.top();
                s.pop();
            }
        } else if (cur == '*' || cur == '/') {

            while (!s.empty()) {
                if(s.top() == '*' || s.top() == '/') {
                    cout << s.top();
                    s.pop();
                }
                else break;
            }
        } else if (cur == ')') {

            while (!s.empty() && s.top() != '(') {
                cout << s.top();
                s.pop();
            }
            s.pop();
            continue;
        } else if (cur >= 'A' && cur <= 'Z') {
            cout << cur;
            continue;
        }
        s.push(cur);
    }

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    return 0;
}