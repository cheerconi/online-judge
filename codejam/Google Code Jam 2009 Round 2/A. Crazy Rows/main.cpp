#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 40 + 10;
int nums[MAXN];
int n;

int find_bad() {
    for (int i = 1; i <= n; i++) {
        if (nums[i] > i) {
            return i;
        }
    }
    return -1;
}
int find_suit(int i) {
    for (int j = i+1; j <= n; j++) {
        if (nums[j] <= i) return j;
    }
}

int solve() {
    int cnt = 0;
    int pos = find_bad();
    while (pos != -1) {
        int tmp = find_suit(pos);
        for (int i = tmp; i-1 >= pos; i--) {
            swap(nums[i], nums[i-1]);
            cnt++;
        }
        pos = find_bad();
    }
    return cnt;
}


int main() {
    freopen("test.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            int cnt = 0;
            for (int j = 0; j < s.size(); j++) {
                if (s[j] == '1') cnt = j+1;
            }
            nums[i] = cnt;
        }
        printf("Case #%d: %d\n", t, solve());
    }
    return 0;
}