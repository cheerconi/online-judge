#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
int nums[MAXN], idx[MAXN];
struct Que{
    int a = 0, b = -1;
    void push(int val, int i) {
        while (a <= b && nums[b] >= val) {
            b--;
        }
        nums[++b] = val;
        idx[b] = i;
    }
    int front() {
        return nums[a];
    }
    void clear() {
        a = 0, b = -1;
    }
    void del(int i) {
        while (idx[a] < i) a++;
    }
};

void solve (vector<int> & dp, int a, int b, int pre) {
    auto nxt = dp;
    Que q;
    for (int j = 0; j <= b; j++) {
        q.push(dp[j], j);
        q.del(j-b+a);
        nxt[j] = min(nxt[j], q.front() + 2);
    }
    q.clear();
    for (int j = b; j >= 0; j--) {
        q.push(dp[b-j], b-j);
        q.del(a-j);
        nxt[j] = min(nxt[j], q.front() + 1);
    }
    swap(nxt, dp);
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k, a, b;
    cin >> n >> k;
    vector<int> dp(2*n+1, 1e9);
    dp[0] = 0;
    int pre = 0;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        solve (dp, a, b, pre);
        pre = b;
    }
    if (dp[n] >= 1e9) {
        cout << "Hungry" << endl;
    }
    else {
        cout << "Full" << endl << dp[n] << endl;
    }
    return 0;



}