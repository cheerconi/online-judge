#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

int main() {
//    freopen("test.txt", "r", stdin);
    int k, n;
    cin >> k >> n;
    int left = 1;
    int right = INT_MAX;
    int id, floor;
    int ret = -1;
    for (int i = 0; i < n; i++) {
        cin >> id >> floor;
        if (id == k) ret = floor;
        if (floor != 1) {
            right = min(right, (id-1)/(floor-1));
        }
        int tmp = id/floor;
        if (id % floor != 0) tmp++;
        left = max(left, tmp);
    }
    if (ret != -1) {
        cout << ret << endl;
        return 0;
    }
    int ret1 = k / left;
    if (k % left != 0) ret1++;
    int ret2 = k / right;
    if (k % right != 0) ret2++;
    if (ret1 == ret2) {
        cout << ret1 << endl;
    }
    else cout << -1 << endl;

    return 0;
}