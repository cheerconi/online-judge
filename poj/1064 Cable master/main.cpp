#include <iostream>
#include <string>
using namespace std;
typedef long long LL;
const int MAXN = 10000 + 10;
LL nums[MAXN];
int n, k;

bool check(LL val) {
    if (val == 0) return true;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += nums[i] / val;
        if (cnt >= k) return true;
    }
    return false;

}
int main() {
//    freopen("test.txt", "r", stdin);
    cin >> n >> k;
    string s;
    LL cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            char c = s[j];
            if (c == '.') continue;
            nums[i] = nums[i]*10 + c-'0';
        }
        cnt += nums[i];
    }
    LL left = 0, right = cnt / k;
    while (left < right) {
        LL mid = (left+right + 1) >> 1;
        if (check(mid)) left = mid;
        else right = mid - 1;
    }
    double val;
    val = (double)left / 100;
    printf("%.2f\n", val);
    return 0;
}