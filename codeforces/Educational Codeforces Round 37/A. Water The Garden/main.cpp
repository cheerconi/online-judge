#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
//    freopen("test.txt", "r", stdin);
    int n, k, val, ret;
    int cs; cin >> cs;
    while (cs--) {
        cin >> n >> k;
        vector<int> taps;
        for (int i = 0; i < k; i++) {
            cin >> val;
            taps.push_back(val);
        }
        ret = 0;
        for (int i = 1; i <= n; i++) {
            val = n;
            auto it = lower_bound(taps.begin(), taps.end(), i);
            if (it != taps.end()) {
                val = min(val, *it-i+1);
            }
            if (it != taps.begin()) {
                it--;
                val = min(val, i-*it+1);
            }
            ret = max(val, ret);
        }
        cout << ret << '\n';

    }

    return 0;
}