#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 2e5 + 10;
string s;
int cnt[26], pre[MAXN], tree[MAXN<<1], n;;
vector<int> nums;
inline int lowbit(int i) {
    return i&(-i);
}
void add (int i) {
    while (i <= n) {
        tree[i]++;
        i += lowbit(i);
    }
}
int sum (int i) {
    int ret = 0;
    while (i > 0) {
        ret += tree[i];
        i -= lowbit(i);
    }
    return ret;
}

void check() {
    for (char c : s) cnt[c-'a']++;
    int flag = 0, even = -1;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 != 0) {
            flag++;
            even = i;
        }
    }
    if (flag > 1) {
        cout << -1 << endl;
        exit(0);
    }
}
void solve() {
    memset(pre, -1, sizeof(pre));
    memset(cnt, -1, sizeof(cnt));
    for (int i = 0; i < s.size(); i++) {
        pre[i] = cnt[s[i]-'a'];
        cnt[s[i]-'a'] = i;
    }
    nums.resize(n, 0);
    for (int i = 0; i < n; i++) {
        if (i < cnt[s[i]-'a']) {
            nums[i] = n - cnt[s[i]-'a'];
            nums[cnt[s[i]-'a']] = (n + 1 + cnt[s[i]-'a']);
            cnt[s[i]-'a'] = pre[cnt[s[i]-'a']];
        }
        else if (i == cnt[s[i]-'a']) {
            nums[i] = n+1;
        }
    }
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> s;
    n = s.size();
    check();
    solve();
    LL ret = 0;
    n = 2*n + 1;
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        add (num);
        int val = (sum(n) - sum(num));
        ret += val;
    }
    cout << ret << endl;
    return 0;
}
