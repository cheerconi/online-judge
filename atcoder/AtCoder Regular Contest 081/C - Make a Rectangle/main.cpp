#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

int main() {
//    freopen("test.txt", "r", stdin);
    int n, tmp;
    scanf("%d", &n);
    map<int, int> m;
    set<int> s2;
    set<int> s4;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        m[tmp]++;
        if (m[tmp] == 2)  s2.insert(-tmp);
        if (m[tmp] == 4) s4.insert(tmp);
    }
    LL ret = 0;
    if (s2.size() >= 2) {
        ret = *s2.begin();
        ret *= *(++s2.begin());
    }
    if (!s4.empty()) {
        LL tmp = *s4.rbegin();
        tmp = tmp*tmp;
        ret = tmp > ret ? tmp : ret;
    }
    cout << ret << endl;
    return 0;
}