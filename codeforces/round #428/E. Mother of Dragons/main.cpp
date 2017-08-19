#include <iostream>
#include <algorithm>
#include <vector>
typedef long long LL;
using namespace std;
const int MAXN = 45;
int graph[MAXN][MAXN];
vector<int> group[MAXN];

double mymax(double a, double b) {
    if (a > b) return a;
    return b;
}

int solve(int n) {
    for (int i = 0; i < n; i++) {
        group[i].push_back(i);
        for (int j = 0; j < i; j++) {
            if (graph[i][j] == 0) continue;
            if (group[i].size())
            bool flag = true;
            for (int k : group[j]) {
                if (graph[i][k] == 0) {
                    flag = false;
                    break;
                }
            }


        }
    }
}


int main() {
    freopen("test.txt", "r", stdin);
    int n, k, tmp;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int card = 0;

    double ret = 0;
    if (card > 1) {
        for (int i = 2; i <= card; i++) {
            ret = mymax(ret, k*k*(i-1)/2.0/i);
        }
    }


    printf("%.8f\n", ret);
    return 0;
}