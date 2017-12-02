#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
const int MAXN = 1e6 + 10;
int nums[MAXN];
int main() {
    int n;
    cin >> n;
    set<int> cnt;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        cnt.insert(nums[i]);
    }
    int m = cnt.size();
    int i = 0, j = 0, ret = MAXN, cur = 0;
    map<int, int> table;
    while (j < n) {
        if (cur == m) {
            ret = min(ret, j-i);
            table[nums[i]]--;
            if (table[nums[i]] == 0) cur--;
            i++;
        }
        else {
            table[nums[j]]++;
            if (table[nums[j]] == 1) cur++;
            j++;
        }
    }
    while (i < n && cur == m) {
        ret = min(ret, j-i);
        table[nums[i]]--;
        if (table[nums[i]] == 0) cur--;
        i++;
    }
    cout << ret << endl;


    return 0;
}