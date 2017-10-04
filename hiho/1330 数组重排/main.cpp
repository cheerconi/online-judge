#include <iostream>
using namespace std;
const int MAXN = 100 + 5;
int nums[MAXN];
bool vis[MAXN];

int gcd(int a, int b) {
    if (b > a) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a%b);
}


int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
    }
    int ret = 1;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        int cur = nums[i];
        int tmp = 1;
        while (cur != i) {
            vis[cur] = true;
            tmp++;
            cur = nums[cur];
        }
        ret = ret*tmp / gcd(ret, tmp);
    }
    cout << ret << endl;
    return 0;
}