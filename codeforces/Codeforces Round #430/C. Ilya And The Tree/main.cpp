#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 200000 + 10;
int nums[MAXN];
int ret[MAXN];
vector<int> edges[MAXN];
vector<int> factors;
vector<int> cnt;

int gcd(int a, int b) {
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a%b);
}

void dfs1(int root, int fa) {
    ret[root] = gcd(nums[root], ret[fa]);
    for (int son : edges[root]) {
        if (son == fa) continue;
        dfs1(son, root);
    }
}
void dfs2(int root, int fa, int deep) {
    int tmp = 0;
    for (int i = 0; i < factors.size(); i++) {
        if (nums[root] % factors[i] == 0) {
            cnt[i]++;
        }
        if (cnt[i] >= deep) tmp = factors[i];
    }
    ret[root] = max(tmp, ret[root]);
    for (int son : edges[root]) {
        if (son == fa) continue;
        dfs2(son, root, deep+1);
    }
    for (int i = 0; i < factors.size(); i++) {
        if (nums[root] % factors[i] == 0) cnt[i]--;
    }
}
void factorize(int num) {
    for (int i = 1; i*i <= num; i++) {
        if (num % i == 0) {
            factors.push_back(i);
            if (i != num/i) factors.push_back(num/i);
        }
    }
    sort(factors.begin(), factors.end());
    cnt = vector<int>(factors.size(), 0);
}
int main() {
//    freopen("test.txt", "r", stdin);
    int n, a, b;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
    }
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int p = nums[1];
    nums[1] = 0;
    dfs1(1, 0);
    nums[1] = p;
    factorize(p);
    dfs2(1, 0, 0);
    for (int i = 1; i <= n; i++) {
        printf("%d", ret[i]);
        if (i == n) cout << endl;
        else printf(" ");
    }
    return 0;
}