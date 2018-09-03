#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1234;
int nums[MAXN];
int main() {
    int n, q, val;
    cin >> n >> q;
    while (q--) {
        cin >> val;
        nums[val]++;
    }
    int ret = 1234;
    for (int i = 1; i <= n; i++) {
        ret = min(ret, nums[i]);
    }
    cout << ret << endl;

    return 0;
}