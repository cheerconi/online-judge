#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;


int main() {
//    freopen("test.txt", "r", stdin);
    int m, b;
    cin >> m >> b;
    LL cur = (b*(b+1)) >> 1;
    LL ret = cur;
    for (LL i = b-1; i >= 0; i--) {
        LL prelen = m*(b-i-1);
        LL prehigh = i+1;
        cur -= (prelen+1) * prehigh;
        cur -= ((1 + prelen) * prelen) >> 1;
        cur += m * ((i+1)*i)>>1;
        LL first = prelen+1;
        LL end = first + (m-1);
        cur += (i+1) * ((first+end)*m)>>1;
        ret = max(cur, ret);
        if (ret > cur) break;

    }
    cout << ret << endl;
    return 0;
}