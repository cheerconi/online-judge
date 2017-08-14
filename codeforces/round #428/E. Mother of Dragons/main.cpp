#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;
const int MAXN = 45;
unordered_set<int> group[MAXN];
int graph[MAXN][MAXN];

double mymax(double a, double b) {
    if (a > b) return a;
    return b;
}


int main() {
    freopen("test.txt", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int card = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i || graph[i][j]==0 || group[i].find(j) != group[i].end()) continue;
            bool flag = true;
            for (int item : group[i]) {
                if (graph[j][item] == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) group[i].insert(j);
            card = max(card, (int)group[i].size() + 1);
        }
    }

    double ret = 0;
    if (card > 1) {
        for (int i = 2; i <= card; i++) {
            ret = mymax(ret, k*k*(i-1)/2.0/i);
        }
    }


    printf("%.8f\n", ret);
    return 0;
}