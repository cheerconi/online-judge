#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;
const int MAXN = 1e5 + 10;
int nxt[MAXN];
bool used[MAXN], ret[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    memset(ret, true, sizeof(ret));
    for (int i = 1; i <= n; i++) {
        cin >> nxt[i];
        ret[nxt[i]] = false;
    }
    for (int i = 1; i <= n; i++) {
        if (!ret[i]) continue;
        vector<int> v;
        int cur = i;
        while (!used[cur]) {
            used[cur] = true;
            v.push_back(cur);
            cur = nxt[cur];
        }
        int n = v.size();
        for (int i = n-2; i >= 0; i--) {
            cout << v[i] << ' ' << v[i+1] << '\n';
        }
    }
    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        vector<int> v;
        int cur = i;
        while (!used[cur]) {
            used[cur] = true;
            v.push_back(cur);
            cur = nxt[cur];
        }
        int n = v.size();
        for (int i = n-2; i >= 0; i--) {
            cout << v[i] << ' ' << v[i+1] << '\n';
        }
    }
    return 0;
}