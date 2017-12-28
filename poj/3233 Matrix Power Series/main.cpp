#include <iostream>
#include <vector>
using namespace std;
int mod, n;
struct Matrix{
    vector<vector<int> > data;
    Matrix () {
        data = vector<vector<int> >(n, vector<int>(n, 0));
    }
    Matrix (int val){
        data = vector<vector<int> >(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) data[i][i] = val;
    }
    Matrix operator* (const Matrix & oth) const {
        Matrix ret;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    ret.data[i][j] = (oth.data[i][k] * data[k][j] + ret.data[i][j]) % mod;
                }
            }
        }
        return ret;
    }
    Matrix operator+ (const Matrix & oth) const {
        Matrix ret;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ret.data[i][j] = (oth.data[i][j] + data[i][j]) % mod;
            }
        }
        return ret;
    }
};
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int k; cin >> n >> k >> mod;
    Matrix A, ret, ones(1);
    vector<Matrix> nums(40, Matrix()), sum(40, Matrix());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A.data[i][j];
        }
    }
    int m = k, p = 1;
    sum[0] = nums[0] = A;
    while (m) {
        nums[p] = nums[p-1]*nums[p-1];
        sum[p] = nums[p-1]*sum[p-1] + sum[p-1];
        m >>= 1;
        p++;
    }
    for (int j = 30; j >= 0; j--) {
        if (k & (1<<j)) {
            ret = ret + sum[j] * ones;
            ones =  nums[j] * ones;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ret.data[i][j];
            if (j+1 != n) cout << ' ';
        }
        cout << endl;
    }

    return 0;
}