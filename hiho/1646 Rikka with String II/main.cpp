#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int mod = 998244353;
string data[20];
int pw[1234], idx[20];
int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    int sumq = 0, sumc = 1;
    for (int i = 0; i < n; i++) {
        cin >> data[i];
        sumq += count(data[i].begin(), data[i].end(), '?');
        sumc += data[i].size();

    }
    pw[0] = 1;
    for (int i = 1; i <= sumq; i++) {
        pw[i] = pw[i-1] * 2 % mod;
    }
    int ret = 1LL * pw[sumq]*sumc % mod;
    for (int i = 1; i < (1<<n); i++) {
        int tot = 0;
        for (int j = 0; j < 20; j++) {
            if (i & (1<<j)) {
                idx[tot++] = j;
            }
        }
        if (tot <= 1) continue;
        int m = 10000;
        for (int j = 0; j < tot; j++) m = min(m, (int)data[idx[j]].size());
        int cur = sumq;
        for (int j = 0; j < m; j++) {
            int zero = 0, one = 0, two = 0;
            for (int k = 0; k < tot; k++) {
                if (data[idx[k]][j] == '0') {
                    zero++;
                }
                else if (data[idx[k]][j] == '1') {
                    one++;
                }
                else if (data[idx[k]][j] == '?') {
                    two++;

                }
            }
            if (zero && one) break;
            cur -= two;
            int tmp;
            if (!zero && !one) cur++;
            tmp = pw[cur];
            if (tot % 2 == 0) tmp = mod - tmp;
            ret = (ret + tmp) % mod;
        }
    }
    cout << ret << endl;

    return 0;
}