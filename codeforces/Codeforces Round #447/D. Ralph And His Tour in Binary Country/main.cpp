#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 1e6 + 10;
int dist[MAXN];
vector<int> items[MAXN];
vector<LL> sum[MAXN];
int n;
void merge(int x) {
    items[x].push_back(0);
    if (2*x > n) return;
    if (2*x+1 > n) {
        for (int item : items[2*x]) {
            items[x].push_back(dist[2*x] + item);
        }
        return;
    }
    int i = 0, j = 0;
    while (i < items[2*x].size() && j < items[2*x+1].size()) {
        if (items[2*x][i]+dist[2*x] <= items[2*x+1][j]+dist[2*x+1]) {
            items[x].push_back(items[2*x][i++]+dist[2*x]);
        }
        else items[x].push_back(items[2*x+1][j++]+dist[2*x+1]);
    }
    while (i < items[2*x].size()) {
        items[x].push_back(items[2*x][i++]+dist[2*x]);
    }
    while (j < items[2*x+1].size()) {
        items[x].push_back(items[2*x+1][j++]+dist[2*x+1]);
    }
}
void add(int x) {
    sum[x].resize(items[x].size());
    sum[x][0] = 0;
    for (int i = 1; i < sum[x].size(); i++) {
        sum[x][i] = sum[x][i-1] + items[x][i];
    }
}
LL count(int x, int h) {
    if (h <= 0 || x > n) return 0;
    int p = lower_bound(items[x].begin(), items[x].end(), h) - items[x].begin() - 1;
    LL ret = 1LL*(p+1)*h - sum[x][p];
    return ret;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int m;
    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        scanf("%d", &dist[i]);
    }
    for (int i = n; i >= 1; i--) {
        merge(i);
        add(i);
    }
    int a, h;
    while (m--) {
        scanf("%d%d", &a, &h);
        LL ret = count(a, h);
        while (a > 1) {
            h -= dist[a];
            if (h <= 0) break;
            ret += h;
            int b = a;
            if (b % 2 == 0) b++;
            else b--;
            ret += count(b, h-dist[b]);
            a /= 2;
        }
        printf("%I64d\n", ret);
    }


    return 0;
}