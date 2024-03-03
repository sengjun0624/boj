//
// Created by Lee SeungJun on 3/3/24.
//

#include <iostream>
#include <string>

using namespace std;

string s;
int shift = 13;
char base;

int main() {
    getline(cin,s);
//     cout<<s<<"\n";
    for (char &c: s) {
        if (isalpha(c)) {
            base = isupper(c) ? 'A' : 'a';
            c = ((c - base + shift) % 26) + base;
//            cout<<"shift alpha : "<<c<<" ";
        }
    }
    for (char &c: s) {
        cout << c;
    }

}