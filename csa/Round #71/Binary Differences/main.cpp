#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
int a[MAXN], b[MAXN], nums[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    for (int i = 1; i <= n; i++) {
        if (nums[i] == 1) {
            a[i] = a[i-1] - 1;
            b[i] = b[i-1] - 1;
            a[i] = min(a[i], -1);
            b[i] = max(b[i], 0);

        }
        else {
            a[i] = a[i-1] + 1;
            b[i] = b[i-1] + 1;
            a[i] = min(a[i], 0);
            b[i] = max(b[i], 1);
        }
    }
    int left = INT_MAX, right = INT_MIN;
    for (int i = 1; i <= n; i++) {
        left = min(left, a[i]);
        right = max(right, b[i]);
    }
    cout << right-left+1 << endl;
    return 0;
}