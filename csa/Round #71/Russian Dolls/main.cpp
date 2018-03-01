#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
map<int, int> table;
int ma, ret;

void bruteforce() {
    int cur = table.rbegin()->second;
    int val = table.rbegin()->first;
    int cnt = 0;
    while (cur < ma) {
        val--;
        cnt += cur;
        cur = cur*2 + table[val];
    }
    ret = cnt;
}
void solve () {
    int cur = table.rbegin()->second;
    int val = table.rbegin()->first;
    int cnt = 0;
    while (cnt < ret) {
        int tmp = cnt;
        int done = val;
        for (auto it = table.rbegin(); it != table.rend() && tmp < ret; it++) {
            if (it->first >= done || it->second <= cur) continue;
            if (it->first == 1) {
                tmp = 100;
                break;
            }
            tmp += (it->second - cur);
            int b = (it->second - cur) * 2 + table[it->first-1];
            int v = it->first-1;
            while (b > cur && tmp < ret) {
                tmp += (b - cur);
                b = (b - cur)*2 + table[v-1];
                v--;
            }
            done = v;
        }
        ret = min(tmp ,ret);
        val--;
        cnt += cur;
        cur = cur * 2 + table[val];
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        table[val]++;
        ma = max(ma, table[val]);
    }
    int last = table.rbegin()->second;
    if (last >= ma) {
        cout << 0 << endl;
        return 0;
    }
    bruteforce();
    solve();
    cout << ret << endl;



    return 0;
}