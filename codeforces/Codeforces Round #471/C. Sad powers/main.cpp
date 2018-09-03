#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
typedef long double LD;
const LL MAXV = 1e18;
vector<LL> dp;
bool check(LL a, LL b) {
    LL c = a*b;
    if (c <= a || c <= b) return false;
    if (c > MAXV) return false;
    if (c % a != 0) return false;
    c /= a;
    if (c != b) return false;
    return true;
}
void make_table() {
    for (LL i = 2; i <= 1e6; i++) {
       LL tmp = i*i;
       while (check(tmp, i)){
           tmp = tmp*i;
           LL sqrt_tmp = sqrt(tmp);
           if (sqrt_tmp*sqrt_tmp == tmp) continue;
           dp.push_back(tmp);
       } 
    }
    sort(dp.begin(), dp.end());
    dp.resize(unique(dp.begin(), dp.end()) - dp.begin());
}
int main() {
    // freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    make_table();
    int q; cin >> q;
    LL a, b, c, d;
    while (q--) {
        cin >> a >> b;
        d = sqrt((LD)b);
        c = sqrt((LD)a);
        if (c*c == a) c--;
        d = d - c;
        auto it = lower_bound(dp.begin(), dp.end(), a);
        c = upper_bound(dp.begin(), dp.end(), b) - it;
        d += c;
        cout << d << '\n';
    }

}