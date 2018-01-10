#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
int ret[10];
bool none[123];
string code;
void solve(int a, int b) {
    memset(ret, 0, sizeof(ret));
    memset(none, false, sizeof(none));
    string s = code.substr(a-1, b-a+1);
    int n = b - a + 1;
    char pre = '!';
    int idx = -1;
    for (int i = 0, dir = 1; i >= 0 && i < n; i += dir) {
        if (none[i]) continue;
        if (isdigit(s[i])) {
            ret[s[i]-'0']++;
            if (s[i] == '0') none[i] = true;
            else s[i]--;
        }
        else if (s[i] == '<'){
            dir = -1;
        }
        else {
            dir = 1;
        }
        if (idx != -1 && !isdigit(s[i]) && !isdigit(pre)) {
            none[idx] = true;
        }
        pre = s[i];
        idx = i;
    }
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q, a, b;
    cin >> n >> q >> code;
    while (q--) {
        cin >> a >> b;
        solve(a, b);
        for (int i = 0; i < 10; i++) {
            cout << ret[i];
            if (i+1 == 10) cout << '\n';
            else cout << ' ';
        }

    }

    return 0;
}