#include <iostream>
using namespace std;
const int MAXN = 2e5 + 10;
int nums[MAXN];
int ret1[MAXN], ret2[MAXN];
int n;
bool solve() {
    int par = 1, cur = 2;
    int i = 1;
    bool flag = true;
    for (; i <= n; i++) {
        if (nums[i] == 1) {
            ret1[cur] = par;
            ret2[cur] = par;
            par = cur;
            cur = cur+1;
        }
        else if (nums[i-1] == 1) {
            for (int j = 0; j < nums[i]; j++) {
                ret1[cur] = par;
                ret2[cur] = par;
                cur++;
            }
            par = cur - nums[i];
        }
        else {
            flag = false;
            break;
        }
    }
    if (flag) return true;
    int cur1 = cur, par1 = par;
    for (int k = i; k <= n; k++) {
        for (int j = 0; j < nums[k]; j++) {
            ret1[cur1++] = par1;
        }
        par1 = cur1 - nums[k];
    }
    ret2[cur] = par;
    cur++;
    par++;
    nums[i]--;
    for (int k = i; k <= n; k++) {
        for (int j = 0; j < nums[k]; j++) {
            ret2[cur++] = par;
        }
        par = cur - nums[k];
    }
    return false;


}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    int tot = 0;
    for (int i = 0; i <= n; i++) {
        cin >> nums[i];
        tot += nums[i];
    }
    if (solve()) {
        cout << "perfect" << endl;
    }
    else {
        cout << "ambiguous" << endl;
        for (int i = 1; i <= tot; i++) {
            cout << ret1[i];
            if (i == tot) cout << endl;
            else cout << ' ';
        }
        for (int i = 1; i <= tot; i++) {
            cout << ret2[i];
            if (i == tot) cout << endl;
            else cout << ' ';
        }
    }

    return 0;
}