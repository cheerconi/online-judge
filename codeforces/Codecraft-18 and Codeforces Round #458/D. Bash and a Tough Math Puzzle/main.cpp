#include <iostream>
#include <algorithm>
#define leftnode (node<<1)
#define rightnode ((node<<1)|1)
#define getmid ((left+right)>>1)
using namespace std;
const int MAXN = 5e5 + 10;
int st[MAXN<<2];

inline int read() {
    int ret=0; char c=getchar();
    while(c<48||c>57)c=getchar();
    while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
    return ret;
}

int gcd (int a, int b) {
    if (b > a) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}

void build (int node, int left, int right) {
    if (left == right) {
        st[node] = read();
        return;
    }
    int mid = getmid;
    build (leftnode, left, mid);
    build (rightnode, mid+1, right);
    st[node] = gcd(st[leftnode], st[rightnode]);
}
void update(int node, int left, int right, int i, int val) {
    if (i < left || i > right) return;
    if (left == right) {
        st[node] = val;
        return;
    }
    int mid = getmid;
    if (mid >= i) update (leftnode, left, mid, i, val);
    else update (rightnode, mid+1, right, i, val);
    st[node] = gcd(st[leftnode], st[rightnode]);
}
int query(int node, int left, int right, int i, int j, int guess) {
    if (right < i || j < left) return 0;
    if (st[node] % guess == 0) return 0;
    if (left == right) {
        return 1;
    }
    int mid = getmid;
    if (i <= left && right <= j) {
        if (st[leftnode] % guess != 0 && st[rightnode] % guess != 0) {
            return 2;
        }
        int tmp;
        if (st[leftnode] % guess != 0) {
            tmp = query(leftnode, left, mid, left, mid, guess);
        }
        else {
            tmp = query(rightnode, mid+1, right, mid+1, right, guess);
        }
        return tmp;
    }
    int ret = query(leftnode, left, mid, i, j, guess);
    if (ret >= 2) return ret;
    ret += query(rightnode, mid+1, right, i, j, guess);
    return ret;
}
int main() {
//    freopen("test.txt", "r", stdin);
    int n = read();
    build (1, 1, n);
    int q = read();
    int cmd, i, j, val;
    while (q--) {
        cmd = read(); i = read();
        if (cmd == 1) {
            j = read();
            val = read();
            if (query(1, 1, n, i, j, val) <= 1) {
                printf("YES\n");
            }
            else printf("NO\n");
        }
        else {
            val = read();
            update(1, 1, n, i, val);
        }
    }
    return 0;
}