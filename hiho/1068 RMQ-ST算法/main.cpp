#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1000000 + 10;
int weight[MAXN];
int dp[MAXN][24];
int n;

void make_st() {
    for (int i = 0; i < n; i++) dp[i][0] = weight[i];

    for(int j = 1; j <= 24; j++) {
        for (int i = 0; i < n; i++) {
            if (i+(1<<j) > n) break;
            dp[i][j] = min(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
        }
    }
    return;
}

int findmin(int a, int b) {
    int j = 0;
    int length = b - a + 1;
    length /= 2;
    while (length) {
        j++;
        length /= 2;
    }
    int ret = dp[a][j];
    ret = min(ret, dp[b-(1<<j)+1][j]);
    return ret;
}

int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }
    make_st();
    int q, a, b;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &a, &b);
        int tmp = findmin(a-1, b-1);
        printf("%d\n", tmp);

    }
    return 0;
}