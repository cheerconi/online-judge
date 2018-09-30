#include <iostream>
#include <string>
using namespace std;
int pos[2];
int n;

int ask(string & s) {
    printf("? ");
    cout << s << endl;
    int ret;
    scanf("%d", &ret);
    return n - ret;
}

void solve(int left, int right, int total, int other) {
    if (right < left) return;
    if (right-left+1 == total) {
        pos[1] = left;
        return;
    }
    if (total == 0) {
        pos[0] = left;
        return;
    }
    if (pos[0] != 0 && pos[1] != 0) return;
    string s(n, '1');
    int mid = (left+right) / 2;
    for (int i = mid+1; i <= right; i++) {
        s[i-1] = '0';
    }
    int ret = ask(s);
    int x = (total + ret - other - right + mid) / 2;
    int y = total - x;
    solve(left, mid, x, other+y);
    solve(mid+1, right, y, other+x);
}

int main() {
    scanf("%d", &n);
    string s(n, '1');
    int total = ask(s);
    solve(1, n, total, 0);
    cout << "! " << pos[0] << ' ' << pos[1] << endl;
    return 0;
}