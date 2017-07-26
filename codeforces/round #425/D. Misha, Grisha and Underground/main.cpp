#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

const int MAXN = 100000 + 10;

struct Station{
    vector<int> sons;
    int dis;
};

Station trees[MAXN];
int first[MAXN];
int path[MAXN << 1];
int deep[MAXN << 1];
int dp[MAXN << 1][24];
int pos;
void dfs(int cur, int dis) {
    trees[cur].dis = dis;
    for (int son : trees[cur].sons) {
        path[pos] = cur;
        deep[pos++] = dis;
        dfs(son, dis+1);
    }
    path[pos] = cur;
    deep[pos++] = dis;
}
void make_st() {
    for (int i = 0; i < pos; i++) {
        if (first[path[i]] == -1) first[path[i]] = i;
        dp[i][0] = i;
    }
    for (int j = 1; j <= 24; j++) {
        for (int i = 0; i < pos; i++) {
            if (i + (1<<j) - 1 >= pos) break;
            int a = dp[i][j-1];
            int b = dp[i+(1<<(j-1))][j-1];
            if (deep[a] > deep[b]) dp[i][j] = b;
            else dp[i][j] = a;
        }
    }
}

int search(int a, int b) {
    if (a > b) swap(a, b);
    int j = -1;
    int length = b - a + 1;
    while (length) {
        j++;
        length /= 2;
    }
    int c = dp[a][j];
    int d = dp[b+1-(1<<j)][j];
    if (deep[c] > deep[d]) return path[d];
    else return path[c];

}

int main() {
//    freopen("test.txt", "r", stdin);
    memset(first, -1, sizeof(first));
    int n, q, dad;
    scanf("%d%d", &n, &q);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &dad);
        trees[dad].sons.push_back(i);
    }
    dfs(1, 0);
    make_st();
    int a, b, c;
    while (q--) {
        scanf("%d%d%d", &a, &b, &c);
        int ret = 0, tmp;
        tmp = search(first[a], first[b]);
        int ab = trees[a].dis + trees[b].dis - 2*(trees[tmp].dis);
        tmp = search(first[b], first[c]);
        int bc = trees[b].dis + trees[c].dis - 2*(trees[tmp].dis);
        tmp = search(first[a], first[c]);
        int ac = trees[a].dis + trees[c].dis - 2*(trees[tmp].dis);
        ret = max(ret, ac+bc-ab);
        ret = max(ret, ab+bc-ac);
        ret = max(ret, ab+ac-bc);
        ret = ret/2 + 1;
        printf("%d\n", ret);
    }



    return 0;
}