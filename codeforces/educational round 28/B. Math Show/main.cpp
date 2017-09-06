#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 50;
int cost[MAXN];
int k;

int solve(int n, int m) {

    int cnt = 0;
    for (int i = 0; i < k; i++) {
        if (m < cost[i]) break;
        int tmp = m / cost[i];
        cnt += min(n, tmp);
        m -= min(n, tmp)*cost[i];
    }
    return cnt;
}



int main() {
//    freopen("test.txt", "r", stdin);
    int n, m;
    scanf("%d%d%d", &n, &k, &m);
    int sum = 0;
    for (int i = 0; i < k; i++) {
        scanf("%d", &cost[i]);
        sum += cost[i];
    }
    sort(cost, cost+k);

    int now = 0;
    int ret = 0;
    do {
        ret = max(ret, solve(n, m)+now);
        now += k + 1;
        m -= sum;
        n--;
    } while (m >= 0 && n >= 0);
    cout << ret << endl;


    return 0;
}