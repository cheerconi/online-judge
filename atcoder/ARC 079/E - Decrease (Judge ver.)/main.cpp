#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

LL a[55];

LL solve(LL n) {
    sort(a, a+n);
    if (a[n-1] < n) return 0;
    int i = 0;
    while (i < n) {
        if (a[i] >= a[n-1] - n - 1 && a[i]>n) break;
        i++;
    }
    i--;
    LL dis = a[n-1];
    if (i >= 0) dis = min(dis, (a[i+1]-a[i])/(n+1));
    for (int j = i+1; j < n; j++) {
        dis = min(dis, (a[j]-n) / (j+2));
        if (dis == 0) break;
    }
    if (dis == 0) {
        a[n-1] -= n;
        for (int j = 0; j < n-1; j++) a[j]++;
        return 1LL + solve(n);
    }
    for (int j = 0; j <= i; j++) a[j] += dis*(n-i-1);
    for (int j = i+1; j < n; j++) a[j] -= n*dis - dis*(n-i-2);
    return solve(n) + (n-i-1)*dis;


}

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    cout << solve(n) << endl;


    return 0;
}