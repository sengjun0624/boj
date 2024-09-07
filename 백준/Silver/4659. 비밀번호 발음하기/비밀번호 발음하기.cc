#include<iostream>

using namespace std;

bool isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return false;
}

int main() {
    //양수면 모음, 음수면 자음
    
    while (true) {
        int cnt = 0;
        string pw;
        cin >> pw;
        if (pw == "end")break;
        bool isIncludeVowel = false; // 하나이상의 모음
        bool canNot3Words = true; //3개이상 모음이나 자음 금지
        bool canNotSameWords = true; //두개이상 같은 알파벳 금지 ,ee oo 제외

        char old = ' ';
        for (char c: pw) {
            if (old != ' ' && old == c && old != 'e' && old != 'o')canNotSameWords = false;
            if (isVowel(c)) {
                isIncludeVowel = true;
                if (cnt > 0)cnt++; //이전이 모음
                else cnt = 1; //이전이 자음
                if (cnt == 3)canNot3Words = false;
            } else {
                if (cnt < 0)cnt--; //이전이 자음
                else cnt = -1; //이전이 자음
                if (cnt == -3)canNot3Words = false;
            }
            old = c;
        }
        if (isIncludeVowel && canNot3Words && canNotSameWords) {
            cout<<"<"+pw+"> is acceptable.\n";
        }else cout<<"<"+pw+"> is not acceptable.\n";
    }
}