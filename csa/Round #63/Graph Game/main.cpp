#include <iostream>
#include <memory.h>
using namespace std;
const int MAXN = 1e5 + 10;
int degree[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m, a, b;
        cin >> n >> m;
        memset(degree, 0, sizeof(degree));
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            degree[a]++;
            degree[b]++;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (degree[i] % 2 == 0) cnt++;
        }
        cout << cnt%2 << endl;
    }
    return 0;
}