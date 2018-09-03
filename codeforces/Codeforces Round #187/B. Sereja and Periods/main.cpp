#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
const int MAXN = 123;
int cnt[26], jump[MAXN], nums[MAXN];
string s, sub;
int n, m;
int solve(int a) {
    int j = 0, i = a;
    while (true) {
        if (s[i%n] == sub[j]) {
            j++; i++;
            if (j == m) {
                if (i >= n && nums[a] != 0) break;
                nums[a]++;
                jump[a] = i - a;
                if (i >= n) break;
                j = 0;
            }
        }
        else i++;
    }

}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int b, d;
    cin >> b >> d;
    cin >> s >> sub;
    for (char c : s) {
        cnt[c-'a']++;
    }
    for (char c : sub) {
        if (cnt[c-'a'] == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    n = s.size(), m = sub.size();
    for (int i = 0; i < s.size(); i++) {
        solve(i);
    }
    int tot = 0, i = 0;
    while (i < n*b) {
        if (i+jump[i%n] <= n*b) {
            tot += nums[i%n];
            i += jump[i%n];
        }
        else break;
    }
    cout << tot / d << endl;


    return 0;
}