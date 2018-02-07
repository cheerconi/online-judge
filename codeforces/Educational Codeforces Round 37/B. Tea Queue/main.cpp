#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1234;
int L[MAXN], R[MAXN], ret[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    int n, cur;
    int cs; cin >> cs;
    while (cs--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> L[i] >> R[i];
        }
        cur = 0;
        for (int i = 1; i <= n; i++) {
            ret[i] = 0;
            if (cur > R[i]) continue;
            cur = max(cur, L[i]);
            ret[i] = cur;
            cur++;
        }
        for (int i = 1; i <= n; i++) {
            cout << ret[i];
            if (i == n) cout << '\n';
            else cout << ' ';
        }




    }
    return 0;
}