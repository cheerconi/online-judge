#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAXN = 55;
string s[MAXN];


int solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) cin >> s[i];
    int len = s[0].size();
    int ret = INT_MAX;
    for (int start = 0; start < len; start++) {
        int now = start;
        for (int i = 1; i < n; i++) {
            if (s[i].size() != len) return -1;
            bool done = false;
            for (int j = 0; j < len; j++) {
                if (s[0][start] == s[i][j]) {
                    bool flag = true;
                    for (int cnt = 1; cnt < len; cnt++) {
                        if (s[0][(start+cnt)%len] != s[i][(j+cnt)%len]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        now += j;
                        done = true;
                        break;
                    }
                }
            }
            if (!done) return -1;
        }
        ret = min(now, ret);
    }
    return ret;
}
int main() {
//    freopen("test.txt", "r", stdin);
    cout << solve() << endl;

    return 0;
}