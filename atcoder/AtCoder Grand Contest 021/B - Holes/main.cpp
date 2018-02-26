#include <iostream>
#include <cmath>
using namespace std;
typedef long double LD;
const int MAXN = 123;
const LD pi = acos((LD)-1);
int x[MAXN], y[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++) {
        LD a = 0, b = 4*pi;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int tmpx = x[j] - x[i];
            int tmpy = y[j] - y[i];
            LD u = -tmpy, v = tmpx;
            LD norm = sqrt(u*u + v*v);
            LD tmpa = acos(u/norm);
            if (v < 0) {
                tmpa = 2 * pi - tmpa;
            }
            LD tmp1 = max(a, tmpa), tmp2 = min(b, tmpa+pi);
            LD tmp3 = max(a,tmpa+2*pi), tmp4 = min(b, tmpa+3*pi);
            LD tmp5 = max(a+2*pi, tmpa), tmp6 = min(b+2*pi, tmpa+pi);
            if (tmp1 < tmp2) {
                a = tmp1;
                b = tmp2;
            }
            else if (tmp3 < tmp4){
                a = tmp3;
                b = tmp4;
            }
            else {
                a = tmp5;
                b = tmp6;
            }

            if (a > b) break;
            if (a > 2*pi) {
                a -= 2*pi;
                b -= 2*pi;
            }
        }
        if (b-a > 0) a = (b-a)/ (2*pi);
        else a = 0;
        printf("%.20Lf\n", a);
    }
    return 0;
}