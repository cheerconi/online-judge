#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
const int MAXN = 1e5 + 10;
int nums[MAXN];
int n, d;
bool check() {
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) cur = max(cur, 0);
        else {
            cur += nums[i];
        }
        if (cur > d) return false;
    }
    return true;
}

int main() {
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    if (!check()) {
        cout << -1 << endl;
        return 0;
    }
    stack<int> s;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            if (cur < 0) {
                s.push(d-cur);
                cur = d;
            }
        }
        else {
            cur += nums[i];
            if (cur > d) {
                int val = s.top();
                s.pop();
                val -= (cur - d);
                cur = d;
                while (val < 0) {
                    val += s.top();
                    s.pop();
                }
                if (val != 0) s.push(val);
            }
        }
    }
    cout << s.size() << endl;

    return 0;
}