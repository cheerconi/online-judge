#include <iostream>
#include <string>
using namespace std;
const int MAXN = 1000000 + 10;
int nxt[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    string ret(n, '0');
    for (int i = 1; i < n; i++) {
        int tmp = nxt[i-1];
        while (tmp != -1 && s[tmp] != s[i]){
            if (tmp == 0) tmp = -1;
            else tmp = nxt[tmp-1];
        }
        nxt[i] = tmp+1;
        int r = (i+1) / (i+1 - nxt[i]);
        tmp = r % k;
        bool flag = false;
        if ((i+1) % (i+1-nxt[i]) == 0) {
            if (1LL*tmp*(k+1) <= r) flag = true;
        }
        else {
            if (1LL*tmp*(k+1) < r) flag = true;
        }
        if (flag) ret[i] = '1';
    }
    if (k == 1) ret[0] = '1';
    cout << ret << endl;
    return 0;
}