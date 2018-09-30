#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10;

LL gcd(LL a, LL b) {
    if (a == 0) return b;
    return gcd(b%a, a);
}
struct Frac{
   LL a, b;
    bool operator< (const Frac & oth) const {
        return a*oth.b < b*oth.a;
    }
    bool operator!= (const Frac & oth) const {
        return a*oth.b != b*oth.a;
    }
    Frac () {}
    Frac (LL _a, LL _b) {
        LL tmp = gcd(_a, _b);
        a = _a / tmp;
        b = _b / tmp;
    }
};
typedef pair<Frac, Frac> pff;
typedef pair<Frac, int> pfi;

pff items[MAXN];
pfi data[MAXN];
int nums[MAXN], n;
LL tree[MAXN];
int lowbit(int i) {
  return i&(-i);
}
void add (int i) {
    while (i <= n) {
        tree[i]++;
        i += lowbit(i);
    }
}
int find (int i) {
    int ret = 0;
    while (i > 0) {
        ret += tree[i];
        i -= lowbit(i);
    }
    return ret;
}
bool cmp(pff a, pff b) {
    if (a.first != b.first) return a.first < b.first;
    return b.second < a.second;
}



int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int w, x, v;
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> x >> v;
        Frac tmp1 = Frac(abs(x), abs(v+w));
        Frac tmp2 = Frac(abs(x), abs(v-w));
        items[i] = {tmp1, tmp2};
    }
    sort(items+1, items+n+1,cmp);
    for (int i = 1; i <= n; i++) {
        data[i] = {items[i].second, i};
    }
    sort(data+1, data+n+1);
    int rk = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1 || data[i].first != data[i-1].first) rk++;
        nums[data[i].second] = rk;
    }
    LL ret = 0;
    for (int i = 1; i <= n; i++) {
        ret += find(rk) - find(nums[i]-1);
        add (nums[i]);
    }
    cout << ret << endl;


}