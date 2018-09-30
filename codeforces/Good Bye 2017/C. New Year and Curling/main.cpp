#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long double LD;
const int MAXN = 1000 + 10;
LD cur[MAXN], ret[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    int n, r, val;
    scanf("%d%d", &n, &r);
    for (int i = 0; i < MAXN; i++) {
        cur[i] = -r;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &val);
        for (int j = 0; j < MAXN; j++) {
            if (abs(val-j) > 2*r) continue;
            LD tmp = 4*r*r - abs(val-j)*abs(val-j);
            tmp = sqrt(tmp) + cur[j];
            ret[i] = max(ret[i], tmp);

        }
        cur[val] = ret[i];
    }
    cout.setf(ios::fixed);


    for (int i = 1; i <= n; i++) {
        cout << setprecision(10) << ret[i];
        if (i == n) printf("\n");
        else printf(" ");
    }
    return 0;
}