#include <iostream>
#include <algorithm>
using namespace std;
typedef long double LD;

struct Circle{
    LD r, x, y;
    int id;
    bool operator< (const Circle & oth) const {
        return r > oth.r;
    }
};

const int MAXN = 40000 + 10;
Circle data[MAXN];
int ret[MAXN];

bool checkin(int i, int j) {
    LD dist = (data[i].x - data[j].x) * (data[i].x - data[j].x);
    dist += (data[i].y - data[j].y) * (data[i].y - data[j].y);
    if (dist < data[i].r * data[i].r) return true;
    return false;
}
int main() {
//    freopen("../test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    LD r, x, y;
    for (int i = 0; i < n; i++) {
        cin >> r >> x >> y;
        data[i].id = i+1;
        data[i].x = x;
        data[i].y = y;
        data[i].r = r;
    }
    sort(data, data+n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        bool in = false;
        for (int j = 0; j < tot; j++) {
            int idx = ret[j];
            if (checkin(idx, i)) {
                in = true;
                break;
            }
        }
        if (!in) ret[tot++] = i;
    }
    for (int i = 0; i < tot; i++) {
        ret[i] = data[ret[i]].id;
    }
    sort(ret, ret+tot);
    cout << tot << endl;
    for (int i = 0; i < tot; i++) {
        cout << ret[i];
        if (i+1 == tot) cout << endl;
        else cout << ' ';
    }

    return 0;
}