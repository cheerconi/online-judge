#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 2000 + 10;
int gcd (int a, int b) {
    if (a > b) return gcd(b, a);
    if (a == 0) return b;
    return gcd(a, b%a);
}
int main() {
    int n, val, cnt = 0, d = 0;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        if (val == 1) cnt++;
        nums.push_back(val);
        d = gcd(d, nums.back());
    }
    if (d > 1) {
        cout << -1 << endl;
        return 0;
    }
    if (cnt > 0) {
        cout << n - cnt << endl;
        return 0;
    }
    while (true) {
        cnt++;
        vector<int> tmp;
        for (int i = 0; i+1 < nums.size(); i++) {
            tmp.push_back(gcd(nums[i], nums[i+1]));
            if (tmp.back() == 1) {
                cout << cnt + (n-1) << endl;
                return 0;
            }
        }
        nums = tmp;
    }
    return 0;
}