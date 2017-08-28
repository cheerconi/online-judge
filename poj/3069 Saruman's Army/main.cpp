#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 10;
int nums[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    int r, n;
    while (scanf("%d%d", &r, &n) && n != -1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        sort(nums, nums+n);
        int cnt = 0;
        int k = 0;
        for (int i = 1; i < n && k < n; i++) {
            if (i > k && nums[i]-nums[k] > r) {
                cnt++;
                while (k < n && abs(nums[k]-nums[i-1]) <= r) k++;
            }
        }
        if (k != n) cnt++;
        cout << cnt << endl;

    }
    return 0;
}