#include <iostream>
#include <string>
using namespace std;
const int MAXN = 1e5 + 10;
int nums[MAXN];
string s[MAXN];
int dfs(int i, int j, int pre, int cur) {
    if (s[i].size() > s[i-1].size()) {
        if (s[i][0] == '?') s[i][0] = '1';
        for (char & c : s[i]) {
            if (c == '?') c = '0';
        }
        return stoi(s[i]);
    }
    if (cur < pre) return -1;
    if (j == s[i].size()) {
        if (cur > pre) return cur;
        return -1;
    }
    pre = pre*10 + s[i-1][j] - '0';
    if (s[i][j] != '?') return dfs(i, j+1, pre, cur*10+s[i][j]-'0');
    int a = s[i-1][j] - '0';
    if (pre/10 != cur) a = 0;
    int tmp = dfs(i, j+1, pre, cur*10+a);
    if (tmp != -1) return tmp;
    a++;
    if (a <= 9) {
        return dfs(i, j+1, pre, cur*10+a);
    }
    return -1;

}
bool solve(int n) {
    for (int i = 1; i <= n; i++) {
        if (s[i][0] == '0') return false;
        if (s[i-1].size() > s[i].size()) return false;
        if (s[i-1].size() == s[i].size()) {
            for (int j = 0; j < s[i].size() && s[i][j] != '?'; j++) {
                if (s[i-1][j] > s[i][j]) return false;
                if (s[i][j] > s[i-1][j]) break;
            }
        }
        nums[i] = dfs(i, 0, 0, 0);
        if (nums[i] == -1) return false;
        s[i] = to_string(nums[i]);
    }
    return true;
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    s[0] = "0";
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    if (solve(n)) {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
            cout << nums[i] << "\n";
        }
    }
    else cout << "NO\n";

    return 0;
}