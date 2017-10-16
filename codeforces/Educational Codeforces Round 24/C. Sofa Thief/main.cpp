#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
int lef[MAXN];
int righ[MAXN];
int top[MAXN];
int bottom[MAXN];
int x1[MAXN];
int x2[MAXN];
int y1[MAXN];
int y2[MAXN];

bool check(int a, int b, int c, int d, int i) {
    if (x1[i] == x2[i]) {
        if (lef[x1[i]]!=a  || righ[x1[i]]!= b) return false;
    }
    else {
        if (lef[max(x1[i], x2[i])]!= a+1 || righ[min(x1[i], x2[i])]!= b+1) return false;
    }
    if (y1[i] == y2[i]) {
        if (top[y1[i]]!=c || bottom[y1[i]]!= d) return false;
    }
    else {
        if (top[max(y1[i], y2[i])]!= c+1 || bottom[min(y1[i],y2[i])]!=d+1) return false;
    }
    return true;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int d;
    scanf("%d", &d);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < d; i++) {
        scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);

        if (x1[i] != x2[i]) lef[max(x1[i],x2[i])]++;
        else lef[x1[i]+1]++;

        if (x1[i] != x2[i]) righ[min(x1[i],x2[i])]++;
        else righ[x1[i]-1]++;

        if (y1[i] != y2[i]) top[max(y1[i], y2[i])]++;
        else top[y1[i]+1]++;

        if (y1[i] != y2[i]) bottom[min(y1[i], y2[i])]++;
        else bottom[y1[i]-1]++;
    }
    for (int i = 1; i <= n; i++) {
        lef[i] += lef[i-1];
        righ[n-i+1] += righ[n-i+2];
    }
    for (int i = 1; i <= m; i++) {
        top[i] += top[i-1];
        bottom[m-i+1] += bottom[m-i+2];
    }
    int q, w, e,r;
    scanf("%d%d%d%d", &q, &w, &e, &r);

    for (int i = 0; i < d; i++) {
        if (check(q, w, e, r, i)) {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}