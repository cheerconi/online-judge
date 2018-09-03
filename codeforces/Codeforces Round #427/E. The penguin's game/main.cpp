#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<bool> pos;
int n, x, y;

bool ask(vector<int> & nums, int i, int j) {
    int n = j-i+1;
    if (n == 0) return false;
    printf("? %d", n);
    for (int k = i; k <= j; k++) printf(" %d", nums[k]);
    cout << endl;
    int val;
    scanf("%d", &val);
    if (val == (x^y) || val == y) return true;
    return false;
}

int find2(vector<int> & nums) {
    int n = nums.size();
    int i = 0, j = n-1;
    while (i < j) {
        int mid = (i + j) / 2;
        if (ask(nums, i, mid)) {
            j = mid;
        }
        else {
            i = mid + 1;
        }
    }
    return nums[i];
}

void solve() {
    int i = 1;
    for (int k = 0; i < 1024; k++) {
        vector<int> nums;
        for (int j = 1; j <= n; j++) {
            if ((j & i) != 0) {
                nums.push_back(j);
            }
        }
        pos.push_back(ask(nums, 0, nums.size()-1));
        i <<= 1;
    }
    i = 1;
    for (int j = 0; !pos[j]; j++) i <<= 1;
    vector<int> nums;
    for (int j = 0; j <= n; j++) {
        if ((j&i) != 0) nums.push_back(j);
    }
    int ret1 = find2(nums);
    int ret2 = ret1;
    i = 1;
    for (int j = 0; j < pos.size(); j++) {
        if (pos[j]) {
            ret2 = ret2 ^ i;
        }
        i <<= 1;
    }
    if (ret1 > ret2) swap(ret1, ret2);
    cout << "! " << ret1 << ' ' << ret2 << endl;
}
int main() {
    scanf("%d%d%d", &n, &x, &y);
    solve();
    return 0;
}