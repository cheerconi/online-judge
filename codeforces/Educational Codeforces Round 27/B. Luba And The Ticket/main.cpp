#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

void solve(multiset<int> & s1, multiset<int> & s2, int & cnt1, int & cnt2) {
    int delta1 = *s1.rbegin();
    int delta2 = 9 - *s2.begin();
    if (cnt1-cnt2 <= max(delta1, delta2)) {
        cnt1 = cnt2;
        return;
    }
    if (delta1 > delta2) {
        s1.insert(0);
        s1.erase(--s1.end());
        cnt1 -= delta1;
    }
    else {
        s2.insert(9);
        s2.erase(s2.begin());
        cnt2 += delta2;
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    string s;
    cin >> s;
    int cnt1 = 0, cnt2 = 0;
    multiset<int> s1, s2;
    for (int i = 0; i < 3; i++) {
        s1.insert(s[i]-'0');
        cnt1 += s[i]-'0';
    }
    for (int i = 3; i < 6; i++) {
        s2.insert(s[i]-'0');
        cnt2 += s[i]-'0';
    }
    int ret = 0, delta1, delta2;
    while (cnt1 != cnt2) {
        ret++;
        if (cnt1 > cnt2) solve(s1, s2, cnt1, cnt2);
        else solve(s2, s1, cnt2, cnt1);
    }
    cout << ret << endl;

    return 0;
}