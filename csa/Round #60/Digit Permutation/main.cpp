#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
vector<int> nums[MAXN], edges[MAXN];
int ret[MAXN], cand[MAXN], degree[MAXN];

bool solve (int k) {
    int tot = 0;
    for (int i = 0; i < k; i++) {
        if (degree[i] == 0) cand[tot++] = i;
    }
    if (tot == 0) return false;
    if (cand[0] == nums[0][0]) {
        if (tot == 1) return false;
        swap(cand[0], cand[1]);
    }
    for (int i = 0; i < tot; i++) {
        ret[cand[i]] = i;
        for (int son : edges[cand[i]]) {
            degree[son]--;
            if (degree[son] == 0) cand[tot++] = son;
        }
    }
    return tot == k;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, k, m, val;
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &val);
            nums[i].push_back(val);
        }
    }
    for (int i = 0; i+1 < n; i++) {
        int j = 0;
        while (j < m && nums[i][j]==nums[i+1][j]) j++;
        if (j == m) return 0 * puts("-1\n");
        edges[nums[i][j]].push_back(nums[i+1][j]);
        degree[nums[i+1][j]]++;
    }
    if (solve(k)) {
        for (int i = 0; i < k; i++) {
            printf("%d", ret[i]);
            if (i+1 == k) printf("\n");
            else printf(" ");
        }
    }
    else {
        puts("-1\n");
    }
    return 0;

}