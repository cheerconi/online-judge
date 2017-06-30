#include <iostream>
#include <algorithm>
#include <memory.h>

typedef long long LL;
using namespace std;

static const int MAXH = 15 + 1;
static const int MOD = 1000000007;


struct M{
    LL matrix[MAXH][MAXH];
    M(){
        memset(matrix, 0, sizeof(matrix));
    }
    M(int diag) {
        memset(matrix, 0, sizeof(matrix));
        for (int i = 0; i < MAXH; i++) matrix[i][i] = diag;
    }

    M operator* (M const & other) const {
        M ret = M();
        for (int i = 0; i < MAXH; i++) {
            for (int j = 0; j < MAXH; j++) {
                LL tmp = 0;
                for (int k = 0; k < MAXH; k++) {
                    tmp += matrix[i][k] * other.matrix[k][j];
                    if (tmp >= MOD) tmp %= MOD;
                }
                ret.matrix[i][j] = tmp;
            }
        }
        return ret;
    }
    M power(LL n) const {
        M ret = M(1);
        M cur = *this;
        while (n) {
            if (n & 1) ret = ret*cur;
            n = n >> 1;
            cur = cur*cur;
        }
        return ret;
    }
    void print() const {
        for (int i = 0; i < MAXH; i++) {
            for (int j = 0; j < MAXH; j++) {
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
};




int main() {
//    freopen("test.txt", "r", stdin);
    M dp = M();
    dp.matrix[0][0] = 1;
    int n, c;
    LL k, a, b;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        M trans = M();
        for (int i = 0; i <= c; i++) {
            if (i - 1 >= 0) trans.matrix[i-1][i] = 1;
            if (i + 1 <= c) trans.matrix[i+1][i] = 1;
            trans.matrix[i][i] = 1;
        }
        b = min(b, k);
        trans = trans.power(b-a);
        dp = dp * trans;
    }
    cout << dp.matrix[0][0] << endl;



    return 0;
}