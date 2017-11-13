#include <iostream>
using namespace std;
const int MAXN = 1000 + 10;
int nums[MAXN];
int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for (int i = 1; i+1 < n; i++) {
        if (nums[i-1] > nums[i] && nums[i+1] > nums[i]) cnt++;
        else if (nums[i-1] < nums[i] && nums[i+1] < nums[i]) cnt++;
    }

    cout << cnt << endl;

    return 0;
}