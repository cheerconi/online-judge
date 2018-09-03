#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
const int MAXN = 1e5 + 10;
int nums[MAXN];
int ind[MAXN];
int lft[MAXN];
int rght[MAXN];

bool cmp(int i, int j) {
    return nums[i] > nums[j];
}

int find(int dad[], int i) {
    if (nums[dad[i]] >= 0) return dad[i];
    return dad[i] = find(dad, dad[i]);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        lft[i] = i-1;
        rght[i] = i+1;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
        ind[i] = i;
    }
    sort(ind+1, ind+n+1, cmp);
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (nums[ind[i]] <= 0) continue;
        for (int j = find(lft, ind[i]); j >= 1; j = find(lft, j)) {
            if (nums[j] == nums[ind[i]]) nums[j] = -1;
            else break;
        }
        for (int j = find(rght, ind[i]); j <= n; j =find(rght, j)) {
            if (nums[j] == nums[ind[i]]) nums[j] = -1;
            else break;
        }
        nums[ind[i]] = -1;
        ret++;
    }
    cout << ret << endl;





}