#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

const int MAXN = 100000 + 10;

struct Tree {
    int deep;
    int dad = 0;
    vector<int> sons;
};
int n, q;
Tree forest[MAXN];
int trace[MAXN << 1];
int first[MAXN];
int dis[MAXN];
int dp[MAXN][24];
int k;
void dfs(int root, int deep) {
    forest[root].deep = deep;
    for (int son : forest[root].sons) {
        trace[k++] = root;
        dfs(son, deep+1);
    }
    trace[k++] = root;
}

void make_st() {
    for (int i = 0; i < k; i++) {
        if (first[trace[i]] == -1) {
            first[trace[i]] = i;
            dis[trace[i]] = forest[trace[i]].deep;
        }
    }
    for (int i = 1; i <= n; i++) dp[i][0] = dis[i];
    for (int i = 1; i <= 24; i++) {
        for (int j = 1; j <= n; j++) {
            if (j+(1<<i)-1 > n) break;
            dp[j][i] = min(dp[j][i-1], dp[j+(1<<(i-1))][i-1]);
        }
    }
}

int search(int a, int b) {
    if (a > b) return search(b, a);
    
}


int main() {
    scanf("%d%d", &n, &q);
    int dad;
    for (int i = 2; i <= n; i++) {
        scanf("%d", &dad);
        forest[i].dad = dad;
        forest[dad].sons.push_back(i);
    }
    memset(first, -1, sizeof(first));
    dfs(1, 0);
    make_st();


    return 0;
}