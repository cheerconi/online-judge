#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long double LD;
const int MAXN = 1e5 + 10;
int nums[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, u;
    cin >> n >> u;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    LD ret = -1;
    int j = 0;
    for (int i = 0; i+1 < n; i++) {
        while (j < n && nums[j]-nums[i] <= u) {
            j++;
        }
        if (j-1 <= i+1) continue;
        ret = max(ret, (LD)(nums[j-1]-nums[i+1]) / (nums[j-1]-nums[i]));
    }
    cout.setf(ios::fixed);
    if (ret >= 0) cout << setprecision(15) << ret << endl;
    else cout << -1 << endl;


    return 0;
}