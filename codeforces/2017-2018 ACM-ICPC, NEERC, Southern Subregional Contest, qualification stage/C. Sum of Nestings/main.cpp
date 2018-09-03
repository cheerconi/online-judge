#include <iostream>
typedef long long LL;
using namespace std;

void solve (LL n, LL k) {
    if (n*(n-1)/2 < k) {
        printf("Impossible\n");
        exit(0);
    }
    LL left = 0;
    LL right = n;
    while (left < right) {
        LL mid = (left+right) >> 1;
        LL val = mid*(mid-1) / 2;
        if (val >= k) right = mid;
        else left = mid + 1;
    }
    if (left*(left-1)/2 > k) left--;
    int other = k - left*(left-1)/2;
    for (int i = 0; i < left; i++) {
        if (i == other && other != 0) {
            printf("()");
            n--;
        }
        printf("(");
        n--;
    }
    for (int i = 0; i < left; i++) {
        printf(")");
    }
    for (int i = 0; i < n; i++) {
        printf("()");
    }
    cout << endl;
    return;

}

int main() {
//    freopen("test.txt", "r", stdin);
    LL n, k;
    cin >> n >> k;
    solve(n, k);

}