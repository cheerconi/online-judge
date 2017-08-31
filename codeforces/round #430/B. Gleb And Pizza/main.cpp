#include <iostream>
#include <math.h>
using namespace std;
const double eps = 1e-6;
int r, d;
int x, y, rad;

bool solve () {
    if (d == 0 && rad == 0) {
        return x*x+y*y == r*r;
    }
    if (d == 0) return false;
    double tmp = sqrt(x*x+y*y + 0.0);
    double high = tmp+rad;
    if (fabs(high-r) > eps && high > r) return false;
    double low = tmp - rad;
    if (fabs(low) <= eps || low < 0) return false;
    if (fabs(r-d-low) > eps && r-d > low) return false;
    return true;

}

int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d%d", &r, &d);
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &x, &y, &rad);
        if (solve()) cnt++;
    }
    cout << cnt << endl;
    return 0;
}