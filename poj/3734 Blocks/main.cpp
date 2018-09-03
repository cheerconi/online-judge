#include <iostream>
using namespace std;
const int mod = 10007;
struct Matrix{
    int data[3][3];
    Matrix () {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                data[i][j] = 0;
            }
        }
    }
    Matrix operator* (const Matrix & other) const {
        Matrix ret;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    ret.data[i][j] = (data[i][k]*other.data[k][j] + ret.data[i][j]) % mod;
                }
            }
        }
        return ret;
    }
};
int solve (int n) {
    Matrix m, ret;
    m.data[0][0] = 2, m.data[0][1] = 1, m.data[0][2] = 0;
    m.data[1][0] = 2, m.data[1][1] = 2, m.data[1][2] = 2;
    m.data[2][0] = 0, m.data[2][1] = 1, m.data[2][2] = 2;
    ret.data[0][0] = ret.data[1][1] = ret.data[2][2] = 1;
    while (n) {
        if (n & 1) ret = m * ret;
        m = m * m;
        n >>= 1;
    }
    return ret.data[0][0];
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}