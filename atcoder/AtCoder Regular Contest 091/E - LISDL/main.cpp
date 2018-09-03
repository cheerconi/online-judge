#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 3e5 + 10;
int nums[MAXN], idx, n, a, b;
bool check (int n, int a, int b) {
    if (a+b > n+1) return false;
    int tmp = n / a;
    if (n % a != 0) tmp++;
    if (b < tmp) return false;
    tmp = n / b;
    if (n % b != 0) tmp++;
    if (a < tmp) return false;
    return true;
}
void solve () {
    if (n == b) {
        for (int i = 0; i < n; i++) {
            nums[idx++] = n-i;
        }
        n = 0;
        return;
    }
    if (n-a >= b-1) {
        for (int i = 0; i < a; i++) {
            nums[idx++] = n-a+1+i;
        }
        n -= a;
        b--;
        return;
    }
    int dist = n-(b-1);
    for (int i = 0; i < dist; i++) {
        nums[idx++] = n-dist+1+i;
    }
    n -= dist;
    b--;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> a >> b;
    if (!check(n, min(a, b), max(a, b))) {
        cout << -1 << endl;
        return 0;
    }
    while (n) {
        solve();
    }
    for (int i = 0; i < idx; i++) {
        cout << nums[i];
        if (i+1 == idx) cout << '\n';
        else cout << ' ';
    }


    return 0;
}