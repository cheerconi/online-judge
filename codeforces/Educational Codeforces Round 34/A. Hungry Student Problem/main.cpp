#include <iostream>
using namespace std;
const int MAXN = 110;
bool vis[MAXN];
int main() {
    int n, val;
    vis[0] = true;
    for (int i = 0; i < MAXN; i++) {
        if (vis[i]) {
            if (i+3 < MAXN) vis[i+3] = true;
            if (i+7 < MAXN) vis[i+7] = true;
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        if (vis[val]) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}