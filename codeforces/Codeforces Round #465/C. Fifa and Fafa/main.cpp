#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
typedef long double LD;
LL r, a1, b1, a2, b2;
LD a, b, c;
void solve() {
    if (a1 == a2 && b1 == b2) {
        c = (LD)r / 2.0;
        a = a1;
        b = b1 + c;

        return;
    }
    if ((a1-a2)*(a1-a2)+(b1-b2)*(b1-b2) >= r*r) {
        a = a1; b = b1; c = r;
        return;
    }
    LD da = a1 - a2;
    LD db = b1 - b2;
    LD dist = sqrt(da*da + db*db);
    c = (dist + r) / 2;
    da = da / dist;
    db = db / dist;
    a = a2 + da * c;
    b = b2 + db * c;
}
int main() {
//    freopen("test.txt", "r", stdin);
    cin >> r >> a1 >> b1 >> a2 >> b2;
    solve();
    printf("%.10Lf %.10Lf %.10Lf\n", a, b, c);

    return 0;
}