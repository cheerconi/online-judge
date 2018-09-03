#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
int deep[MAXN];
int path[MAXN << 1];
int first[MAXN];
int dp[MAXN<<1][19];
vector<int> neg[MAXN];
int pos;

void dfs(int cur, int fa, int dis) {
    deep[cur] = dis;
    for (int son : neg[cur]) {
        if (son == fa) continue;
        path[pos++] = cur;
        dfs(son, cur, dis+1);
    }
    path[pos++] = cur;
}
void make_st() {
    memset(first, -1, sizeof(first));
    for (int i = 0; i < pos; i++) {
        if (first[path[i]] == -1) first[path[i]] = i;
        dp[i][0] = path[i];
    }
    for (int j = 1; j < 19; j++) {
        for (int i = 0; i < pos; i++) {
            if (i+(1<<j)-1 >= pos) break;
            int tmp1 = dp[i][j-1];
            int tmp2 = dp[i+(1<<(j-1))][j-1];
            if (deep[tmp1] > deep[tmp2]) dp[i][j] = tmp2;
            else dp[i][j] = tmp1;
        }
    }
}
int search(int a, int b) {
    if (a > b) swap(a, b);
    int j = -1;
    int length = b - a + 1;
    while (length) {
        j++;
        length >>= 1;
    }
    int tmp1 = dp[a][j];
    int tmp2 = dp[b+1-(1<<j)][j];
    if (deep[tmp1] > deep[tmp2]) return tmp2;
    else return tmp1;
}
bool judge(int a, int b, int c, int d) {
    int dad_ab = search(first[a], first[b]);
    int dad_cd = search(first[c], first[d]);
    int dad_ac = search(first[a], first[c]);
    int dad_ad = search(first[a], first[d]);
    int dad_bc = search(first[b], first[c]);
    int dad_bd = search(first[b], first[d]);
    int dis_ac = deep[a] + deep[c] - 2*deep[dad_ac];
    int dis_ad = deep[a] + deep[d] - 2*deep[dad_ad];
    int dis_cd = deep[c] + deep[d] - 2*deep[dad_cd];
    int dis_ab = deep[a] + deep[b] - 2*deep[dad_ab];
    int dis_bc = deep[b] + deep[c] - 2*deep[dad_bc];
    int dis_bd = deep[b] + deep[d] - 2*deep[dad_bd];
    int tmp1 = dis_ac + dis_ad - dis_cd;
    int tmp2 = dis_bc + dis_bd - dis_cd;
    if (tmp1+tmp2 <= 2*dis_ab) return true;
    else return false;




}


int main() {
//    freopen("test.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, q;
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++) neg[i].clear();
        int a, b, c, d;
        for (int i = 1; i <= n-1; i++) {
            scanf("%d%d", &a, &b);
            neg[a].push_back(b);
            neg[b].push_back(a);
        }
        pos = 0;
        dfs(1, 0, 0);
        make_st();



        while (q--) {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            if (judge(a,b,c,d)) printf("YES\n");
            else printf("NO\n");

        }
    }
    return 0;
}