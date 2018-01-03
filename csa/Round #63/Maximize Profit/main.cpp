#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
const int MAXN = 100;
int nums[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int s, q, k;
    cin >> s >> q >> k;
    for (int i = 0; i < q; i++) {
        cin >> nums[i];
    }
    sort(nums, nums+q);
    double ret = s;
    for (int i = 0; i < q; i++) {
        if (k >  ret*nums[i]/100) {
            ret += k;
        }
        else ret += ret*nums[i]/100;
    }
    cout.setf(ios::fixed);
    cout << setprecision(10) <<  ret << endl;
    return 0;
}