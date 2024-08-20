/*
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

*/
/*
 * 카라츠바= (a1*10^128 + a0) * (b1 * 10^128 + b0)
 * a1, a0 ,b1 ,b0 하프로 나누고 합칠때 (a0+a1)*(b0+b1)= a0b0 + a0b1+a1b0 +a1b1
 *                                                 z0        z0         z2
 *//*

vector<int> multiply(const vector<int> &a, const vector<int> &b) {
    vector<int> c(a.size() + b.size() + 1, 0);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            c[i + j] += (a[i] * b[j]);
    return c;
}

vector<int> karatuba(vector<int> &a, vector<int> &b) {
    int an = a.size(), bn = b.size();
    if (an < bn) return karatuba(b, a);
    if (an == 0 || bn == 0)return vector<int>{};
    if (an <= 50) return multiply(a, b);

    int half = an / 2;

    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(bn, half));
    vector<int> b1(b.begin() + min<int>(bn, half), b.end());

    vector<int> z2 = karatuba(a1, b1);
    vector<int> z0 = karatuba(a0, b0);

    vector<int> a1_plus_a0 = a1;
    vector<int> b1_plus_b0 = b1;

    for (int i = 0; i < a1.size(); i++) a1_plus_a0[i] += a0[i];
    for (int i = 0; i < b1.size(); i++) b1_plus_b0[i] += b0[i];

    vector<int> z1 = karatuba(a1_plus_a0, b1_plus_b0);

    vector<int> ret(z2.size() + 2 * an);

    //combine
    for (int i = 0; i < z0.size(); i++)ret[i] += z0[i];
    for (int i = 0; i < z1.size(); i++)ret[i + half] += z1[i] - z2[i] - z0[i];
    for (int i = 0; i < z2.size(); i++)ret[i + 2 * half] += z2[i];

    return ret;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string singer, fan;
        cin >> singer >> fan;
        int N = singer.length();
        int M = fan.length();
        vector<int> members(N), fans(M);
        for (int i = 0; i < N; i++) members[i] = (singer[i] == 'M');
        for (int i = 0; i < M; i++)fans[M - i - 1] = (fan[i] == 'M');
        vector<int> C = karatuba(members, fans);
        int ans = 0;
        for (int i = N - 1; i < M; i++) if (C[i] == 0)ans++;
        cout << ans << "\n";
    }
}
*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
 * 카라츠바= (a1*10^128 + a0) * (b1 * 10^128 + b0)
 * a1, a0 ,b1 ,b0 하프로 나누고 합칠때 (a0+a1)*(b0+b1)= a0b0 + a0b1+a1b0 +a1b1
 *                                                 z0        z0         z2
 */
vector<int> multiply(const vector<int> &a, const vector<int> &b) {
    vector<int> c(a.size() + b.size() + 1, 0);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            c[i + j] += (a[i] * b[j]);
    return c;
}
//a += b*(10^k)
void addTo(vector<int> &a, const vector<int> &b, int k){
    a.resize(max(a.size(), b.size() + k));
    for (int i = 0; i < b.size(); i++)
        a[i + k] += b[i];
}

//a -= b
void subFrom(vector<int> &a, const vector<int> &b){
    a.resize(max(a.size(), b.size()) + 1);
    for (int i = 0; i < b.size(); i++)
        a[i] -= b[i];
}

vector<int> karatsuba(vector<int> &a, vector<int> &b) {
    int an = a.size(), bn = b.size();
    if (an < bn) return karatsuba(b, a);
    if (an == 0 || bn == 0)return vector<int>{};
    if (an <= 50) return multiply(a, b);

    int half = an / 2;

    vector<int> a0 (a.begin(), a.begin() + half);
    vector<int> a1 (a.begin() + half, a.end());


    vector<int> b0(b.begin(), b.begin() + min<int>(bn, half));
    vector<int> b1(b.begin() + min<int>(bn, half), b.end());

    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);

    addTo(a0, a1, 0);
    addTo(b0, b1, 0);

    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    vector<int> res;
    addTo(res, z0, 0);
    addTo(res, z1, half);
    addTo(res, z2, half * 2);

    return res;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string singer, fan;
        cin >> singer >> fan;
        int N = singer.length();
        int M = fan.length();
        vector<int> members(N), fans(M);

        for (int i = 0; i < N; i++) members[i] = (singer[i] == 'M');
        for (int i = 0; i < M; i++)fans[M - i - 1] = (fan[i] == 'M');

        vector<int> C = karatsuba(members, fans);
        int ans = 0;
        for (int i = N - 1; i < M; i++) if (C[i] == 0)ans++;
        cout << ans << "\n";
    }
}
