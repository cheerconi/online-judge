#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
LL mod;
struct Matrix{
    vector<vector<LL> > data;
    Matrix () {
        data = vector<vector<LL> >(4, vector<LL>(4, 0));
    }
    Matrix operator* (const Matrix & other) const {
        Matrix ret;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    ret.data[i][j] = (ret.data[i][j] + data[i][k]*other.data[k][j] % mod) % mod;
                }
            }
        }
        return ret;
    }
};
Matrix power (Matrix  m, LL p) {
    Matrix ret;
    for (int i = 0; i < 4; i++) ret.data[i][i] = 1;
    while (p) {
        if (p&1) ret = ret * m;
        m = m * m;
        p >>= 1;
    }
    return ret;
}
int main() {
//    freopen("test.txt", "r", stdin);
    LL n, k, l;
    cin >> n >> k >> l >> mod;
    if (l == 0) {
        if (k == 0) cout << 1%mod << endl;
        else cout << 0 << endl;
        return 0;
    }
    if (l < 63 && (1LL<<l) <= k) {
        cout << 0 << endl;
        return 0;
    }
    Matrix m;
    m.data[0] = {1, 1, 0, 0};
    m.data[1] = {1, 0, 0, 0};
    m.data[2] = {0, 0, 1, 1};
    m.data[3] = {0, 1, 1, 1};
    Matrix ret = power(m, n-2);
    LL dp0= 2*ret.data[0][0] + ret.data[0][1] + ret.data[0][3];
    dp0 += 2*ret.data[1][0] + ret.data[1][1] + ret.data[1][3];
    dp0 = dp0 % mod;
    LL dp1 = 2*ret.data[2][0] + ret.data[2][1] + ret.data[2][3];
    dp1 += 2*ret.data[3][0] + ret.data[3][1] + ret.data[3][3];
    dp1 = dp1 % mod;
    LL cnt = 1;
    for (int i = 0; i < min(63LL, l); i++) {
        if ((1LL<<i) & k) cnt = cnt * dp1 % mod;
        else cnt = cnt * dp0 % mod;
    }
    if (l == 64) cnt = cnt * dp0 % mod;
    cout << cnt << endl;
    return 0;
}