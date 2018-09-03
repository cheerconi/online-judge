#include <iostream>
#include <algorithm>
using namespace std;
int nums[123], cnt[123];
int main() {
//    freopen("test.txt", "r", stdin);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        nums[i]--;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (nums[j] == ((i+j)%n)) cnt[i]++;
        }
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        ret = max(ret, cnt[i]);
    }
    cout << ret << endl;

    return 0;
}