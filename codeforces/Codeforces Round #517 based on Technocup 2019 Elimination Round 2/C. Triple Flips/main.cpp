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
const int MAXN = 1<<6;
const int MAXM = 1e5 + 10;
int nums[MAXM];
vector<int> dp[MAXN];

vector<vi> ops, ret, rem, cur;
int mask = (1<<6) - 1, n;
void init() {
    for (int i = 0; i < 6; i++) {
        for (int j = 1; i+2*j < 11; j++) {
            ops.push_back({i, i+j, i+2*j});
        }
    }
    for (int i = 1; i < MAXN; i++) {
        for (int j = 0; j < ops.size(); j++) {
            auto& op = ops[j];
            assert(op.size() == 3);
            int tmp = (1<<op[0]) + (1<<op[1]) + (1<<op[2]);
            tmp ^= i;
            if (tmp & mask) continue;
            dp[i].push_back(j);
        }
    }
    for (int i = 1; i < MAXN; i++) {
        if (!dp[i].empty()) continue;
        for (int j = 0; j < ops.size() && dp[i].empty(); j++) {
            for (int k = j+1; k < ops.size() && dp[i].empty(); k++) {
                int tmp = (1<<ops[j][0]) + (1<<ops[j][1]) + (1<<ops[j][2]);
                tmp ^= (1<<ops[k][0]) + (1<<ops[k][1]) + (1<<ops[k][2]);
                tmp ^= i;
                if (tmp & mask) continue;
                dp[i].push_back(j);
                dp[i].push_back(k);
            }
        }
       assert(!dp[i].empty());
    }
}

void solve(int start, int i) {
    if (i == ops.size()) {
        if (cur.size() >= rem.size()) return;
        for (int j = start; j <= n; j++) {
            if (nums[j] % 2 != 0) return;
        }
        rem = cur;
        return;
    }
    solve(start, i+1);
    cur.push_back(ops[i]);
    nums[ops[i][0]] ^= 1;
    nums[ops[i][1]] ^= 1;
    nums[ops[i][2]] ^= 1;
    solve(start, i+1);
    cur.pop_back();
    nums[ops[i][0]] ^= 1;
    nums[ops[i][1]] ^= 1;
    nums[ops[i][2]] ^= 1;

}

void brute_force(int start) {
    ops.clear();
    for (int i = start; i <= n; i++) {
        for (int j = 1; i+2*j <= n; j++) {
            ops.push_back({i, i+j, i+2*j});
        }
    }
    rem.resize(100);
    solve(start, 0);
    if (rem.size() == 100) {
        cout << "NO" << endl;
        exit(0);
    }
    for (auto& item : rem) {
        ret.push_back(item);
    }
}





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    init();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    int start = 1;
    while (n - start + 1 >= 14) {
        if (nums[start] == 0) {
            start++;
            continue;
        }
        int tmp = 0;
        for (int i = 5; i >= 0; i--) {
            tmp = (tmp<<1) + nums[i+start];
        }
        assert(tmp < MAXN);
        for (int idx : dp[tmp]) {
            assert(idx < ops.size());
            assert(ops[idx].size() == 3);
            assert(start+ops[idx][2] < MAXM);
            nums[start+ops[idx][0]] ^= 1;
            nums[start+ops[idx][1]] ^= 1;
            nums[start+ops[idx][2]] ^= 1;
            ret.push_back({start+ops[idx][0], start+ops[idx][1], start+ops[idx][2]});
        }
        start += 6;
    }
    while (n - start + 1 >= 10) {
        if (nums[start] == 0) {
            start++;
            continue;
        }
        assert(start+2 < MAXM);
        nums[start] ^= 1;
        nums[start+1] ^= 1;
        nums[start+2] ^= 1;
        ret.push_back({start, start+1, start+2});
        start++;
    }
    brute_force(start);
    cout << "YES" << endl << ret.size() << endl;
    for (auto & item : ret) {
        assert(item.size() == 3);
        cout << item[0] << ' ' << item[1] << ' ' << item[2] << endl;
    }







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
