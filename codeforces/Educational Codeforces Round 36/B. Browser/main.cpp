#include <iostream>
#include <algorithm>
using namespace std;
int n, pos, l, r;

int solve () {
    if (l <= pos && pos <= r) {
        if (r == n && l == 1) {
            return 0;
        }
        if (r == n) {
            return pos - l + 1;
        }
        if (l == 1) {
            return r - pos + 1;
        }
        int tmp1 = r - pos;
        int tmp2 = pos - l;
        return min(tmp1, tmp2)*2 + max(tmp1, tmp2) + 2;
    }
    if (pos < l) {
        if (r == n) {
            return l-pos + 1;
        }
        return r - pos + 2;
    }
    if (l == 1) {
        return pos - r + 1;
    }
    return pos - l + 2;
}
int main() {

    cin >> n >> pos >> l >> r;
    cout << solve() << endl;

    return 0;
}