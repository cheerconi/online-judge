#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
int nums[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums, nums+n);
    int b = nums[n-1];
    int a = nums[0];
    for (int i = 1; i < n-1; i++) {
        if (abs(2*nums[i]-b) < abs(2*a-b)) {
            a = nums[i];
        }
    }
    cout << b << ' ' << a << endl;
    return 0;
}