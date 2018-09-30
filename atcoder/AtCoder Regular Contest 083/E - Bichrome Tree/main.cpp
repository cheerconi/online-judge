#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1000 + 10;
vector<int> sons[MAXN];
int data[MAXN], dp0[MAXN], dp1[MAXN];
int n;

int solve(vector<int> & dp, int m) {
    vector<bool> cur(m+1, false);
    cur[0] = true;
    int ret = 0;
    for (int i = 0; i < dp.size(); i++) {
        for (int j = cur.size()-1; j >= dp[i]; j--) {
            if (dp[j-dp[i]]) dp[j] = true;
            ret = max(j, ret);
        }
    }
    return ret;
}

void dfs(int root) {
    int white = 0;
    int black = 0;
    int sum = 0;
    vector<int> dp;
    for (int son : sons[root]) {
        dfs(son);
        if (dp1[son] != -1) white += dp1[son]; // white amount when black is satifised
        if (dp0[son] != -1) black += dp0[son]; // when white is satifised
    }
    int cnt = 0;
    if (data[root] >= white) {
        int tmp = solve(dp, data[root]-white);
        if (black+sum-tmp)
    }
}


int main() {
    freopen("test.txt", "r", stdin);
    scanf("%d", &n);
    int dad;
    for (int i = 2; i <= n; i++) {
        scanf("%d", &dad);
        sons[dad].push_back(i);
    }
    for (int i =1; i <= n; i++) scanf("%d", &data[i]);
    dfs(1);
    return 0;
}