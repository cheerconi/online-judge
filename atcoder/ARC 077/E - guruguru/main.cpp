#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long LL;


int main(){
//    freopen("test.txt", "r", stdin);
    LL n, m, pre, now;
    scanf("%lld%lld%lld", &n, &m, &pre);
    vector<LL> a(m+2, 0);
    vector<LL> b(m+2, 0);
    for (int i = 1; i < n; i++) {
        scanf("%lld", &now);
        if (now > pre) {
            b[1] += now - pre;
            b[pre + 1] -= now - pre;
            b[now + 1] += now - pre;
            a[pre+1] -= 1;
            a[now+1] += 1;
            b[pre + 1] += now + 1;
            b[now + 1] -= now + 1;
        }
        else { // now < pre
            b[now + 1] += now - pre + m;
            b[pre + 1] -= now - pre + m;
            a[1] -= 1;
            a[now + 1] += 1;
            b[1] += now + 1;
            b[now + 1] -= now + 1;
            a[pre + 1] -= 1;
            b[pre + 1] += now + m + 1;
        }
        pre = now;
    }
    LL ret = a[1] + b[1];
    for (int i = 1; i <= m; i++) {
        a[i] += a[i-1];
        b[i] += b[i-1];
        ret = min(a[i]*(LL)i + b[i], ret);
    }
    cout << ret << endl;
}