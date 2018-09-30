#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long LL;
const int MAXN = 5000 + 10;
int nums[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    LL zero = 0;
    unordered_map<int, int> table;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        table[nums[i]]++;
        if (nums[i] == 0) zero++;
    }
    LL ret = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) continue;
        for (int j = i+1; j < n; j++) {
            if (nums[j] == 0) continue;
            int val = nums[i]+nums[j];
            ret += table[val];
        }
    }
    for (auto it = table.begin(); it != table.end(); it++) {
        if (it->first == 0) continue;
        if (it->second >= 2) ret += zero * (it->second) * (it->second - 1) / 2;
    }
    ret += zero * (zero-1) * (zero-2) / 6;
    cout << ret << endl;

    return 0;
}