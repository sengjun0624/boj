#include<iostream>
#include<stack>
#include<algorithm>
#include<string>

using namespace std;
int testCase;
string str,bomb;



stack<char>Stack;
int main() {
	cin >> str >> bomb;
	int length = bomb.length();

	for (char c : str) {
		Stack.push(c);
		if (c == bomb[length - 1] && Stack.size() >= length) {
			//폭탄 문자열의 마지막 문자일 때
			string Compare;

			for (int i = 0; i < length; i++) {
				// 폭탄 문자열의 길이만큼 임시 문자열에 저장
				Compare.push_back(Stack.top());
				Stack.pop();
			}
		
			reverse(Compare.begin(), Compare.end());
			
			if (Compare.compare(bomb)!=0) {
				//폭탄 문자열과 임시 문자열 비교 실패시 다시 Stack에 넣음.
				for (char temp : Compare) {

					Stack.push(temp);
				}
			}
		}
	}
	string outPut;
	while (!Stack.empty()) {

		outPut.push_back(Stack.top());
		Stack.pop();
	}

	reverse(outPut.begin(), outPut.end());
	if (outPut.empty()) {
		outPut+="FRULA"; 
	}
	for (char word : outPut) {

		cout << word;
	}
	//cout << "\n";

}
