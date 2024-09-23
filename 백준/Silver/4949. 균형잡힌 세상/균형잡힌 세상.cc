#include<iostream>
#include<stack>

using namespace std;

bool isValid(const string &str) {
    stack<char> st;
    for (char c: str) {
        if (c == '(' || c == '[')st.emplace(c);
        else if (c == ')') {
            if (st.empty() || st.top() != '(')return false;
            st.pop();
        } else if (c == ']') {
            if (st.empty() || st.top() != '[')return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    while (true) {
        string str;
        getline(cin,str);
        if (str == ".")break;
        //cout<<str<<"\n";
        if(isValid(str))cout<<"yes\n";
        else cout<<"no\n";
    }
}