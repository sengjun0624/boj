#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int cnt = 0;
        string singer, fan;
        cin >> singer >> fan;
        int len=fan.length();
        for (int i = 0; i < len; i++) {
            bool is = true;
            for (int j = 0; j < singer.length(); j++) {
                if (singer[j] == 'M' && fan[j] == 'M') {
                    is = false;
                    break;
                }
            }
            if (is)cnt++;
            if (fan.length()==singer.length())break;
            fan = fan.substr(1);
        }
        cout << cnt << "\n";
    }
}
