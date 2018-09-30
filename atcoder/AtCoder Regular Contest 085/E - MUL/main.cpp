#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
using namespace std;
int smash[110];
int nums[110];
int n;
LL ret = 0;

void dfs(int i, LL cur) {
    if (i == n+1) {
        ret = max(ret, cur);
        return;
    }
    if (smash[i] > 0) {
        dfs(i+1, cur);
        return;
    }
    dfs (i+1, cur+nums[i]);
    if (nums[i] >= 0) return;
    for (int j = i; j <= n; j += i) smash[j]++;
    dfs(i+1, cur);
    for (int j = i; j <= n; j += i) smash[j]--;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> nums[i];
    dfs(1, 0);
    cout << ret << endl;
}