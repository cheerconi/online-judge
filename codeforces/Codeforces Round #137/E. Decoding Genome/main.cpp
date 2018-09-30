#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
const int mod = 1e9 + 7;
int m;
struct Matrix{
    vector<vi> data;
    Matrix () {
        data = vector<vi>(m, vi(m, 0));
    }
    void set_one() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                data[i][j] = 1;
            }
        }
    }
    void set_unit() {
        data = vector<vi>(m, vi(m, 0));
        for (int i = 0; i < m; i++) {
            data[i][i] = 1;
        }
    }
    Matrix operator*(const Matrix & oth) const {
        Matrix ret;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < m; k++) {
                    ret.data[i][j] = (ret.data[i][j] + 1LL * data[i][k] * oth.data[k][j] % mod) % mod;
                }
            }
        }
        return ret;
    }
    int sum() {
        int ret = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                ret = (ret + data[i][j]) % mod;
            }
        }
        return ret;
    }
};
Matrix power(LL n, Matrix base) {
    Matrix ret; ret.set_unit();
    while (n) {
        if (n & 1) ret = ret * base;
        base = base * base;
        n >>= 1;
    }
    return ret;
}
int convert(char c) {
    int ret;
    if (c >= 'a' && c <= 'z') ret = c - 'a';
    else ret = c - 'A' + 26;
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LL n, k;
    cin >> n >> m >> k;
    Matrix base; base.set_one();
    string s;
    for (int i = 0; i < k; i++) {
        cin >> s;
        base.data[convert(s[0])][convert(s[1])] = 0;
    }
    Matrix ret = power(n-1, base);
    cout << ret.sum() << endl;

    return 0;
}