#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i=1;i<=sqrt(yellow);i++){
        if(yellow % i != 0)continue;
        int col = i+2; int row = yellow / i + 2;
        int c_brown = row * 2 + (col - 2) * 2;
        cout<<row<<",    "<<col<<",     "<<c_brown<<'\n';
        if(c_brown == brown){
            answer.push_back(row);
            answer.push_back(col);
            break;
        }
    }
    return answer;
}