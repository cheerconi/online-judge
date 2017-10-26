#include <iostream>
#define leftnode (node<<1)
#define rightnode ((node<<1)|1)
using namespace std;

const int MAXN = 2e5 + 10;
int tree[MAXN<<2], nums[MAXN];
int ind = 1;
int n;

void build (int node, int left, int right) {
    if (left == right) {
        scanf("%d", &nums[ind]);
        tree[node] = ind++;
        return;
    }
    int mid = (left+right) >> 1;
    build(leftnode, left, mid);
    build (rightnode, mid+1, right);
    if (nums[tree[leftnode]] > nums[tree[rightnode]]) tree[node] = tree[leftnode];
    else tree[node] = tree[rightnode];
}
void update(int node, int left, int right, int i, int val) {
    if (i > right || i < left) return;
    if (left == right) {
        nums[i] = val;
        return;
    }
    int mid = (left+right) >> 1;
    update(leftnode, left, mid, i, val);
    update(rightnode, mid+1, right, i, val);
    if (nums[tree[leftnode]] > nums[tree[rightnode]]) tree[node] = tree[leftnode];
    else tree[node] = tree[rightnode];
}
int query(int node, int left, int right, int i, int j) {
    if (right < i || j < left) return 0;
    if (i <= left && right <= j) return nums[tree[node]];
    int mid = (left+right) >> 1;
    int ret = query(leftnode, left, mid, i, j);
    ret = max(ret, query(rightnode, mid+1, right, i, j));
    return ret;
}

int find (int i, int val) {
    if (i == n) return 0;
    int left = i+1, right = n;
    while (left < right) {
        int mid = (left+right) >> 1;
        if (query(1, 1, n, left, mid) > val) {
            right = mid;
        }
        else left = mid + 1;
    }
    if (query(1, 1, n, left, left) > val) return left;
    return 0;
}



int main () {
//    freopen("test.txt", "r", stdin);
    cin >> n;
    build(1, 1, n);
    int i = 0;
    while (i = find(i, 0)) {
        printf("%d", nums[i]);
        int val = nums[i];
        update(1, 1, n, i, 0);
        while (i = find(i, val)) {
            printf(" %d", nums[i]);
            val = nums[i];
            update(1, 1, n, i, 0);
        }
        printf("\n");
    }


}
