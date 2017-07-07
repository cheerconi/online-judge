#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
static const int MAXN = 1000000 + 10;
struct Point{
    LL inner0;
    LL inner1;
    LL outer;
    vector<int> sons;
    vector<LL> dis;
    Point(){
        inner0 = 0;
        inner1 = 0;
        outer = 0;
    }
} gym[MAXN];

struct Cmp{
    bool operator() (pair<int,LL> a, pair<int,LL> b){
        return a.second < b.second;
    }
};

LL abs(LL a, LL b) {
    LL tmp = a - b;
    if (tmp < 0) tmp = -tmp;
    return tmp;
}

void dfs_inner(int root) {
    LL inner0 = 0;
    LL inner1 = 0;
    for (int i = 0; i < gym[root].sons.size(); i++) {
        int son = gym[root].sons[i];
        dfs_inner(son);
        LL tmp = gym[son].inner0 + gym[root].dis[i];
        if (tmp > inner0) {
            inner1 = inner0;
            inner0 = tmp;
        }
        else if (tmp > inner1) {
            inner1 = tmp;
        }
    }
    gym[root].inner0 = inner0;
    gym[root].inner1 = inner1;

}
void dfs_outer(int root) {
    for (int i = 0; i < gym[root].sons.size(); i++) {
        LL outer = 0;
        int son = gym[root].sons[i];
        LL tmp1;
        if (gym[root].inner0 == gym[root].dis[i] + gym[son].inner0) {
            tmp1 = gym[root].dis[i] + gym[root].inner1;
        }
        else tmp1 = gym[root].dis[i] + gym[root].inner0;
        LL tmp2 = gym[root].dis[i] + gym[root].outer;
        if (tmp1 > outer) outer = tmp1;
        if (tmp2 > outer) outer = tmp2;
        gym[son].outer = outer;
        dfs_outer(son);
    }

}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, dad;
    LL dis, m;
    scanf("%d%lld", &n, &m);
    for (int i = 2; i <= n; i++) {
        scanf("%d%lld", &dad, &dis);
        gym[dad].sons.push_back(i);
        gym[dad].dis.push_back(dis);
    }
    dfs_inner(1);
    dfs_outer(1);
    vector<LL> ret(n+1, 0);
    for (int i = 1; i <= n; i++) {
        LL tmp = gym[i].outer;
        if (tmp < gym[i].inner0) tmp = gym[i].inner0;
        ret[i] = tmp;
    }


    int i = 1;
    int j = 1;
    int length = 0;
    vector<int> tiny(n+2, 0);
    vector<int> big(n+2, 0);
    int t0 = 1, t1 = 1, b0 = 1, b1 = 1;
    for (; j <= n; j++) {
        while (t0 < t1 && ret[tiny[t1-1]] > ret[j]) t1--;
        while (b0 < b1 && ret[big[t1-1]] < ret[j]) b1--;
        tiny[t1++] = j;
        big[b1++] = j;
        if (abs(ret[tiny[t0]]-ret[big[b0]]) > m) {
            if (j - i > length) length = j-i;
            i = tiny[t0];
            if (i > big[b0]) i = big[b0];
            i++;
            while (t0 < t1 && tiny[t0] < i) t0++;
            while (b0 < b1 && big[b0] < i) b0++;
        }
    }
    if (length < j - i) length = j - i;


    cout << length << endl;





    return 0;
}