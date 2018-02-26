#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
int nums[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    string s; cin >> s;
    int a = -1e9, b = 1e9;
    for (int i = 4; i < n; i++) {
        if (s[i-4]!=s[i-3] || s[i-3]!=s[i-2] || s[i-2]!=s[i-1]) continue;
        int mi = INT_MAX, ma = INT_MIN;
        for (int j = 0; j <= 4; j++) {
            mi = min(mi, nums[i-j]);
            ma = max(ma, nums[i-j]);
        }
        if (s[i-1] == '0' && s[i] == '1') {
            a = max(a, ma+1);
        }
        if (s[i-1] == '1' && s[i] == '0') {
            b = min(b, mi-1);
        }
    }
    cout << a << ' ' << b << endl;

    return 0;
}