#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
static const int MAXN = 50000 + 10;

struct Villain{
    int maxsub;
    int size;
    Villain() {
        maxsub = 0;
        size = 0;
    }
} gang[MAXN];

int pre[MAXN<<1];
int val[MAXN<<1];
int now[MAXN<<1];
int m;

void add(int a, int b) {
    val[m] = b;
    int pos = now[a];
    pre[m] = pos;
    now[a] = m;
    m++;
}

void dfs(int root, int fa) {
    int size = 1;
    int maxsub = 0;
    int pos = now[root];
    while (pos != -1) {
        int son_id = val[pos];
        pos = pre[pos];
        if (son_id == fa) continue;
        dfs(son_id, root);
        size += gang[son_id].size;
        maxsub = max(maxsub, gang[son_id].size);

    }
    gang[root].maxsub = maxsub;
    gang[root].size = size;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    m = 0;
    memset(now, -1, sizeof(now));

    for (int i = 2; i <= n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1, 0);
    int m = INT_MAX;
    vector<int> ret;
    for (int i = 1; i <= n; i++) {
        int val = max(gang[i].maxsub, n - gang[i].size);
        if (m > val) {
            ret.clear();
            ret.push_back(i);
            m = val;
        } else if (m == val) {
            ret.push_back(i);
        }
    }
    for (int i = 0; i < ret.size(); i++) {
        printf("%d", ret[i]);
        if (i == ret.size() - 1) printf("\n");
        else printf(" ");
    }

    return 0;
}