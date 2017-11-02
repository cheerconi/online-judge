#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 110;
int nums[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) scanf("%d", &nums[i]);
    nums[0] = -10000;
    nums[m+1] = 10000;
    sort(nums, nums+2+m);
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        auto it1 = lower_bound(nums, nums+m+2, a);
        auto it2 = upper_bound(nums, nums+m+2, b);
        cout << it2-it1 << endl;
    }
    return 0;
}