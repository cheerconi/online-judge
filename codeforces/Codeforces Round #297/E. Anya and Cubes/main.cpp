#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 30;
unordered_map<LL, LL> table[2][MAXN];
int nums[MAXN], k;
LL s, fact[MAXN];
void solve (int i, int n, int k_cur, LL val, int id) {
    if (i == n) {
        table[id][k_cur][val] += 1;
        return;
    }
    if (k_cur < k && fact[i] != -1 && val+fact[i] <= s) {
        solve (i+1, n, k_cur+1, val+fact[i], id);
    }
    if (nums[i]+val <= s) {
        solve (i+1, n, k_cur, val+nums[i], id);
    }
    solve(i+1, n, k_cur, val, id);
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n; cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n; i++)  {
        cin >> nums[i];
        if (nums[i] <= 18) {
            fact[i] = 1;
            for (int j = nums[i]; j > 0; j--) {
                fact[i] *= j;
            }
        }
        else fact[i] = -1;
    }
    solve(0, n/2, 0, 0, 0);
    solve(n/2, n, 0, 0, 1);
    LL ret = 0;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; i+j <= k; j++) {
            for (auto it = table[0][i].begin(); it != table[0][i].end(); it++) {
                ret += (it->second) * (table[1][j][s - it->first]);
            }
        }
    }
    cout << ret << endl;
    return 0;
}