#include <iostream>
#include <set>
using namespace std;
int nums[100];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    set<int> ret;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            ret.insert(nums[i]+nums[j]);
        }
    }
    cout << ret.size() << endl;
    return 0;
}