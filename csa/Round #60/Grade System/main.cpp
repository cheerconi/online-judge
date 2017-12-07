#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n, val;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        cin >> val;
        nums.push_back(val);
    }
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i = 1; i < n-1; i++) {
        sum += nums[i];
    }
    sum = sum / (n-2);
    cout << sum << endl;
    return 0;
}