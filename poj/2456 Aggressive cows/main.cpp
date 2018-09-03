#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
int nums[MAXN];
int n;
bool check (int d, int m) {
    int cur = 0;
    for (int i = 0; i < n && m > 0; i++) {
        if (nums[i] >= cur) {
            m--;
            cur = nums[i]+d;
        }
    }
    if (m == 0) return true;
    return false;
}
int main() {
    int m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    sort(nums, nums+n);
    int left = 0, right = 1e9;
    while (left < right) {
        int mid = (left + right + 1) >> 1;
        if (check(mid, m)) {
            left = mid;
        }
        else {
            right = mid-1;
        }
    }
    cout << left << endl;

    return 0;
}