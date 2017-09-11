#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int cnt[26];

bool solve() {
//    freopen("test.txt", "r", stdin);
    int n , k;
    scanf("%d%d", &n, &k);
    string s;
    cin >> s;
    int ret = 0;
    for (char c : s) {
        cnt[c-'a']++;
        ret = max(ret, cnt[c-'a']);
    }
    if (ret <= k) return true;
    return false;
}

int main() {
    if (solve()) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}