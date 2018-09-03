#include <iostream>
#include <unordered_map>
using namespace std;
const int MAXN = 100000 + 10;
int nums[MAXN];
int main() {
    int n, k, m;
    cin >> n >> k >> m;
    unordered_map<int, int> table;
    int debris = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        table[nums[i]%m]++;
        if (table[nums[i]%m] >= k) {
            debris = nums[i]%m;
            break;
        }
    }
    if (debris == -1) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n && k > 0; i++) {
        if (nums[i]%m == debris) {
            printf("%d", nums[i]);
            k--;
            if (k == 0) cout << endl;
            else printf(" ");
        }
    }
    return 0;
}