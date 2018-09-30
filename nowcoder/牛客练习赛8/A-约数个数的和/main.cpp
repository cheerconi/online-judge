#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
int bound = 1e6;
int main() {
    int n;
    LL ret = 0, i = 1;
    cin >> n;
    for (; i <= min(bound, n); i++) {
        ret += n / i;
    }
    while (i <= n) {
        LL j = n / (n / i);
        j = min(j, (LL)n);
        ret += (n/i)*(j-i + 1);
        i = j + 1;
    }
    cout << ret << endl;
    return 0;
}