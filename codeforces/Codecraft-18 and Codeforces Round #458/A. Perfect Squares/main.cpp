#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN = 1234;
int nums[MAXN];

bool find (int num) {
    if (num < 0) return true;
    int a = sqrt(num);
    if (a*a != num) return true;
    return false;
}
int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums, nums+n, greater<int>());
    for (int i = 0; i < n; i++) {
        if (find(nums[i])) {
            cout << nums[i] << endl;
            return 0;
        }
    }
    return 0;
}