#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10;
double t[MAXN];
int rate[MAXN];
int ind[MAXN];
double eps = 1e-6;

bool cmp(int i, int j) {
    return t[i] < t[j];
}
int main() {
//    freopen("test.txt", "r", stdin);
    int n, k, tmp;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &rate[i], &tmp);
        t[i] = (double)tmp / rate[i];
        ind[i] = i;
    }
    sort(ind, ind+n, cmp);
    LL cost = 0;
    double store = k * t[ind[0]];
    for (int i = 1; i < n; i++) {
        cost += rate[ind[i-1]];
        if (cost > k) {
            double ret = store/(cost-k)+t[ind[i-1]];
            if (ret < t[ind[i]]) {
                printf("%.10f\n", ret);
                return 0;
            }
        }
        store += (k-cost) * (t[ind[i]]-t[ind[i-1]]);
    }
    cost += rate[ind[n-1]];
    if (cost <= k) cout << -1 << endl;
    else {
        double ret = store/(cost-k) + t[ind[n-1]];
        printf("%.10f\n", ret);
    }
    return 0;
}