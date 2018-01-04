#include <iostream>
using namespace std;
typedef long long LL;
const int MAXN = 1e6 + 10;
int nums[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    };
    LL pos = -nums[0], neg = nums[0], ret = 0;
    for (int i = 0; i < n; i++) {
        LL pre = ret;
        LL tmp = max(pos+nums[i], neg-nums[i]);
        ret = max(ret, tmp);
        pos = max(pos, pre-nums[i]);
        neg = max(neg, pre+nums[i]);
    }
    cout << ret << endl;
    return 0;
}