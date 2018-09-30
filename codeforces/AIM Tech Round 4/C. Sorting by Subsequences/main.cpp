#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 100000 + 10;
int nums[MAXN];
int ind[MAXN];
int n;

bool cmp(int i, int j) {
    return nums[i] < nums[j];
}
int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
        ind[i] = i;
    }
    vector<vector<int> > ret;
    sort(ind+1, ind+n+1, cmp);
    for (int i = 1; i <= n; i++) {
        if (ind[i] == -1) continue;
        ret.push_back(vector<int>());
        int j = i;
        while (ind[j]!= -1) {
            ret.back().push_back(j);
            int tmp = j;
            j = ind[j];
            ind[tmp] = -1;
        }
    }
    cout << ret.size() << endl;
    for (vector<int> item : ret) {
        cout << item.size() << ' ';
        for (int i = 0; i < item.size(); i++) {
            printf("%d", item[i]);
            if (i+1 == item.size()) printf("\n");
            else printf(" ");
        }
    }

    return 0;
}