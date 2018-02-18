#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
vector<LL> nums, sum;
double solve() {
    if (nums.size() == 1) return 0;
    int left = 0, right = nums.size() - 2;
    while (left < right) {
        int mid = (left+right) >> 1;
        double val1 = (nums.back() + sum[mid]) / (2.0 + mid);
        double val2 = (nums.back() + sum[mid+1]) / (3.0 + mid);
        if (val1 >= val2) left = mid + 1;
        else right = mid;
    }
    return nums.back() - (nums.back() + sum[left]) / (2.0 + left);
}
int main() {
//    freopen("test.txt", "r", stdin);
    int q; cin >> q;
    int cmd, val;
    while (q--) {
        scanf("%d", &cmd);
        if (cmd == 1) {
            scanf("%d", &val);
            nums.push_back(val);
            sum.push_back(val);
            if (sum.size() >= 2) {
                sum.back() += sum[sum.size()-2];
            }
        }
        else {
            printf("%.10f\n", solve());

        }

    }
    return 0;
}