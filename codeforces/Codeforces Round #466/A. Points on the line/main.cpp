#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
const int MAXN = 123;
int nums[MAXN];
int main() {
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int ret = INT_MAX;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] < nums[i] || nums[j]-nums[i] > d) cur++;
        }
        ret = min(ret, cur);
    }
    cout << ret << endl;
    return 0;
}