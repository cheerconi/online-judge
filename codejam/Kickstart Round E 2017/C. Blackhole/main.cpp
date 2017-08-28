#include <iostream>
#include <algorithm>
using namespace std;

int x[3], y[3], z[3];

double solve(int a, int b, int c) {
    int x = max(a, b);
    x = max(x, c);
    int y = min(a, b);
    y = min(y, c);
    return abs(x-y) / 6.0;
}

int main() {
    freopen("test.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        for (int i = 0; i < 3; i++) {
            scanf("%d%d%d", &x[i], &y[i], &z[i]);
        }
        double ret = solve(x[0], x[1], x[2]);
        printf("Case #%d: %.10f\n", t, ret);
    }
    return 0;
}