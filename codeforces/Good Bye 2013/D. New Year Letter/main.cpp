#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long LL;
int x;

bool solve (LL i, LL j, int state, int k) {
    if (k == 0) return j == x;
    LL tmp = i + j;
    int d = state % 3; state /= 3;
    int c = state % 3; state /= 3;
    int b = state % 3; state /= 3;
    int a = state;
    if (b == 0 && c == 2) tmp++;
    if (tmp > x) return false;
    int val = c*3 + d;
    val *= 9;
    val += a*3 + d;
    return solve(j, tmp, val, k-1);
}

int main() {
//    freopen("test.txt", "r", stdin);
    int k, n, m;
    cin >> k >> x >> n >> m;
    for (int state = 0; state < 81; state++) {
        int tmp = state;
        int d = tmp % 3; tmp /= 3;
        int c = tmp % 3; tmp /= 3;
        int b = tmp % 3; tmp /= 3;
        int a = tmp;
        if (n == 1 && a != b) continue;
        if (m == 1 && c != d) continue;
        int nn = n;
        if (a != 0) nn--;
        if (nn % 2 == 0 && b != 2) nn--;
        int mm = m;
        if (c != 0) mm--;
        if (mm % 2 == 0 && d != 2) mm--;
        nn /= 2; mm /= 2;
        for (int i = 0; i <= nn; i++) {
            if (a == 0 && b == 2 && n == 2 && i == 0) continue;
            for (int j = 0; j <= mm; j++) {
                if (c == 0 && d == 2 && m == 2 && j == 0) continue;
                if (solve(i, j, state, k-2)) {
                    string x(n, 'B'), y(m, 'B');
                    x[0] = 'A' + a; x[n-1] = 'A' + b;
                    y[0] = 'A' + c; y[m-1] = 'A' + d;
                    int idx = 0;
                    if (x[0] != 'A') idx++;
                    while (i > 0) {
                        x[idx] = 'A'; x[idx+1] = 'C';
                        idx += 2; i--;
                    }
                    idx = 0;
                    if (y[0] != 'A') idx++;
                    while (j > 0) {
                        y[idx] = 'A'; y[idx+1] = 'C';
                        idx += 2; j--;
                    }
                    cout << x << endl << y << endl;
                    return 0;
                }


            }
        }

    }
    cout << "Happy new year!" << endl;
    return 0;
}