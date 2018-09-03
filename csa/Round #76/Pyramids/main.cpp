#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pll;
const int MAXN = 1e5 + 10;
pll nums[MAXN];

bool cmp(pll a, pll b) {
    return a.second-a.first < b.second-b.first;
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    LL a, b, c, d, e;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        nums[i] = {a, b};
    }
    sort(nums, nums+n, cmp);
    vector<pll> s;
    int i = 0;
    while (i < n) {
        if (s.empty()) {
            s.push_back(nums[i++]);
            continue;
        }
        auto cur = s.back();
        if (cur.second >= nums[i].second) {
            i++;
            continue;
        }
        if (cur.first+cur.second >= nums[i].first+nums[i].second) {
            i++;
            continue;
        }
        if (cur.second-cur.first == nums[i].second-nums[i].first && nums[i].second > cur.second) {
            s.pop_back();
            continue;
        }
        s.push_back(nums[i++]);
    }
    LL ret = 0;
    for (i = 1; i < s.size(); i++) {
        a = s[i-1].first; b = s[i-1].second;
        c = s[i].first; d = s[i].second;
        if (a > c) {
            b += a - c;
            a = c;
        }
        else if (c > a) {
            d -= c - a;
            c = a;
        }
        e = (d - b) / 2;
        a -= e; c-= e; b += e; d -= e;
        if (a < 1) {
            b -= (1-a);
            d += (1-a);
            a = c = 1;
        }
        ret += (s[i-1].first + a) * (b - s[i-1].second + 1) / 2;
        ret += (s[i].first + c) * (s[i].second - d + 1) / 2;
        if (b == d) ret -= a;
        ret -= s[i].first;
    }
    ret += s[0].first * (s[0].first - 1) / 2;
    ret += (s.back().first + 1) * s.back().first / 2;
    cout << ret << endl;
}

