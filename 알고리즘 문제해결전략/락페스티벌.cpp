//
// Created by Lee SeungJun on 5/17/24.
//
#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;


const int Max = 1001;

int arr[Max];
int t, n, l;

double two_pointer() {
    double min = 999999999;
    for (double size = l; size <= n; size++) {
        int st = 1; int ed = 1; int len = 1; double sum = arr[st];

        for (st; st <= n; st++) {

            while (ed < n && len < size) {
                ed++;
                len++;
                sum += arr[ed];
            }
            if (len == size) {
                if (min > sum / size ){
                  
                    min = sum / size;
                }
            }
            len--;
            sum -= arr[st];
        }
    }
    return min;
}

int main() {

    cin >> t;
    while (t--) {
        memset(arr,0,sizeof(arr));
        cin >> n >> l;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        cout<<fixed<<setprecision(10)<<two_pointer()<<"\n";
    }

}
