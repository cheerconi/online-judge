#include <iostream>
#include <string>
const int MAXN = 1e6 + 10;
bool none[MAXN];
int a[MAXN], b[MAXN];
int cand[2][MAXN], gg[MAXN];
using namespace std;
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    string s; cin >> s;
    int n = s.size();
    s = "0" + s;
    int tot_cur = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = i-1;
        b[i] = i+1;
        cand[0][tot_cur++] = i;
    }
    b[n] = 0;
    int cnt = 0, cur = 0;
    while (tot_cur > 0) {
        int tot_nxt = 0, gg_sz = 0;
        bool flag = false;
        for (int k = 0; k < tot_cur; k++) {
            int i = cand[cur][k];
            if (none[i]) continue;
            if (a[i] != 0 && s[a[i]] != s[i]) {
                if (gg_sz == 0 || gg[gg_sz-1] <  a[i]) gg[gg_sz++] = a[i];
                if (gg_sz == 0 || gg[gg_sz-1] <  i) gg[gg_sz++] = i;
            }
            if (b[i] != 0 && s[b[i]] != s[i]) {
                if (gg_sz == 0 || gg[gg_sz-1] < i) gg[gg_sz++] = i;
                if (gg_sz == 0 || gg[gg_sz-1] < b[i]) gg[gg_sz++] = b[i];
            }
        }
        for (int k = 0; k < gg_sz; k++) {
            int i = gg[k];
            none[i] = true;
            flag = true;
            if (a[i] != 0) {
                if (tot_nxt == 0 || cand[1-cur][tot_nxt-1]  < a[i]) cand[1-cur][tot_nxt++] = a[i];
                b[a[i]] = b[i];
            }
            if (b[i] != 0) {
                if (tot_nxt == 0 || cand[1-cur][tot_nxt-1] < b[i]) cand[1-cur][tot_nxt++] = b[i];
                a[b[i]] = a[i];
            }
        }
        if (flag) cnt++;
        cur = 1 - cur;
        swap(tot_cur, tot_nxt);
    }
    cout << cnt << endl;
    return 0;
}