#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 123;
vector<pii> edges[MAXN];
int state[MAXN];
bool solve (int cur) {
    for (auto & item : edges[cur]) {
        int cmd;
        if (item.second == 0 && state[cur] == 1) {
            cmd = -1;
        }
        else if (item.second == 0 && state[cur] == -1) {
            cmd = 1;
        }
        else if (item.second == 1 && state[cur] == 1) {
            cmd = 1;
        }
        else cmd = -1;
        if (state[item.first] == 0) {
            state[item.first] = cmd;
            if(!solve (item.first)) return false;
        }
        if (state[item.first] != cmd) return false;
    }
    return true;
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, a, b, c;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    bool succ = true;
    for (int i = 1; i <= n; i++) {
        if (state[i] == 0) {
            state[i] = 1;
            if (!solve(i)) {
                succ = false;
                break;
            }
        }
    }
    if (succ) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (state[i] == 1) cnt++;
        }
        cout << cnt << endl;
        for (int i = 1; i <= n; i++) {
            if (state[i] == 1) {
                cout << i;
                cnt--;
                if (cnt == 0) cout << endl;
                else cout << ' ';
            }

        }
        return 0;
    }
    else cout << "Impossible" << endl;
    return 0;
}