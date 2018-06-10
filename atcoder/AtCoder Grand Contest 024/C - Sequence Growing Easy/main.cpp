#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
const int MAXN = 2e5 + 10;
LL nums[MAXN];

LL solve(int n) {
    if (nums[0] != 0) return -1;
    LL ret = 0;
    map<LL, LL> table;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) continue;
        LL pos = i - nums[i];
        if (pos < 0) return -1;
        if (nums[i-1]+1 < nums[i]) return -1;
        if (table.find(pos) == table.end()) {
            table[pos] = pos;
        }
        ret += i - table[pos];
        table[pos] = i;
    }
    return ret;

}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << solve(n) << endl;



    return 0;
}