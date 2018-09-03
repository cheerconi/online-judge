#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 400;
int nums[MAXN], n;


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int ret = 360;
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[(i+j) % n];
            ret = min(ret, abs(360-2*sum));
        }
    }
    cout << ret << endl;


    return 0;
}