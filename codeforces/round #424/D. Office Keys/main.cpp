#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef long long LL;
const int MAXN = 1000 + 10;
const int MAXK = 2000 + 10;
const LL LLMAX = 0x7fffffffffffffff;
int person[MAXN];
int key[MAXK];

int main() {
//    freopen("test.txt", "r", stdin);
    int n, k, office;
    scanf("%d%d%d", &n, &k, &office);
    for (int i = 0; i < n; i++) scanf("%d", &person[i]);
    for (int i = 0; i < k; i++) scanf("%d", &key[i]);
    sort(person, person+n);
    sort(key, key+k);
    LL ret = LLMAX;
    for (int i = 0; i <= k-n; i++) {
        LL tmp = 0;
        for (int j = 0; j < n; j++) {
            tmp = max(tmp, abs(office - key[i+j])  + (LL)abs(key[i+j] - person[j]));
        }
        ret = min(tmp, ret);
    }
    cout << ret << endl;

    return 0;

}