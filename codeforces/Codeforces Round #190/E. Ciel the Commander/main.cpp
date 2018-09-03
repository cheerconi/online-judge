#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1e5 + 10;
vector<int> edges[MAXN];
char rk[MAXN];
int sz[MAXN];
void count(int root, int par) {
    sz[root] = 1;
    for (int son : edges[root]) {
        if (son == par || rk[son] != 0) continue;
        count(son, root);
        sz[root] += sz[son];
    }
}
void solve (int root, char c) {
    count(root, 0);
    int tot = sz[root];
    if (tot == 1) {
        rk[root] = c;
        return;
    }
    bool done = false;
    int pre = 0;
    while (!done) {
        done = true;
        for (int son : edges[root]) {
            if (rk[son] != 0 || son == pre) continue;
            if (sz[son]*2 > tot) {
                done = false;
                pre = root;
                root = son;
                break;
            }
        }
    }
    rk[root] = c;
    for (int son : edges[root]) {
        if (rk[son] != 0) continue;
        solve(son, c+1);
    }
}


int read_int(){
    int wyn = 0,pom;
    pom = getchar();
    while(pom<='9' && pom>='0'){
        wyn*=10;
        wyn+=pom-'0';
        pom = getchar();
    }
    return wyn;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, a, b;
    n = read_int();
    for (int i = 1; i < n; i++) {
        a = read_int();
        b = read_int();
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    solve(1, 'A');
    for (int i = 1; i <= n; i++) {
        printf("%c", rk[i]);
        if (i == n) printf("\n");
        else printf(" ");
    }


    return 0;
}