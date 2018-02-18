#include <iostream>
using namespace std;
typedef long long LL;
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LL n, k, a = 0, b = 0, c = 0, val;
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> val;
        LL num = n / val * val;
        if (num > b*c) {
            a = i;
            b = n / val;
            c = val;
        }
    }
    if (a == 0) a = 1;
    cout << a << ' ' << b << endl;

    return 0;
}