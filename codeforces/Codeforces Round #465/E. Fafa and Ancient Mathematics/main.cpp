#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 1e4 + 10;
int a[MAXN][123], b[MAXN][123], tot;
pii nums[MAXN];
string s;
int dfs (int & i) {
    if (s[i] == '(') {
        int idx = tot++;
        i++;
        int idx1 = dfs(i);
        int idx2 = dfs(i);
        i++;
        nums[idx] = {idx1, idx2};
        return idx;
    }
    if (isdigit(s[i])) {
        int num = s[i] - '0';
        int idx = tot++;
        i++;
        nums[idx] = {-num, -num};
        return idx;
    }
    if (s[i] == '?') {
        i++;
        return dfs (i);
    }
}

void solve (int cur, int rare, int mi) {
    if (nums[cur].first < 0) {
        a[cur][0] = b[cur][0] = -nums[cur].first;
        return;
    }
    solve (nums[cur].first, rare, mi);
    solve (nums[cur].second, rare, mi);

    for (int i = 0; i <= mi; i++) {
        if (a[nums[cur].first][i] == INT_MAX) break;
        for (int j = 0; j+i <= mi; j++) {
            if (a[nums[cur].second][j] == INT_MAX) break;
            if (rare == 1) {
                if (i+j < mi) {
                    b[cur][i+j+1] = max(b[cur][i+j+1], b[nums[cur].first][i] + b[nums[cur].second][j]);
                    a[cur][i+j+1] = min(a[cur][i+j+1], a[nums[cur].first][i] + a[nums[cur].second][j]);
                }
                b[cur][i+j] = max(b[cur][i+j], b[nums[cur].first][i] - a[nums[cur].second][j]);
                a[cur][i+j] = min(a[cur][i+j], a[nums[cur].first][i] - b[nums[cur].second][j]);
            }
            else {
                if (i+j < mi) {
                    b[cur][i+j+1] = max(b[cur][i+j+1], b[nums[cur].first][i] - a[nums[cur].second][j]);
                    a[cur][i+j+1] = min(a[cur][i+j+1], a[nums[cur].first][i] - b[nums[cur].second][j]);
                }
                b[cur][i+j] = max(b[cur][i+j], b[nums[cur].first][i] + b[nums[cur].second][j]);
                a[cur][i+j] = min(a[cur][i+j], a[nums[cur].first][i] + a[nums[cur].second][j]);
            }
        }
    }
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    int p, m;
    cin >> p >> m;
    if (p+m == 0) {
        cout << s << endl;
        return 0;
    }
    int i = 0;
    int root = dfs (i);
    for (int i = 0; i <= min(p, m); i++) {
        for (int j = 0; j < tot; j++) {
            a[j][i] = INT_MAX;
            b[j][i] = INT_MIN;
        }
    }
    int ret;
    if (p > m) {
        solve (root, -1, m);
        ret = b[root][m];
    }
    else {
        solve (root, 1, p);
        ret = b[root][p];
    }
    cout << ret << endl;


    return 0;
}