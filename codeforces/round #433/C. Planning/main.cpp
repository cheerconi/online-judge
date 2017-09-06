#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 300000 + 10;
int cost[MAXN];
int ind[MAXN];

bool cmp(int i, int j) {
    return cost[i] > cost[j];
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, k;
    set<int> s;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &cost[i]);
        s.insert(i+k);
        ind[i] = i;
    }
    sort(ind+1, ind+1+n, cmp);
    LL ret = 0;
    for (int i = 1; i <= n; i++) {
        auto it = s.lower_bound(ind[i]);
        ret += (*it - ind[i])*(LL)cost[ind[i]];
        cost[ind[i]] = *it;
        s.erase(it);
    }
    cout << ret << endl;
    for (int i = 1; i <= n; i++) {
        printf("%d", cost[i]);
        if (i == n) cout << endl;
        else printf(" ");
    }

}