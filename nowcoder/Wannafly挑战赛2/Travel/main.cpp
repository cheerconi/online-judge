#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
int const MAXN = 52501 + 10;
LL dp[50][50];
LL sum[MAXN];
LL n;
LL get(int i, int j) {
    if (i > j) swap(i, j);
    LL ret = sum[j-1] - sum[i-1];
    ret = min(ret, sum[i-1] + sum[n] - sum[j-1]);
    return ret;
}
int main() {
//    freopen("test.txt", "r", stdin);
    LL m, val;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &val);
        sum[i] = sum[i-1] + val;
    }
    multimap<pii, LL> edges;
    int a, b;
    int c;
    set<int> tmp;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        tmp.insert(a);
        tmp.insert(b);
        edges.insert({{a, b}, c});
    }
    vector<int> points(tmp.begin(), tmp.end());
    map<int, int> table;
    int nn = points.size();
    for (int i = 0; i < nn; i++) {
        table[points[i]] = i;
    }

    for (int i = 0; i < nn; i++) {
        for (int j = i+1; j < nn; j++) {
            dp[i][j] = get(points[i], points[j]);
            dp[j][i] = dp[i][j];
        }
    }
    for (auto it : edges) {
        int x = it.first.first;
        int y = it.first.second;
        x = table[x];
        y = table[y];
        if (dp[x][y] > it.second) {
            dp[x][y] = it.second;
            dp[y][x] = dp[x][y];
        }
    }
    while (true) {
        bool flag = false;
        for (int i = 0; i < nn; i++) {
            for (int j = 0; j < nn; j++) {
                for (int k = 0; k < nn; k++) {
                    if (dp[i][j] > dp[i][k] + dp[k][j]) {
                        dp[i][j] = dp[i][k] + dp[k][j];
                        flag = true;
                    }


                }
            }
        }
        if (!flag) break;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &a, &b);
        LL ret = get(a, b);
        for (int x = 0; x < nn; x++) {
            for (int y = 0; y < nn; y++) {
                ret = min(ret, get(a, points[x]) + get(b, points[y]) + dp[x][y]);
            }
        }
        printf("%lld\n", ret);
    }

    return 0;
}