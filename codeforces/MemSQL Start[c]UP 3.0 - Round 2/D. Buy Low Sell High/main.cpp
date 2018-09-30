#include <iostream>
#include <set>
using namespace std;
typedef long long LL;
const int MAXN = 3e5 + 10;
int nums[MAXN];
LL ret;
multiset<int> unused, start;
void add(int i) {
    int tmp = *unused.rbegin();
    ret += tmp - nums[i];
    start.insert(nums[i]);
    unused.erase(--unused.end());
}
void change(int i) {
    int tmp = *start.rbegin();
    ret += tmp - nums[i];
    start.erase(--start.end());
    start.insert(nums[i]);
    unused.insert(tmp);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for (int i = n-1; i >= 0; i--) {
        if (unused.empty() || *unused.rbegin() <= nums[i]) {
            if (!start.empty() && *start.rbegin() > nums[i]) {
                change(i);
            }
            else unused.insert(nums[i]);
            continue;
        }
        if (start.empty() || *start.rbegin() <= nums[i]) {
            if (!unused.empty() && *unused.rbegin() > nums[i]) {
                add(i);
            }
            else unused.insert(nums[i]);
            continue;
        }
        if (*start.rbegin() > *unused.rbegin()) change(i);
        else add(i);
    }
    cout << ret << endl;
}
