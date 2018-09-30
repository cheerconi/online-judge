#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 1e3 + 10;
int nums[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k1, k2, val, k;
    cin >> n >> k1 >> k2;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        cin >> val;
        pq.push(abs(val - nums[i]));
    }
    k = k1 + k2;
    while(k--) {
        int cur = pq.top(); pq.pop();
        if (cur == 0) cur = 1;
        else cur--;
        pq.push(cur);
    }
    LL ret = 0;
    while (!pq.empty()) {
        LL cur = pq.top(); pq.pop();
        ret += cur * cur;
    }
    cout << ret << endl;
    return 0;
}