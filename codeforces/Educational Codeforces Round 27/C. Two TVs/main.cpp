#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 200000 + 10;
pii nums[MAXN];

bool cmp(pii a, pii b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

bool solve(int n) {
    int cur1 = -1, cur2 = -1;
    for (int i = 0; i < n; i++) {
        int left = nums[i].first;
        int right = nums[i].second;
        if (cur1 >= left && cur2 >= left) return false;
        if (cur1 >= left) cur2 = right;
        else  cur1 = right;
    }
    return true;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &nums[i].first, &nums[i].second);
    }
    sort(nums, nums+n, cmp);
    if (solve(n)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}