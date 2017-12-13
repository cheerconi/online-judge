#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 5000 + 10;
int nums[MAXN];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    sort(nums, nums+n, greater<int>());
    vector<int> ret;
    ret.push_back(nums[0]);
    for (int i = 1; i < n; i++) {
        for (int & item : ret) {
            if (item > nums[i]) {
                item = nums[i];
                nums[i] = 0;
                break;
            }
        }
        if (nums[i] != 0) ret.push_back(nums[i]);
    }
    cout << ret.size() << endl;


    return 0;
}