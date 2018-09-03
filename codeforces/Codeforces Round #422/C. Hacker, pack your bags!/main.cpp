#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;
typedef long long LL;


static const int MAXD = 200000 + 10;

LL minicost[MAXD];

struct Vouch{
    int start;
    int end;
    int dur;
    LL cost;
    Vouch(int _start, int _end, int _cost) {
        start = _start;
        end = _end;
        dur = end - start + 1;
        cost = _cost;
    }
};

static bool cmp1(Vouch const & v1, Vouch const & v2) {
    return v1.start < v2.start;
}

static bool cmp2(Vouch const & v1, Vouch const & v2) {
    return v1.end < v2.end;
}

int main(){
//    freopen("test.txt", "r", stdin);
    int n, x, start, end, cost;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < MAXD; i++) {
        minicost[i]= INT_MAX;
    }
    vector<Vouch> vs1, vs2;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &start, &end, &cost);
        Vouch tmp = Vouch(start, end, cost);
        vs1.push_back(tmp);
        vs2.push_back(tmp);
    }
    sort(vs1.begin(), vs1.end(), cmp1); // sort by start
    sort(vs2.begin(), vs2.end(), cmp2); // sort by end

    int j = n-1;
    LL cnt = INT_MAX;
    for (int i = n-1; i >= 0; i--) {
        Vouch tmp = vs2[i];
        while (j >= 0 && vs1[j].start > tmp.end) {
            minicost[vs1[j].dur] = min (minicost[vs1[j].dur], vs1[j].cost);
            j--;
        }
        if(x-tmp.dur > 0) cnt = min (tmp.cost+minicost[x - tmp.dur], cnt);
    }
    if (cnt == INT_MAX) cout << -1 << endl;
    else cout << cnt << endl;


}