#include <iostream>
using namespace std;
typedef long long LL;
const int MAXN = 200000 + 10;
LL nums[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    LL sum = 0, cur = 0;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        sum += nums[i];
    }
    for (int i = 1; i <=n; i++) {
        cur += nums[i];
        if (cur*2 >= sum) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}