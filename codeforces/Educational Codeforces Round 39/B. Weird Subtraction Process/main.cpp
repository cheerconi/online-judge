#include <iostream>
using namespace std;
typedef long long LL;
LL a, b;

void solve () {
    if (a == 0 || b == 0) return;
    if (a < 2*b && b < 2*a) return;
    if (a >= 2*b) a -= a / (2*b) * (2*b);
    else b -= b / (2*a) * (2*a);
    solve();
}

int main() {
    cin >> a >> b;
    solve();
    cout << a << ' ' << b << endl;
    return 0;
}