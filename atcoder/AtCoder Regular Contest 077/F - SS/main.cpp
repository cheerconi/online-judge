#include <iostream>
#include <string>
#include <memory.h>
#include <vector>

using namespace std;
typedef long long LL;

static const int MAXS = 100000 + 10;
LL w[MAXS][26];

LL fib(int id, LL order ,int n, int k) {
    if (order <= n) return w[order][id];
    if (order <= 2*n) return w[n][id] + w[order-n][id];
    LL f1 = w[n][id];
    LL f2 = w[n][id] + w[k][id];
    LL x1 = n;
    LL x2 = n + k;
    while (x1 + x2 < order) {
        LL tmp = f2;
        f2 = f2 + f1;
        f1 = tmp;
        tmp = x2;
        x2 = x1 + x2;
        x1 = tmp;
    }
    return f2 + fib(id, order - x2, n, k);

}


int main() {
//    freopen("test.txt", "r", stdin);
    string s;
    cin >> s;
    int n = s.size() >> 1;
    LL left, right;
    cin >> left >> right;
    memset(w, 0, sizeof(w));
    vector<int> next(n, 0);
    for (int i = 1; i < n; i++) {
        int len = next[i-1];
        while (len >= 1 && s[len] != s[i]) {
            len = next[len-1];
        }
        if (s[len] == s[i]) next[i] = len + 1;
        else next[i] = 0;
    }
    int k = n - next.back();
    for (int i = 1; i <= n; i++) {
        w[i][s[i-1]-'a']++;
        for (int j = 0; j < 26; j++) {
            w[i][j] += w[i-1][j];
        }
    }
    for (int i = 0; i < 26; i++) {
        cout << fib(i, right, n, k) - fib(i, left-1, n, k);
        if (i != 25) cout << ' ';
    }
    cout << endl;


    return 0;
}