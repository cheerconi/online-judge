#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100 + 10;
int nums[MAXN];
int cnt[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    for (int i = n-1; i >= 0; i--) {
        cnt[i] = cnt[i+1];
        if (nums[i] == 1) cnt[i]++;
    }
    int ret = 0;
    int zero = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) zero++;
        ret = max(ret, zero+cnt[i]);
    }
    cout << ret << endl;

    return 0;
}