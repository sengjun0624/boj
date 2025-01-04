#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int MAX,MIN;
int solution(vector<vector<int>> sizes) {
    for(auto v:sizes){
        int row = max(v[0],v[1]);
        int col = min(v[0],v[1]);
        MAX = max(MAX,row);
        MIN = max(MIN,col);
    }
    return MAX*MIN;
}
//큰거 한쪽에 몰고 작은거 다른쪽에 몰아서 하면될것같은데