#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
struct Item{
    int id, val;
    bool operator< (const Item &  oth) const {
        return val > oth.val;
    }
};
const int MAXN = 2e5 + 10;
Item items[MAXN];
LL nums[MAXN], tree[MAXN], n;

int lowbit(int i) {
    return i&(-i);
}
void add (int i) {
    while (i <= n) {
        tree[i]++;
        i += lowbit(i);
    }
}
LL query(int i) {
    LL ret = 0;
    while (i > 0) {
        ret += tree[i];
        i -= lowbit(i);
    }
    return ret;
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        items[i].id = i;
        items[i].val = nums[i];
    }
    sort(items+1, items+n+1);
    int i = 1;
    LL ret = 0;
    for (int j = n-1; j >= 1; j--) {
        if (nums[j] <= j) continue;
        while (i <= n & items[i].val >= j) {
            add (items[i++].id);
        }
        int a = min(n, nums[j]);
        ret += query(a) - query(j);
    }
    cout << ret << endl;

    return 0;
}