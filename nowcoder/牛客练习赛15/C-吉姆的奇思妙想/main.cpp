#include <iostream>
#include <climits>
using namespace std;
typedef long long LL;
const int MAXN = 2e5 + 10;
LL deg[MAXN], freq[MAXN];
__int128 pre[MAXN], rear[MAXN];
LL a, b, m;
int lft, rght;
void solve () {
    if (lft == rght) return;
    __int128 val1 = (__int128)b * m * rear[lft];
    if (lft != 0) val1 += a * pre[lft-1];
    __int128 val4 = (__int128)b * m * rear[rght] + a * pre[rght-1];
    if (lft+1 == rght) {
        if (val1 > val4) lft = rght;
        else rght = lft;
        return;
    }
    int x = lft + (rght-lft+1) / 3;
    __int128 val2 = (__int128)b * m * rear[x] + a * pre[x-1];

    if (lft+2 == rght) {
        if (val1 <= val2 && val1 <= val4) {
            rght = lft;
        }
        else if (val2 <= val1 && val2 <= val4) {
            lft++; rght--;
        }
        else {
            lft = rght;
        }
        return;
    }
    int y = rght - (rght-lft + 1) / 3;
    __int128 val3 = (__int128)b * m * rear[y] + a * pre[y-1];
    if (val1 < val2) {
        rght = x;
    }
    else {
        if (val3 > val2) {
            rght = y;
        }
        else {
            lft = x;
        }

    }
    solve ();
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LL n;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> deg[i] >> freq[i];
    }
    for (int i = n-1; i >= 0; i--) {
        rear[i] = rear[i+1] + freq[i];
    }
    pre[0] = (__int128)deg[0] * deg[0] * freq[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i-1] + (__int128)deg[i] * deg[i] * freq[i];
        if (pre[i] <= 0 || pre[i] > LLONG_MAX) {
            n = i;
            break;
        }
    }
    int q; cin >> q;
    while (q--) {
        cin >> a >> b;
        lft = 0, rght = n;
        solve();
        LL ret =  b * m * rear[lft];
        if (lft != 0) ret += a * pre[lft-1];
        cout << ret << '\n';
    }

    return 0;
}