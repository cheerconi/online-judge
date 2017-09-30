#include <iostream>
using namespace std;
typedef long long LL;

LL i, j, k;

void solve(LL n) {
    for (i = 1; i <= 3500; i++) {
        if (n/4 >= i) continue;
        for (j = i; j <= 3500; j++) {
            LL tmp1 = i+j;
            LL tmp2 = i*j;
            k = 4*tmp2 - n*tmp1;
            if (k > 0 && n*tmp2%k==0) {
                k = n*tmp2/k;
                return;
            }
        }
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    solve(n);
    cout << i << ' ' << j << ' ' << k << endl;

    return 0;
}