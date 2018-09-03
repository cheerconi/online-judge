#include <iostream>
#include <memory.h>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
const int MAXN = 110;
int red[MAXN], black[MAXN];
int dis[MAXN];
bool in[MAXN];

int update(int k, int n, vector<int> & v) {
    int val = INT_MAX;
    int ret = -1;
    for (int i = 0; i < n; i++) {
        if (in[i]) continue;
        for (int ind : v) {
            int tmp = red[ind]^black[i];
            tmp = min(tmp, black[ind]^red[i]);
            if (dis[i] == -1 || dis[i] > tmp) dis[i] = tmp;
        }
        if (dis[i] < val) {
            val = dis[i];
            ret = i;
        }
    }
    return ret;
}

LL solve(int n) {
    memset(in, false, sizeof(in));
    memset(dis, -1, sizeof(dis));
    pii item = {-1, -1};
    int val = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int tmp = black[i]^red[j];
            tmp = min(tmp, red[i]^black[j]);
            if (tmp < val) {
                val = tmp;
                item = {i, j};
            }
        }
    }
    LL cnt = val;
    in[item.first] = true;
    in[item.second] = true;
    vector<int> v{item.first, item.second};
    update(item.first, n, v);
    int ind = update(item.second, n, v);
    while (ind != -1) {
        cnt += dis[ind];
        in[ind] = true;
        v.push_back(ind);
        ind = update(ind, n, v);
    }
    return cnt;
}


int main() {
    freopen("test.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            scanf("%d", &red[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &black[i]);
        }
        printf("Case #%d: %lld\n", t, solve(n));
    }
    return 0;
}