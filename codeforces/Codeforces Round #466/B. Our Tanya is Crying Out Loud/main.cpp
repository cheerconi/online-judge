#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
int main() {
    LL n, k, a, b;
    cin >> n >> k >> a >> b;
    if (k == 1) {
        cout << (n-1)*a << endl;
        return 0;
    }
    LL ret = 0;
    while (n > 1) {
        if (n < k) {
            ret += (n-1)*a;
            n = 1;
        }
        else {
            if (n % k == 0) {
                ret += min((n-n/k)*a, b);
                n /= k;
            }
            else {
                ret += (n%k) * a;
                n = n / k * k;
            }
        }
    }
    cout << ret << endl;
    return 0;
}