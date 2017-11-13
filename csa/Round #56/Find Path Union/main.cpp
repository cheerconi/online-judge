#include <iostream>
#include <set>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
typedef long long LL;

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    LL val;
    cin >> n;
    set<LL> table;
    int ret = 0;
    vector<LL> nums;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &val);
        nums.push_back(val);
    }
    sort(nums.begin(), nums.end(), greater<LL>());
    while (!nums.empty()) {
        val = nums.back();
        while (val > 1) {
            if (table.find(val) != table.end()) {
                table.erase(val);
                break;
            }
            else {
                ret++;
            }
            val /= 2;
        }
        LL tmp = nums.back();
        table.insert(tmp);
        tmp /= 2;
        table.insert(tmp);
        nums.pop_back();
    }

    cout << ret << endl;
    return 0;
}