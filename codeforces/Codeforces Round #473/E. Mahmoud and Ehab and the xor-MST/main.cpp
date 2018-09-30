#include <iostream>
using namespace std;
typedef long long LL;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LL n; cin >> n;
    LL ret = 0;
    for (int i = 0; i < 60 && n != 1; i++) {
        ret += (1LL<<i) * (n/2);
        n = (n+1) / 2;
    }
    cout << ret << endl;

    return 0;
}