#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
int id[300], k, res[300];
int solve (int val) {
    if (id[val] != -1) return id[val];
    int j = max(0, val-k+1);
    while (id[j] != -1) j++;
    if (res[j] != 0 && j+res[j]-1 >= val) {
        for (int i = j; i <= val; i++) {
            id[i] = id[j-1];
        }
        res[val+1] = res[j]-(val-j+1);
        return id[val];
    }
    int tmp = j;
    int cnt = k;
    while (j <= val)  {
        id[j++] = tmp;
        cnt--;
    }
    res[val+1] = cnt;
    return id[val];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, val;
    cin >> n >> k;
    memset(id, -1, sizeof(id));
    for (int i = 0; i < n; i++) {
        cin >> val;
        cout << solve(val);
        if (i+1 == n) cout << endl;
        else cout << ' ';
    }


    return 0;
}