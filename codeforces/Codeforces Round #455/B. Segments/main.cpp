#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 123;
int nums[MAXN];
int main() {
    int n, ret = 0;
    cin >> n;
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i+len <= n; i++) {
            for (int k = i; k < i+len; k++) {
                nums[k]++;
                ret = max(nums[k], ret);
            }
        }
    }
    cout << ret << endl;

    return 0;
}