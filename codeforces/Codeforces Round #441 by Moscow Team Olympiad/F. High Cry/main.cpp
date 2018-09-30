#include <iostream>
#include <limits.h>
using namespace std;
typedef long long LL;
const int MAXN = 200000 + 10;
int nums[MAXN], a[MAXN], b[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
    }
    nums[0] = nums[n+1] = INT_MAX;
    for (int i = 1; i <= n; i++) {
        a[i] = i-1;
        while ((nums[a[i]]|nums[i]) <= nums[i]) a[i] = a[a[i]];
    }
    for (int i = n; i >= 1; i--) {
        b[i] = i+1;
        while ((nums[b[i]]|nums[i]) <= nums[i] && nums[i] != nums[b[i]]) b[i] = b[b[i]];
    }
    LL ret = 1LL * n * (n-1) / 2 + n;
    for (int i = 1; i <= n; i++) {
        ret -= 1LL * (b[i]- i) * (i - a[i]);
    }
    cout << ret << endl;
    return 0;
}