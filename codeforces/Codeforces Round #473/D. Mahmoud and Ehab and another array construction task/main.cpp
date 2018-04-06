#include <iostream>
#include <vector>
#include <cmath>
const int MAXN = 1500001;
using namespace std;
typedef long long LL;
int factor[MAXN];
bool used[MAXN];


void make_table() {
    int tot = sqrt(MAXN);
    for (LL i = 2; i <= tot; i++) {
        if (factor[i] != 0) continue;
        for (LL j = i*i; j < MAXN; j += i) {
            if (factor[j] == 0) factor[j] = i;
        }
    }
}

bool check (int num) {
    int tmp = num;
    while (factor[tmp] != 0) {
        if (used[factor[tmp]]) return false;
        tmp /= factor[tmp];
    }
    if (used[tmp]) return false;
    while (factor[num] != 0) {
        used[factor[num]] = true;
        num /= factor[num];
    }
    used[num] = true;
    return true;
}

void solve (int i, int num, int n) {
    for (int val = num+1; val < MAXN; val++) {
        if (check(val)) {
            cout << val;
            if (i+1 == n) cout << endl;
            else cout << ' ';
            break;
        }
    }
    i++;
    int j = 2;
    while (i < n) {
        while (factor[j] != 0 || used[j]) j++;
        cout << j;
        i++; j++;
        if (i == n) cout << endl;
        else cout << ' ';
    }
}


int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    make_table();
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        if (check (val)) {
            cout << val;
            if (i+1 ==n) cout << endl;
            else cout << ' ';
        }
        else {
            solve (i, val, n);
            break;
        }
    }
    return 0;
}