#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int x, int y) {
    if (x < y) return gcd(y, x);
    if (y == 0) return x;
    return gcd(y, x%y);
}
bool solve (int a, int b, int c, int d, int k) {
    if (a == c && b == d) return false;
    int x = abs(a - c);
    int y = abs(b - d);
    if (x > y) swap(x, y);
    int tmp = gcd(y, x);
    return tmp+1 == k;




}
int main() {
    int n, m, k, ret = 0;
    cin >> n >> m >> k;
    for (int a = 0; a <= n; a++) {
        for (int b = 0; b <= m; b++) {
            for (int c = 0; c <= n; c++) {
                for (int d = 0; d <= m; d++) {
                    if (solve(a, b, c, d, k)) ret++;

                }
            }
        }
    }
    cout << ret/2 << endl;

    return 0;
}