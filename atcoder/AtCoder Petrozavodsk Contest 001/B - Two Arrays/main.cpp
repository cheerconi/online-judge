#include <iostream>
using namespace std;
typedef long long LL;
const int MAXN = 10000 + 10;
int a[MAXN];
int main() {
    LL cnt1 = 0, cnt2 = 0;
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> val;
        if (val > a[i]) {
            cnt1 += (val - a[i]) / 2;
        }
        else if (val < a[i]) {
            cnt2 += a[i] - val;
        }
    }
    if (cnt1 >= cnt2) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}