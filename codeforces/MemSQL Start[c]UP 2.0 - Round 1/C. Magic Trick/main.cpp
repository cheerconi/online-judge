#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    cout.setf(ios::fixed);
    LL a = m*n - 1 + (n-1)*(m-1);
    LL b = n * (m*n - 1);
    long double ret;
    if (b != 0) {
        ret = (long double) a / b;
    }
    else ret = 1;
    cout << setprecision(15) << ret << endl;
    return 0;
}