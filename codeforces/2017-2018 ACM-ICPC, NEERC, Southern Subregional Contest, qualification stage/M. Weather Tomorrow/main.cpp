#include <iostream>
using namespace std;
const int MAXN = 100 + 10;
int nums[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    int d, n;
    cin >> n;
    cin >> nums[0] >> nums[1];
    d = nums[1] - nums[0];
    bool flag = true;
    for (int i = 2; i < n; i++) {
        cin >> nums[i];
        if (nums[i] - nums[i-1] != d) flag = false;
    }
    if (flag) cout << d+nums[n-1] << endl;
    else cout << nums[n-1] << endl;
    return 0;
}