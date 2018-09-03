#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
int nums[MAXN];

bool check (int ret, int num) {
    if (num >= ret) return true;
    for (int i = 17; i >= 0; i--) {
        int a = ret & (1<<i);
        int b = num & (1<<i);
        if (b != 0) return true;
        if (a != 0 && b == 0) return false;
    }
    return true;
}

int main() {
    int n, num;
    cin >> n;
    map<int, LL> table;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        table[num]++;
    }
    n = table.size();
    auto it = table.begin();
    for (int i = n-1; i >= 0; i--) {
        nums[i] = it->first;
        it++;
    }
    int ret = 0;
    LL cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!check(ret, nums[i])) break;
        for (int j = i+1; j < n; j++) {
            if (ret < (nums[i]|nums[j])) {
                ret = nums[i]|nums[j];
                cnt = table[nums[i]]*table[nums[j]];
            }
            else if (ret == (nums[i]|nums[j])) cnt += table[nums[i]]*table[nums[j]];
        }
    }
    if (table[ret] >= 2) {
        cnt += table[ret]*(table[ret]-1) / 2;
    }
    if(table.rbegin()->first > ret && table.rbegin()->second >= 2) {
        ret = table.rbegin()->first;
        cnt = (table.rbegin()->second-1) * table.rbegin()->second / 2;
    }
    cout << ret << ' ' << cnt << endl;
    return 0;
}