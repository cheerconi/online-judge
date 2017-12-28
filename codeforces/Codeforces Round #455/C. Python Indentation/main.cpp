#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 5000 + 10;
const int mod = 1e9 + 7;
char s[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%c", &s[i]);
    }
    vector<LL> cur(n+1, 0);
    cur[0] = 1;
    for (int i = n-1; i >= 0; i--) {
        vector<LL> tmp(n+1, 0);
        if (s[i] == 'f') {
            for (int i = 1; i <= n; i++) {
                tmp[1] = (tmp[1] + cur[i]) % mod;
                if(i+1 <= n) tmp[i+1] =  (tmp[i+1] - cur[i] + mod) % mod;
            }
            for (int i = 1; i <= n; i++) tmp[i] = (tmp[i-1] + tmp[i]) % mod;
        }
        else {
            for (int i = 0; i < n; i++) {
                tmp[i+1] = cur[i];
            }
        }
        swap(tmp, cur);
    }
    LL ret = 0;
    for (int i = 0; i <= n; i++) ret = (cur[i] + ret) % mod;
    cout << ret << endl;

    return 0;
}