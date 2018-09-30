#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 2000 + 10;
int cnt[MAXN][MAXN], n;
void update(int x1, int x2, int y1, int y2) {
    while (x2 <= 0) {
        x2 += n; x1 += n;
    }
    while (y2 <= 0) {
        y2 += n; y1 += n;
    }
    if (x1 < 0) {
        update(0, x2, y1, y2);
        update(n+x1, n, y1, y2);
        return;
    }
    if (y1 < 0) {
        update(x1, x2, 0, y2);
        update(x1, x2, n+y1, n);
        return;
    }
    cnt[x1][y1]++; cnt[x1][y2]--; cnt[x2][y1]--; cnt[x2][y2]++;

    return;
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q; cin >> q;
    int k; cin >> k;
    n = 2 * k;
    int x, y;
    char c;
    while (q--) {
        cin >> x >> y >> c;
        x = x % n;
        y = y % n;
        if (c == 'W') {
            update(-x, k - x, k - y, n - y);
            update(k - x, n - x, -y, k - y);
        } else {
            update(-x, k - x, -y, k - y);
            update(k - x, n - x, k - y, n - y);
        }

    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            cnt[i][j] += cnt[i][j - 1];
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i = 1; i < n; i++) {
            cnt[i][j] += cnt[i - 1][j];
        }
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ret = max(ret, cnt[i][j]);
        }
    }
    cout << ret << endl;
    return 0;
}