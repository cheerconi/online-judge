#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN = 100000 + 10;
const long double eps = 1e-10;
int cnt[MAXN];

int check(int n) {
    for (int i = 0; i+2 < n; i++) {
        if (cnt[i] == 0) continue;
        if (cnt[i] >= 2 && cnt[i+1] >= 0) return 1;
        if (cnt[i] <= -2 && cnt[i+1] <= 0) return -1;
        cnt[i+1] += cnt[i];
        cnt[i+2] += cnt[i];
    }
    long double p = sqrt((long double) 5) + 1;
    p /= 2;
    long double ret = p * cnt[n-2] + cnt[n-1];
    if (fabs(ret) < eps) return 0;
    if (ret > 0) return 1;
    return -1;
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    int n = max(s1.size(), s2.size());
    if (s1.size() < n) s1 = string(n-s1.size(), '0') + s1;
    if (s2.size() < n) s2 = string(n-s2.size(), '0') + s2;
    for (int i = 0; i < n; i++) {
        int a = s1[i] - '0';
        int b = s2[i] - '0';
        cnt[i] = a - b;
    }
    int ret = check(n);
    if (ret == 0) cout << "=" << endl;
    else if (ret == -1) cout << "<" << endl;
    else cout << ">" << endl;

    return 0;
}