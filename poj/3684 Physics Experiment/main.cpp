#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
const int MAXN = 123;
double nums[MAXN];


int main() {
//    freopen("test.txt", "r", stdin);
    int c;
    cin >> c;
    while (c--) {
        int n, h, r, t;
        cin >> n >> h >> r >> t;
        double t0 = sqrt(h/5.0);
        for (int i = 0; i < n; i++) {

            double t1 = t - i;
            if (t1 <= 0) {
                nums[i] = h;
                continue;
            }
            int cnt = t1 / t0;
            t1 = t1 - cnt*t0;

            if (cnt % 2 == 0) {
                double tmp = 5 * t1 * t1;
                nums[i] = h - tmp;
            }
            else {
                double tmp = h - (t0-t1)*(t0-t1)*5;
                nums[i] = tmp;
            }
        }
        sort(nums, nums + n);
        for (int i = 0; i < n; i++) {
            printf("%.2f", nums[i] + r*i/50.0);
            if (i == n-1) printf("\n");
            else printf(" ");
        }

    }
    return 0;
}