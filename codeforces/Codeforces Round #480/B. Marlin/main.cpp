#include <iostream>
#include <string>
using namespace std;
string mat[5];

void solve(int n, int k) {
    if (k % 2 == 0) {
        for (int i = 1; i <= k/2; i++) {
            mat[1][i] = '#';
            mat[2][i] = '#';
        }
        return;
    }

    if (k <= n-2) {
        int d = n-2 - k;
        d /= 2;
        for (int i = 1+d; i <= k+d; i++) {
            mat[1][i] = '#';
        }
        return;
    }

    for (int i = 1; i <= n-2; i++) {
        mat[1][i] = '#';
        k--;
    }
    mat[2][n-2] = '#';
    k--;
    for (int i = 1; i <= k; i++) {
        mat[2][i] = '#';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < 4; i++) {
        mat[i] = string(n, '.');
    }
    solve(n, k);
    cout << "YES" << endl;
    for (int i = 0; i < 4; i++) {
        cout << mat[i] << endl;
    }
    return 0;
}