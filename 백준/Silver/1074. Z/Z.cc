//
// Created by Lee SeungJun on 12/20/23.
//

#include<iostream>
#include<cmath>

using namespace std;

int main() {
    long long n, c, r;
    cin >> n >> r >> c;
    long long ans = 0;
    long long val = pow(2, n * 2);

    for (int i = n; i > 0; i--) {
        val /= 4;
        long long tmp_c = c / pow(2, i - 1);
        long long tmp_r = r / pow(2, i - 1);
        ans += (tmp_r * 2 + tmp_c) * val;

        c = c % static_cast<int>(pow(2, i - 1));
        r = r % static_cast<int>(pow(2, i - 1));
    }
    cout<<ans;
}