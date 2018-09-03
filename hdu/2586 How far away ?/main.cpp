#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

const int MAXN = 40000 + 10;
vector<pii> neg[MAXN];
int path[MAXN << 1];
int deep[MAXN << 1];
int dis[MAXN];
int first[MAXN];
int dp[MAXN << 1][24];

int pos;
void dfs(int cur, int d, int fa, int w) {
    dis[cur] = w;
    for (pii tmp : neg[cur]) {
        if (tmp.first == fa) continue;
        deep[pos] = d;
        path[pos++] = cur;
        dfs(tmp.first, d+1, cur, w+tmp.second);
    }
    deep[pos] = d;
    path[pos++] = cur;
}
void make_st() {
    for (int i = 0; i < pos; i++) {
        if (first[path[i]] == -1) first[path[i]] = i;
        dp[i][0] = i;
    }
    for (int i = 1; i <= 24; i++) {
        for (int j = 0; j < pos; j++) {
            if (j+(1<<i)-1 >= pos) break;
            int a = dp[j][i-1];
            int b = dp[j+(1<<(i-1))][i-1];
            if (deep[a] > deep[b]) dp[j][i] = b;
            else dp[j][i] = a;
        }
    }
}
int search(int a, int b) {
    if (a > b) swap(a, b);
    int i = -1;
    int length = b - a + 1;
    while (length) {
        i++;
        length >>= 1;
    }
    int c = dp[a][i];
    int d = dp[b+1-(1<<i)][i];
    if (deep[c] > deep[d]) return path[d];
    else return path[c];

}
int compute(int a, int b) {
    return dis[a] + dis[b] - 2 * dis[search(first[a], first[b])];
}

int main() {
//    freopen("test.txt", "r", stdin);
    int t, n, q, a, b, weight;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n-1; i++) {
            scanf("%d%d%d", &a, &b, &weight);
            neg[a].push_back({b, weight});
            neg[b].push_back({a, weight});
        }
        pos = 0;
        dfs(1, 0, 0, 0);
        memset(first, -1, sizeof(first));
        make_st();
        while (q--) {
            scanf("%d%d",&a, &b);
            printf("%d\n", compute(a, b));
        }


    }
    return 0;
}