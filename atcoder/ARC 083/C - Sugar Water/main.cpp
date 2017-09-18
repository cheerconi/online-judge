#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int a, b, c, d, e, f;
const double eps = 1e-6;
const int MAXN = 3000 + 10;
bool water[MAXN];
bool sugar[MAXN];

double solve(int water, int suger) {
}
int main() {
//    freopen("test.txt", "r", stdin);
    cin >> a >> b >> c >> d >> e >> f;
    water[0] = true;
    sugar[0] = true;
    for (int i = 0; i <= f; i++) {
        if (water[i]) {
            if (i+100*a <= f) water[i+100*a] = true;
            if (i+100*b <= f) water[i+100*b] = true;
        }
        if (sugar[i]) {
            if (i+c <= f) sugar[i+c] = true;
            if (i+d <= f) sugar[i+d] = true;
        }
    }
    double rate = -1;
    int ret[2];
    for (int i = 100; i <= f; i += 100) {
        if (!water[i]) continue;
        int tmp = f - i;
        double tmp1 = (double)e / 100.0 * i;
        tmp = min(tmp, (int)tmp1);
        for (int j = tmp; j >= 0; j--) {
            if (sugar[j]) {
                if ((double)j/i > rate) {
                    rate = (double)j / i;
                    ret[0] = i;
                    ret[1] = j;
                }
                break;
            }
        }
    }
    cout << ret[0]+ret[1] << ' ' << ret[1] << endl;
    return 0;
}