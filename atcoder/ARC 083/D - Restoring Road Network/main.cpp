#include <iostream>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 300 + 5;
int dp[MAXN][MAXN];
int n;
struct Edge{
    int i,j,dist;
    bool operator< (Edge const & other) const {
        return dist < other.dist;
    }
};
vector<Edge> edges;

void update(Edge & edge) {
    int a = edge.i;
    int b = edge.j;
    int dist = edge.dist;
    for (int i = 0; i < n; i++) {
        if (dp[i][a] == -1) continue;
        for (int j = i+1; j < n; j++) {
            if (dp[b][j] == -1) continue;
            LL tmp = 0LL + dp[i][a] + dist + dp[b][j];
            if (dp[i][j]==-1 || dp[i][j]>tmp) {
                dp[i][j] = tmp;
                dp[j][i] = tmp;
            }

        }
    }
    for (int i = 0; i < n; i++) {
        if (dp[i][b] == -1) continue;
        for (int j = i+1; j < n; j++) {
            if (dp[a][j] == -1) continue;
            LL tmp = 0LL + dp[i][b] + dist + dp[a][j];
            if (dp[i][j]==-1 || dp[i][j]>tmp) {
                dp[i][j] = tmp;
                dp[j][i] = tmp;
            }

        }
    }
}
LL solve() {
    LL ret = 0;
    for (Edge & edge : edges) {
        int i = edge.i, j = edge.j, dist = edge.dist;
        if (dp[i][j] == dist) continue;
        if (dp[i][j] != -1 && dp[i][j] < dist) return -1;
        ret = ret + dist;
        update(edge);
    }
    return ret;
}

int main() {
//    freopen("test.txt", "r", stdin);
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    int data;
    for (int i = 0; i < n; i++) dp[i][i] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &data);
            Edge tmp;
            if (i < j) {
                tmp.dist = data;
                tmp.i = i;
                tmp.j = j;
                edges.push_back(tmp);
            }

        }
    }
    sort(edges.begin(), edges.end());
    cout << solve() << endl;
    return 0;
}