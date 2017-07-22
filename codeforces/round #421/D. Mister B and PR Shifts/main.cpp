#include <iostream>
using namespace std;
typedef long long LL;
const int MAXN = 1000000 + 10;
LL a[MAXN];
LL b[MAXN];

void add(LL k, LL val, int start, int end) {
    if (start > end) return;
    a[start] += k;
    a[end+1] -= k;
    LL bias = val - start*k;
    b[start] += bias;
    b[end+1] -= bias;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, num;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &num);
        if (num >= i) {
            add(-1, num-i, 0, num-i);
            add(1, 1, num-i+1, n-i);
            add(-1, num-1, n-i+1, n-1);
        }
        else {
            add(1, i-num, 0, n-i);
            add(-1, num-1, n-i+1, n+num-i);
            add(1, 1, n+num-i+1, n-1);
        }

    }
    int pos = 0;
    LL val = b[0];
    for (int i = 1; i < n; i++) {
        a[i] += a[i-1];
        b[i] += b[i-1];
        if (a[i]*i + b[i] < val) {
            val = a[i]*i + b[i];
            pos = i;
        }

    }
    cout << val << ' ' << pos << endl;
    return 0;
}