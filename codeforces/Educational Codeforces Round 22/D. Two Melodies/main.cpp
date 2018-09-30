#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
const int MAXN = 5000 + 10;
const int MAXM = 1e5 + 10;
int ret[MAXN][MAXN], nums[MAXN], dpmod[7], dpnum[MAXM];
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    for (int j = 1; j <= n; j++) {
        memset(dpnum, 0, sizeof(dpnum));
        memset(dpmod, 0, sizeof(dpmod));
        ret[0][j] = 1;
        for (int i = 1; i < j; i++) {
            if (abs(nums[i]-nums[j])==1 || (nums[i]-nums[j])%7==0){
                ret[0][j] = max(ret[0][j], ret[0][i]+1);

            }
            dpmod[nums[i]%7] = max(dpmod[nums[i]%7], ret[j][i]);
            dpnum[nums[i]] = max(dpnum[nums[i]], ret[j][i]);
        }

        for (int i = j+1; i <= n; i++) {
            ret[i][j] = max(ret[i][j], ret[0][j]+1);
            ret[i][j] = max(ret[i][j], dpmod[nums[i]%7]+1);
            ret[i][j] = max(ret[i][j], dpnum[nums[i]-1]+1);
            ret[i][j] = max(ret[i][j], dpnum[nums[i]+1]+1);
            dpmod[nums[i]%7] = max(dpmod[nums[i]%7], ret[i][j]);
            dpnum[nums[i]] = max(dpnum[nums[i]], ret[i][j]);
            ans = max(ans, ret[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}