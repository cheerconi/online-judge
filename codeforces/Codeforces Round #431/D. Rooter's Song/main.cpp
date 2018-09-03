#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int MAXN = 100000 + 10;
unordered_map<int, vector<int> > a[2];
struct Item{
    int type, pos, delay;
    int x, y;
};
Item data[MAXN];

bool cmp (int i, int j) {
    return data[i].pos < data[j].pos;
}

int main() {
//    freopen("test.txt", "r", stdin);
    unordered_set<int> nums;
    int n, w, h;
    cin >> n >> w >> h;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &data[i].type, &data[i].pos, &data[i].delay);
        a[data[i].type-1][data[i].pos - data[i].delay].push_back(i);
        nums.insert(data[i].pos - data[i].delay);
    }
    for (int num : nums) {
        sort(a[0][num].begin(), a[0][num].end(), cmp);
        sort(a[1][num].begin(), a[1][num].end(), cmp);
        for (int i = 0; i < a[0][num].size(); i++) {
            int n1 = a[0][num].size() - i;
            int n2 = a[1][num].size();
            int ind = a[0][num][i];
            if (n1 > n2) {
                data[ind].x = h;
                data[ind].y = data[a[0][num][i+n2]].pos;
            }
            else {
                data[ind].y = w;
                data[ind].x = data[a[1][num][n1-1]].pos;
            }
        }
        for (int i = 0; i < a[1][num].size(); i++) {
            int n1 = a[1][num].size() - i;
            int n2 = a[0][num].size();
            int ind = a[1][num][i];
            if (n1 > n2) {
                data[ind].y = w;
                data[ind].x = data[a[1][num][i+n2]].pos;
            }
            else {
                data[ind].x = h;
                data[ind].y = data[a[0][num][n1-1]].pos;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", data[i].y, data[i].x);
    }



    return 0;
}