#include <iostream>
using namespace std;
typedef long long LL;
int main() {
    LL n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << n << endl;
        return 0;
    }
    int a = 62;
    while (true) {
        if ((1LL<<a) & n) break;
        a--;
    }
    LL ret = 0;
    while (a >= 0) {
        ret += 1LL<<a;
        a--;
    }
    cout << ret << endl;
    return 0;
}