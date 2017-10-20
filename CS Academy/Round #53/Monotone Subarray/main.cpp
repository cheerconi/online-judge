#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
int nums[MAXN];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    int ret = 0;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (nums[i-1] >= nums[i]) cnt++;
        else {
            ret = max(ret, cnt);
            cnt = 1;
        }
    }
    ret = max(ret, cnt);
    cnt = 1;
    for (int i = 1; i < n; i++) {
        if (nums[i-1] <= nums[i]) cnt++;
        else {
            ret = max(ret, cnt);
            cnt = 1;
        }
    }
    ret = max(ret, cnt);
    cout << ret << endl;

    return 0;
}