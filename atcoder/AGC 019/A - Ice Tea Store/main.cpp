#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
LL cost[4];
LL vol[] = {1, 2, 4, 8};
int ind[4];

bool cmp(int i, int j) {
    double a = cost[i]/ (double)vol[i];
    double b = cost[j] / (double)vol[j];
    return a < b;
}

int main() {
//    freopen("test.txt", "r", stdin);
    for (int i = 0; i < 4; i++) {
        scanf("%d", &cost[i]);
        ind[i] = i;
    }
    LL n;
    scanf("%lld", &n);
    n *= 4;
    sort(ind, ind+4, cmp);
    LL ret = 0;
    for (int j = 0; j < 4; j++) {
        int i = ind[j];
        LL tmp = n/vol[i];
        ret += tmp*cost[i];
        n -= tmp*vol[i];
    }
    cout << ret << endl;

}