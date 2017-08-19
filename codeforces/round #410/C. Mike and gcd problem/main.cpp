#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
const int MAXN = 100000 + 10;
int state[MAXN];

int gcd(int a, int b) {
    if (a > b) return gcd(b, a);
    if (a == 0) return b;
    return gcd(a, b%a);
}




int main() {
//    freopen("test.txt", "r", stdin);
    int n, tmp;
    scanf("%d", &n);
    int d = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        if (tmp % 2 == 0) state[i] = true;
        if (d != 1) d = gcd(d, tmp);
    }
    if (d > 1) {
        cout << "YES" << endl << "0" << endl;
        return 0;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!state[i]) {
            i++;
            if (i < n && !state[i]) cnt++;
            else cnt += 2;
        }
    }
    cout << "YES" << endl << cnt << endl;
    return 0;






    return 0;
}