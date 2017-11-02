#include <iostream>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
int nums[MAXN];
LL n, k;

bool solve(LL val) {
    if (val == 0) return true;
    LL cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += nums[i] / val;
        if (cnt >= k) return true;
    }
    return false;

}

int main() {
    LL sum = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        sum += nums[i];
    }
    LL left = 0, right = sum / k;
    while (left < right) {
        LL mid = (left+right) >> 1;
        if (solve(mid)) left = mid + 1;
        else right = mid;
    }
    if (!solve(left)) left--;
    cout << left << endl;
    return 0;
}