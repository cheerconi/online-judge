#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
typedef long long LL;

int solve (deque<int> & v, LL k) {
    int cur = v.front();
    v.pop_front();
    int cnt = 0;
    int val;
    while (cnt < k) {
        if (cur > v.front()) {
            cnt++;
            val = v.front();
            v.pop_front();
            v.push_back(val);
        }
        else {
            cnt = 1;
            v.push_back(cur);
            cur = v.front();
            v.pop_front();
        }
    }
    return cur;
}

int main() {
    int n, val;
    LL k;
    cin >> n >> k;
    int ret = 0;
    deque<int> v;
    for (int i = 0; i < n; i++) {
        cin >> val;
        v.push_back(val);
        ret = max(ret, val);
    }
    if (k >= n-1) {
        cout << ret << endl;
        return 0;
    }
    cout << solve(v, k) << endl;
    return 0;
}