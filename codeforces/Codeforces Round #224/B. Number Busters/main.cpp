#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pll;
int main() {
//    freopen("test.txt", "r", stdin);
    LL a, b, w, x, c, d;
    cin >> a >> b >> w >> x >> c;
    if (c <= a) {
        cout << 0 << endl;
        return 0;
    }
    d = w - x;
    unordered_map<int, pll> table;
    table[b] = {c - a, 0};
    LL cnt = 0;
    while (c > a) {
        if (x <= b) {
            LL tmp = (b-x) / x;
            if ((b-x)%x != 0) tmp++;
            c -= tmp;
            cnt += tmp;
            b -= x*tmp;
            if (x == b) {
                c--;
                cnt++;
                b -= x;
            }
            if (c <= a) {
                cnt -= a - c;
                break;
            }
            auto it = table.find(b);
            if (it == table.end()) {
                table[b] = {c-a, cnt};
            }
            else {
                LL x = cnt - it->second.second;
                LL y = it->second.first - (c-a);
                LL jump = (c-a) / y;
                cnt += jump*x;
                c -= jump*y;
                table.erase(it);
            }
        }
        else {
            LL tmp = (x-b) / d;
            if ((x-b)%d != 0) tmp++;
            cnt += tmp;
            b += tmp*d;
        }
    }
    cout << cnt << endl;
    return 0;
}