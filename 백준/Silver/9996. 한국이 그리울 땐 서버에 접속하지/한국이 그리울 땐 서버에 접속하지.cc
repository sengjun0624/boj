//
// Created by Lee SeungJun on 3/4/24.
//

#include <iostream>

using namespace std;

string pattern, file;
int n;


int main() {

    cin >> n;
    cin >> pattern;
    while (n--) {
        bool isEqual = true;
        cin >> file;
        //find prefix
        for (int i = 0; i < pattern.length() && i < file.length(); i++) {
            if (pattern[i] == '*') {
                break;
            }

            if (pattern[i] != file[i]) {
                isEqual = false;
                break;
            }
        }
        int i = pattern.length();
        int j = file.length();

        while (i--&&j--) {
            if (pattern[i] == '*') {
                break;
            }

            if (pattern[i] != file[j]) {
                isEqual = false;
                break;
            }
        }
        string ans = (isEqual&&file.length()>=pattern.length()-1) ? "DA" : "NE";
        cout << ans << "\n";
    }
}
