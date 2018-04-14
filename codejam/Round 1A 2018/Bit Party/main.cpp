#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 1000 + 10;
LL m[MAXN], s[MAXN], p[MAXN];
LL r, b, c;
bool check (LL bound) {
    priority_queue<LL, vector<LL>, greater<LL> > pq;
    LL tmp, cur = 0;
    for (int i = 0; i < c && cur < b; i++) {
        tmp = bound - p[i];
        if (tmp <= 0) continue;
        tmp = tmp / s[i];
        tmp = min(tmp, m[i]);
        if (pq.size() < r) {
            cur += tmp;
            pq.push(tmp);
            continue;
        }
        LL val = pq.top();
        if (val >= tmp) continue;
        pq.pop(); pq.push(tmp);
        cur = cur - val + tmp;
    }
    if (cur >= b) return true;
    return false;
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int cs; cin >> cs;
    for (int k = 1; k <= cs; k++) {
        cin >> r >> b >> c;
        for (int i = 0; i < c; i++) {
            cin >> m[i] >> s[i] >> p[i];
        }
        LL lft = 1, rght = 2e18;
        while (lft < rght) {
            LL mid = (lft+rght) >> 1;
            if (check(mid)) rght = mid;
            else lft = mid+1;
        }
        cout << "Case #" << k << ": " << lft << '\n';

    }
    return 0;
}