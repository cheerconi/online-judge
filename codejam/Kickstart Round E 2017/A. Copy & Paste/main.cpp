#include <iostream>
#include <string>
#include <limits.h>
using namespace std;
string s;
int ret;

void solve(int i, int now, string paste) {
    if (s.size() == i) {
        ret = min(ret, now);
        return;
    }
    solve (i+1, now+1, paste);
    if (paste.size() != 0) {
        if (s.substr(i, paste.size()) == paste) {
            solve(i+paste.size(), now+1, paste);
        }
    }
    for (int x = 0; x < i; x++) {
        for (int len = 2; x+len-1 < i; len++) {
            paste = s.substr(x, len);
            if (s.substr(i, len) == paste) {
                solve(i+len, now+2, paste);
            }
        }
    }
}

int main () {
    freopen("test.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        cin >> s;
        ret = INT_MAX;
        solve(0, 0, "");
        printf("Case #%d: %d\n", t, ret);
    }
    return 0;

}