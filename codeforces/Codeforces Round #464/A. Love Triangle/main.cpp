#include <iostream>
using namespace std;
const int MAXN = 5000 + 10;
int f[MAXN];
int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        int cur = f[i];
        cur = f[cur];
        if (f[cur] == i) {
            flag = true;
            break;
        }
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}