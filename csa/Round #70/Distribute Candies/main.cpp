#include <iostream>
#include <assert.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
LL nums[MAXN];
bool solve (LL n, LL k) {
    LL a = n / k;
    LL b = n % k;
    if (a == 0) return false;
    if ((k%2==0 && b==k/2) || (k%2==1 && b==(k+1)/2))  {
        for (int i = 0; i < k; i++) {
            if (i % 2 == 0) nums[i] = a+1;
            else nums[i] = a;
        }
        return true;
    }
    if (k%2 == 1 && b == k/2) {
        for (int i = 0; i < k; i++) {
            if (i%2 == 0) nums[i] = a;
            else nums[i] = a+1;
        }
        return true;
    }
    LL cnta = k - b, cntb = b;
    int i = 0;
    while (cnta>0 && cntb>0) {
        cnta--;
        cntb--;
        nums[i] = a;
        nums[i+1] = a+1;
        i += 2;
    }
    if (cntb > 0) a = a+1;
    int delta;
    if (nums[i-1] == a+1) delta = -1;
    else delta = 1;
    while (i+1 < k) {
        nums[i] = a+delta;
        nums[i+1] = a-delta;
        i += 2;
    }
    if (i == k-1) nums[i] = a;
    LL tmp = 0;
    for (int j = 0; j < k; j++) {
        if (nums[j] <= 0) return false;
        tmp += nums[j];
    }
    assert(tmp == n);
    return true;

}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LL n, k;
    cin >> n >> k;
    if (solve (n, k)) {
        for (int i = 0; i < k; i++) {
            cout << nums[i];
            if (i+1 == k) cout << endl;
            else cout << ' ';
        }
    }
    else cout << -1 << endl;

    return 0;
}