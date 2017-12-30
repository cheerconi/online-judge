#include <iostream>
using namespace std;
const int MAXN = 1500 + 10;
int tree[MAXN], n;
char s[2][10] = {"even", "odd"};
inline int lowbit(int i) {
    return i&(-i);
}
void add (int i) {
    while (i <= n) {
        tree[i] += 1;
        i += lowbit(i);
    }
}
int sum(int i) {
    int ret = 0;
    while (i > 0) {
        ret += tree[i];
        i -= lowbit(i);
    }
    return ret;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int val, ret = 0, q, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        add (val);
        ret += sum(n) - sum(val);
    }
    ret %= 2;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &a, &b);
        a = b - a + 1;
        a = (a-1)*a / 2;
        ret = (ret + a) % 2;
        cout << s[ret] << endl;
    }

}

