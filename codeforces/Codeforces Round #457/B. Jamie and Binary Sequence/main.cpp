#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
LL cnt[200], base = 100, tot, i;
bool solve(LL n, LL k) {
    for (; (1LL<<i) <= n; i++) {
        if ((1LL<<i) & n) {
            cnt[i+base]++;
            tot++;
        }
    }
    if (tot > k) return false;
    i--;
    while (true) {
        if (cnt[i+base]+tot <= k) {
            cnt[i-1+base] += cnt[i+base]*2LL;
            tot += cnt[i+base];
            cnt[i+base] = 0;
            i--;
        }
        else break;
    }
    i = 0;
    while (true) {
        if (cnt[i] != 0) break;
        i++;
    }
    tot = k - tot;
    if (tot > 0) cnt[i]--;
    return true;

}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LL n, k;
    cin >> n >> k;
    if (!solve (n, k)) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
        int j = 199;
        while (cnt[j] != 0) j--;
        while (k > 0 && j >= 0) {
            for (int t = 0; t < cnt[j]; t++) {
                cout << j-base;
                k--;
                if (k == 0) cout << endl;
                else cout << ' ';
            }
            j--;
        }
        i--;
        if (k > 0) {
            while (k > 2) {
                cout << i-base << ' ';
                k--;
                i--;
            }
            cout << i-base << ' ' << i-base << endl;
        }

    }
    return 0;
}