#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 1000000 + 10;
const LL inf = (1LL<<63) - 1;
int nums[MAXN], n, a, b;
vector<int> cand;
LL ret;
void add (int val) {
    for (LL i = 2; i*i <= val; i++) {
        if (val % i == 0) {
            cand.push_back(i);
            while (val % i == 0) val /= i;
        }
    }
    if (val != 1) cand.push_back(val);
}
void solve (int val) {
    LL costa = 0, costb = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        costa += a;
        if (costb != inf) {
            costa = min(costa, costb+a);
        }
        if (costb != inf && nums[i] % val != 0) {
            if ((nums[i]+1)%val==0 || (nums[i]-1)%val==0) costb += b;
            else costb = inf;
        }
        if (nums[i]%val != 0) {
            if ((nums[i]+1)%val == 0 || (nums[i]-1)%val == 0) {
                cur += b;
            }
            else {
                cur = costa;
            }
        }
        cur = min(cur, costa);
        cur = min(cur, costb);
        if (cur >= ret) break;
    }
    ret = min(ret, cur);
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    add (nums[0]); add (nums[0]+1); add (nums[0]-1);
    add (nums[n-1]); add (nums[n-1]+1); add (nums[n-1]-1);
    sort(cand.begin(), cand.end());
    cand.resize(unique(cand.begin(), cand.end()) - cand.begin());
    ret = inf;
    for (int val : cand) {
        solve (val);
    }
    cout << ret << endl;

    return 0;
}