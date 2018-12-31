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

void done(const set<char>& cands, string& ret) {
    int j = 0;
    for (auto cand : cands) {
        while (ret[j] != ' ') j++;
        assert(j < ret.size());
        ret[j] = cand;
    }
}

string cmp(const string& x, const string& s, set<char> cands, string ret, int i, int delta) {
    while (i < s.size()) {
        if (ret[s[i]-'a'] != ' ') {
            if (delta == 1 && ret[s[i]-'a'] < x[i]) return "";
            if (delta == -1 && ret[s[i]-'a'] > x[i]) return "";
            if (ret[s[i]-'a'] != x[i]) {
                done(cands, ret);
                return ret;
            }
            i++;
            continue;
        }
        for (char c = x[i]+delta; c >= 'a' && c <= 'z'; c += delta) {
            if (cands.find(c) == cands.end()) continue;
            cands.erase(c);
            ret[s[i]-'a'] = c;
            done(cands, ret);
            return ret;
        }
        if (cands.find(x[i]) == cands.end()) return "";
        cands.erase(x[i]);
        ret[s[i]-'a'] = x[i];
        i++;
    }
    done(cands, ret);
    return ret;
}

string solve(int k, const string& s, const string& a, const string& b) {
    set<char> cands;
    string ret(k, ' ');
    for (int i = 0; i < k; i++) {
        cands.insert(i+'a');
    }
    int i = 0;
    for (; i < a.size() && a[i] == b[i]; i++) {
        if (ret[s[i]-'a'] == ' ' && cands.find(a[i]) != cands.end()) {
            cands.erase(a[i]);
            ret[s[i]-'a'] = a[i];
        }
        if (ret[s[i]-'a'] != a[i]) return "";
    }
    if (i == s.size()) {
        done(cands, ret);
        return ret;
    }
    if (ret[s[i]-'a'] != ' ') {
        if (ret[s[i]-'a'] > b[i] || ret[s[i]-'a'] < a[i]) return "";
    }
    for (char c = a[i]+1; c < b[i] && ret[s[i]-'a'] == ' '; c++) {
        if (cands.find(c) == cands.end()) continue;
        cands.erase(c);
        ret[s[i]-'a'] = c;
    }
    if (ret[s[i]-'a'] != ' ' && ret[s[i]-'a'] != a[i] && ret[s[i]-'a'] != b[i]) {
        done(cands, ret);
        return ret;
    }
    if (ret[s[i]-'a'] == a[i] || (cands.find(a[i]) != cands.end() && ret[s[i]-'a'] == ' ')) {
        auto tmp_cands = cands;
        auto tmp_ret = ret;
        if (ret[s[i]-'a'] == ' ') {
            tmp_ret[s[i]-'a'] = a[i];
            tmp_cands.erase(a[i]);
        }
        tmp_ret = cmp(a, s, tmp_cands, tmp_ret, i+1, 1);
        if (!tmp_ret.empty()) return tmp_ret;
    }
    if (ret[s[i]-'a'] == b[i] || (cands.find(b[i]) != cands.end() && ret[s[i]-'a'] == ' ')) {
        auto tmp_cands = cands;
        auto tmp_ret = ret;
        if (ret[s[i]-'a'] == ' ') {
            tmp_ret[s[i]-'a'] = b[i];
            tmp_cands.erase(b[i]);
        }
        tmp_ret = cmp(b, s, tmp_cands, tmp_ret, i+1, -1);
        if (!tmp_ret.empty()) return tmp_ret;
    }
    return "";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int cs; cin >> cs;
    string s, a, b;
    int k;
    while (cs--) {
        cin >> k;
        cin >> s >> a >> b;
        auto ret = solve(k, s, a, b);
        if (!ret.empty()) {
            cout << "YES\n" << ret << "\n";
        }
        else cout << "NO\n";
    }





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
