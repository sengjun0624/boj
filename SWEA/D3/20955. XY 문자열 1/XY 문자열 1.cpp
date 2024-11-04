#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int t;
string s1, s2;


void solve() {
    while (s1.length() < s2.length()) {
        char c = s2[s2.length() - 1];
        //Y든 X든 마지막 문자를 자름.
        s2 = s2.substr(0, s2.length() - 1);
        if (c == 'Y')reverse(s2.begin(), s2.end());
    }
    if (s1 == s2)cout << "Yes\n";
    else cout << "No\n";

}

void input() {

    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> s1 >> s2;
        cout << "#" << i << " ";
        solve();
    }
}

int main() {
    input();
}