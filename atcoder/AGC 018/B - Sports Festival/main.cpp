#include <iostream>
#include <unordered_set>
#include <memory.h>
using namespace std;
const int MAXN = 300 + 10;
int point[MAXN];
int data[MAXN][MAXN];
int vote[MAXN];
int n, m;

bool check(int k) {
    unordered_set<int> trash;
    memset(point, 0, sizeof(point));
    while (trash.size() < m) {
        memset(vote, 0, sizeof(vote));
        bool flag = true;
        for (int i = 0; i < n; i++) {
            while (trash.find(data[i][point[i]]) != trash.end()) point[i]++;
            vote[data[i][point[i]]]++;
            if (vote[data[i][point[i]]] > k) {
                trash.insert(data[i][point[i]]);
                flag = false;
                break;
            }
        }
        if (flag) return true;
    }
    return false;
}

int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &data[i][j]);
        }
    }
    int left = 1;
    int right = n;
    while (left < right) {
        int mid = (left + right) >> 1;
        if (check(mid)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    cout << left << endl;

    return 0;
}