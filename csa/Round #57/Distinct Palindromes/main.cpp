#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
const int MAXN = 1234;
const int mod = 1e9 + 7;
int ret[MAXN][MAXN];
string s;

int solve(int left, int right) {
    if (ret[left][right] != -1) return ret[left][right];
    if (right-left <= 1) {
        ret[left][right] = (right-left) + 1;
        return ret[left][right];
    }
    LL cnt = 0;
    vector<int> L(26, -1);
    vector<int> R(26, -1);
    for (int i = left; i <= right; i++) {
        if (L[s[i]-'a'] == -1) {
            cnt++;
            L[s[i]-'a'] = i;
        }
        R[s[i]-'a'] = i;
    }
    for (int i = 0; i < 26; i++) {
        if (L[i] != R[i]) {
            cnt++;
            cnt = (cnt + solve(L[i]+1, R[i]-1)) % mod;
        }
    }
    ret[left][right] = cnt;
    return cnt;
}

int main() {
//    freopen("test.txt", "r", stdin);
    memset(ret, -1, sizeof(ret));
    cin >> s;
    cout << solve(0, s.size()-1) << endl;


    return 0;
}