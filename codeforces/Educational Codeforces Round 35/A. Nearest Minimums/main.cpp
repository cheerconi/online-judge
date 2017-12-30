#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
int nums[MAXN];
int main() {
    int n, m = 2e9;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        m = min(m, nums[i]);
    }
    int pre = -1, ret = n+1;
    for (int i = 0; i < n; i++) {
        if (nums[i] == m) {
            if (pre != -1) {
                ret = min(ret, i - pre);
            }
            pre = i;
        }
    }
    cout << ret << endl;

    return 0;
}