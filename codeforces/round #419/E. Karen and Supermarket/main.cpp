#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
static const int MAXN = 5000 + 10;

LL dp[MAXN][MAXN][2];
LL budget;

struct Good{
    LL price;
    LL coupon;
    int size = 0;
    vector<int> sons;

} goods[MAXN];

void dfs(int root) {
    int size = 1;
    dp[root][1][1] = goods[root].price - goods[root].coupon;
    dp[root][1][0] = goods[root].price;
    dp[root][0][0] = 0;
    int newsize = 0;
    for (int i = 0; i < goods[root].sons.size(); i++) {
        int son = goods[root].sons[i];
        dfs(son);
        for (int x = size; x >= 0; x--) {
            for (int y = goods[son].size; y >= 0; y--) {
                dp[root][x+y][0] = min(dp[root][x+y][0], dp[root][x][0]+dp[son][y][0]);
                dp[root][x+y][1] = min(dp[root][x+y][1], dp[root][x][1]+min(dp[son][y][1], dp[son][y][0]));
                if (dp[root][x+y][1] <= budget || dp[root][x+y][0] <= budget) newsize = max(newsize, x+y);
//                cout << "root is " << root << "         " << "x+y is " << x+y << endl;
//                cout << "dp[root][x+y][0] " << dp[root][x+y][0] << endl;
//                cout << "dp[root][x+y][1] " << dp[root][x+y][1] << endl;
            }
        }
        size = newsize;
    }
    if (dp[root][1][1] <= budget) newsize = max(1, newsize);
    goods[root].size = newsize;
}
int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d%I64d%I64d%I64d", &n, &budget, &goods[1].price, &goods[1].coupon);
    int pre;
    for (int i = 2; i <= n; i++) {
        scanf("%I64d%I64d%d", &goods[i].price, &goods[i].coupon, &pre);
        goods[pre].sons.push_back(i);
    }
    memset(dp, 1, sizeof(dp));

    dfs(1);
    cout << goods[1].size << endl;
//    for (int i = 0; i <= n; i++) {
//        cout << dp[1][i][0] << ' ' << dp[1][i][1] << endl;
//    }

    return 0;
}