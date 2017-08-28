#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string s;
bool bucket[26];

int solve() {
    if (s.size() < n) return -1;
    for (char c : s) {
        bucket[c-'a'] = true;
    }
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (bucket[i]) cnt++;
    }
    return max(0, n-cnt);


}

int main() {
//    freopen("test.txt", "r", stdin);
    cin >> s;
    scanf("%d", &n);
    int ret = solve();
    if (ret == -1) cout << "impossible" << endl;
    else cout << ret << endl;
    return 0;
}