#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 50;
LL neg[MAXN];
int card;
double mymax(double a, double b) {
    if (a > b) return a;
    return b;
}
int count(LL x) {
    int cnt = 0;
    while (x) {
        cnt++;
        x = x & (x-1);
    }
    return cnt;
}
void clique(LL cand, int sz) {
    if (cand == 0) {
        card = max(card, sz);
        return;
    }
    for (int i = 0; cand != 0; i++) {
        if (count(cand)+sz <= card) return;
        if ((cand & (1LL<<i)) != 0) {
            cand ^= (1LL << i);
            clique(cand&neg[i], sz+1);
        }
    }
}
int main() {
//    freopen("test.txt", "r", stdin);
    int n, k, tmp;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &tmp);
            if (tmp == 1) neg[i] |= 1LL<<j;
        }
    }
    clique((1LL<<n)-1, 0);

    double ret = 0;
    if (card > 1) {
        for (int i = 2; i <= card; i++) {
            ret = mymax(ret, k*k*(i-1)/2.0/i);
        }
    }
    printf("%.8f\n", ret);
    return 0;
}