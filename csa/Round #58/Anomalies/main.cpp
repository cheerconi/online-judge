#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 123;
int nums[MAXN];
int main() {
    int n, k;
    cin >> n >> k;
    int ret = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (abs(nums[i]-nums[j]) <= k) {
                flag = false;
                break;
            }
        }
        if (flag) ret++;
    }
    cout << ret << endl;
    return 0;
}