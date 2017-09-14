#include <iostream>
#include <algorithm>
#include <vector>
typedef long long LL;
using namespace std;
const int MAXN = 2000 + 10;
int n, m;
struct Data{
    LL val;
    int id;
};

Data a[MAXN], b[MAXN], a2[MAXN*MAXN], b2[MAXN*MAXN];
struct P{
    int a,b;


};
P pa[MAXN*MAXN], pb[MAXN*MAXN];

bool cmp(Data const & a, Data const & b) {
    return a.val < b.val;
}

int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d", &n);
    LL sa = 0, sb = 0;
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i].val);
        sa = sa + a[i].val;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%I64d", &b[i].val);
        sb = sb + b[i].val;
        b[i].id = i;
    }
    int n2 = 0, m2 = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            a2[n2++].val = a[i].val + a[j].val;
            pa[n2-1].a = i;
            pa[n2-1].b = j;
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < i; j++) {
            b2[m2++].val = b[i].val + b[j].val;
            b2[m2-1].id = m2-1;
            pb[m2-1].a = i;
            pb[m2-1].b = j;
        }
    }
    sort(b, b+m, cmp);
    sort(b2, b2+m2,cmp);
    LL ret = abs(sa - sb);
    vector<int> index(4, -1);
    for (int i = 0; i < n; i++) {
        LL target = sb + 2*a[i].val - sa;
        if (target % 2 == 1) target++;
        target /= 2;
        Data t;
        t.val = target;
        auto p = lower_bound(b, b+m, t, cmp);
        if (p-b < m) {
            if (ret > abs(sb - 2*(p->val) + 2*a[i].val - sa)) {
                ret = abs(sb - 2*(p->val) + 2*a[i].val - sa);
                index[0] = i;
                index[1] = p->id;
            }
        }
        p--;
        if (p-b >= 0) {
            if (ret > abs(sb - 2*(p->val) + 2*a[i].val - sa)) {
                ret = abs(sb - 2*(p->val) + 2*a[i].val - sa);
                index[0] = i;
                index[1] = p->id;
            }
        }
    }
    for (int i = 0; i < n2; i++) {
        LL target = sb + 2*a2[i].val - sa;
        if (target % 2 == 1) target++;
        target /= 2;
        Data t;
        t.val = target;
        auto p = lower_bound(b2, b2+m2, t, cmp);
        if (p-b2 < m2) {
            if (ret > abs(sb - 2*(p->val) + 2*a2[i].val - sa)) {
                ret = abs(sb - 2*(p->val) + 2*a2[i].val - sa);
                index[0] = pa[i].a;
                index[1] = pa[i].b;
                index[2] = pb[p->id].a;
                index[3] = pb[p->id].b;
            }
        }
        p--;
        if (p-b2 >= 0) {
            if (ret > abs(sb - 2*(p->val) + 2*a2[i].val - sa)) {
                ret = abs(sb - 2*(p->val) + 2*a2[i].val - sa);
                index[0] = pa[i].a;
                index[1] = pa[i].b;
                index[2] = pb[p->id].a;
                index[3] = pb[p->id].b;
            }
        }
    }
    cout << ret << endl;
    if (index[3] != -1) {
        cout << 2 << endl;
        cout << index[0]+1 << ' ' << index[2]+1 << endl;
        cout << index[1]+1 << ' ' << index[3]+1 << endl;
        return 0;
    }
    if (index[1] != -1) {
        cout << 1 << endl;
        cout << index[0]+1 << ' ' << index[1]+1 << endl;
        return 0;
    }
    cout << 0 << endl;
    return 0;



}