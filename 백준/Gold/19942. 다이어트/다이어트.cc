#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

const int MAX = 15;
int arr[MAX][5];
bool isSelected[MAX];
int n, k;
int Min = 987654321;
int standard[4] = {0, 0, 0, 0};
bool ans[15];

bool satisfy(int (&tmp)[5]) {
    for (int i = 0; i < 4; i++) {
        if (tmp[i] < standard[i])return false;
    }
    return true;
}

bool comp(vector<int> &v1 ,vector<int> &v2) {
    int len1 = v1.size();
    int len2 = v2.size();
    int minLength = min(len1, len2);

    // 원소 하나하나 비교
    for (int i = 0; i < minLength; i++) {
        if (v1[i] < v2[i]) {
            return true;  // v1이 더 작다
        } else if (v1[i] > v2[i]) {
            return false; // v2가 더 작다
        }
    }

    // 만약 지금까지 차이가 없다면, 더 짧은 벡터가 더 작다
    return len1 < len2;}

void makeCombination(int idx, int len) {
    if (len == k) {
        int tmp[5] = {0, 0, 0, 0, 0};
        //선택된 영양소를 더해줌
        for (int i = 0; i < n; i++) {
            if (isSelected[i]) {
                for (int j = 0; j < 5; j++) {
                    tmp[j] += arr[i][j];
                }
            }
        }

        // 조건을 만족하는지 체크함
        if (satisfy(tmp)) {
            //최소비용인지 체크
            if (Min > tmp[4]) {
                //최소비용 갱신
                Min = tmp[4];
                memset(ans, false, sizeof(ans));
                for (int i = 0; i < n; i++) {
                    if (isSelected[i])ans[i] = true;
                }
            } else if (Min == tmp[4]) {
                vector<int> original, rival;
                for (int i = 0; i < n; i++) {

                    if (isSelected[i]) {
                        rival.push_back(i);
                    }
                    if (ans[i])original.push_back(i);
                }
                if (!comp(original, rival)) {
                    memset(ans, false, sizeof(ans));
                    for (int idx: rival)ans[idx] = true;
                }

            }

        }
        return;
    }
    for (; idx < n; idx++) {
        isSelected[idx] = true;
        makeCombination(idx + 1, len + 1);
        isSelected[idx] = false;
    }
}

int main() {
    memset(ans, false, sizeof(ans));
    cin >> n;
    for (int i = 0; i < 4; i++)cin >> standard[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        k = i;
        makeCombination(0, 0);
    }
    if (Min == 987654321)cout << -1;
    else {
        cout << Min << "\n";
        for (int i = 0; i < n; i++) {
            if (ans[i]) {
                cout << i + 1 << " ";
            }
        }
    }
}