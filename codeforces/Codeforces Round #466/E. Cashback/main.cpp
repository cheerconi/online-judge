#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10;
LL dp[MAXN];
int nums[MAXN], seq[MAXN], idx[MAXN];
struct Que{
    int a = 0, b = -1;
    int front() {
        return seq[a];
    }
    void push(int val, int i) {
        while (b >= a && seq[b] >= val) {
            b--;
        }
        seq[++b] = val;
        idx[b] = i;
    }
    void fresh(int i) {
        while (idx[a] < i) a++;
    }
};
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, c;
    cin >> n >> c;
    LL sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        sum += nums[i];
    }
    if (c == 1) {
        cout << 0 << endl;
        return 0;
    }
    Que q;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i-1];
        q.push(nums[i], i);
        q.fresh(i-c+1);
        if (i-c >= 0) {
            dp[i] = max(dp[i], dp[i-c]+q.front());
        }
    }
    cout << sum - dp[n] <<  endl;

    return 0;
}