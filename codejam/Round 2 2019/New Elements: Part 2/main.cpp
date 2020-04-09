#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <memory.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long double LD;
typedef long long LL;
typedef pair<LL, LL> pll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#ifdef LOCAL
#define DEBUG(x) { cerr << "# " << #x << ": " << x << endl;}
#else
#define DEBUG(x)
#endif
mt19937_64 mt(time(0));
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/

const int MAXN = 300 + 10;
LL nums[MAXN][2];
const LD eps = 1e-11;

LL gcd(LL a, LL b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(a, b%a);
}

struct  Fra{
    LL a, b;
    Fra(LL a_, LL b_): a(a_), b(b_) {
        LL tmp = gcd(a, b);
        a /= tmp;
        b /= tmp;
    }
    bool operator== (const Fra& rhs) {
        return a*rhs.b == b*rhs.a;
    }
    bool operator< (const Fra& rhs) {
        return a*rhs.b < b*rhs.a;
    }
    LD value() {
        return (LD)a / b;
    }
};

pair<Fra, Fra> check(pair<Fra, Fra> rule, int i, int j) {
    if (nums[i][0] <= nums[j][0] && nums[i][1] <= nums[j][1]) return rule;
    LL a = nums[i][0] - nums[j][0];
    LL b = nums[j][1] - nums[i][1];
    assert (a != 0 && b != 0);
    if (a > 0 && b > 0) {
        Fra tmp(a, b);
        rule.first = rule.first < tmp ? tmp : rule.first;
    } else {
        Fra tmp(-a, -b);
        rule.second = rule.second < tmp ? rule.second : tmp;
    }
    if (rule.first < rule.second) return rule;
    Fra tmp(1, 0);
    rule.first = tmp;
    return rule;
}

LL nice(LD a, LD b) {
    LD c = std::ceil(a+eps);
    LD d = std::floor(b-eps);
    if (c <= d) return c;
    return -1;
}

pll solve(pair<Fra, Fra> rule) {
    if (rule.first == Fra(1, 0)) {
        return {-1, -1};
    }
    if (rule.second == Fra(1, 0)) {
        LL a = std::ceil(rule.first.value()+eps);
        return {1, a};
    }
    LL ret = nice(rule.first.value(), rule.second.value());
    if (ret > 0) {
        return {ret, 1};
    }
    LD res = rule.second.value() - std::floor(rule.second.value());
    if (res < eps) {
        res = rule.first.value() - rule.first.value();
    }
    for (LL tot = 1; tot <= 1000000; tot++) {
        LL times = tot / res;
        ret = nice(rule.first.value()*times, rule.second.value()*times);
        if (ret > 0) return {times, ret};
        times++;
        ret = nice(rule.first.value()*times, rule.second.value()*times);
        if (ret > 0) return {times, ret};
    }
    return {-1, -1};





}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
//    freopen("../test.txt", "r", stdin);
#ifdef LOCAL

    // freopen("../output.txt", "w", stdout);
#endif
    int n;
    int T; cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> nums[i][0] >> nums[i][1];
        }
        pair<Fra, Fra> rule = make_pair(Fra(0, 1), Fra(1, 0));
        for (int i = 1; i < n; i++) {
            rule = check(rule, i-1, i);
        }
        pll ret = solve(rule);
        if (ret.first == -1) {
            cout << "Case #"<< cs << ": IMPOSSIBLE"<< endl;

        } else {
            cout << "Case #"<< cs << ": " << ret.first << ' ' << ret.second << endl;
        }




    }

/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
