#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <vector>
#include <set>

#define getmid start + ((end-start)>>1)
#define leftnode node<<1
#define rightnode (node<<1)|1

using namespace std;

const int MAXN = 10000000 + 10;
const int MAXQ = 10000 + 10;
const int N = 10000000;
int tree[MAXN<<2];
int ret;
bool used[MAXQ<<2];
set<int> points;
int lists[MAXQ<<2];
int ii[MAXQ];
int jj[MAXQ];

void update(int node, int start, int end, int i, int j, int val) {
    if (i > end || j < start) return;
    if (i <= start && end <= j) {
        tree[node] = val;
        return;
    }
    int mid = getmid;
    if (tree[node] != -1) {
        update(leftnode, start, mid, start, mid, tree[node]);
        update(rightnode, mid+1, end, mid+1, end, tree[node]);
    }
    update(leftnode, start, mid, i, j, val);
    update(rightnode, mid+1, end, i, j, val);
    tree[node] = -1;
    return;
}
void sum(int node, int start, int end) {
    if (tree[node]==0 || (tree[node]!=-1 && used[tree[node]])) return;
    if (tree[node] != -1) {
        ret++;
        used[tree[node]] = true;
        return;
    }
    int mid = getmid;
    sum(leftnode, start, mid);
    sum(rightnode, mid+1, end);
    return;


}
int get_pos(int i, int end) {
    int start = 0;
    int mid;
    while (start <= end) {
        mid = getmid;
        if (i == lists[mid]) return mid+1;
        if (i > lists[mid]) start = mid+1;
        else end = mid;
    }
    return start+1;

}

int main() {
//    freopen("test.txt", "r", stdin);
    int C, Q, i, j, N;
    scanf("%d", &C);
    for (int c = 0; c < C; c++) {
        points.clear();
        scanf("%d", &Q);
        for (int q = 1; q <= Q; q++) {
            scanf("%d%d", &i, &j);
            ii[q-1] = i;
            jj[q-1] = j;
            points.insert(i);
            points.insert(i+1);
            points.insert(j);
            points.insert(j+1);
        }
        N = 0;
        for (set<int>::iterator it = points.begin(); it != points.end(); it++) {
            lists[N++] = *it;
        }
        memset(tree, 0, sizeof(int)*(N+1));
        for (int q = 1; q <= Q; q++) {
            i = get_pos(ii[q-1], N);
            j = get_pos(jj[q-1], N);
            update(1, 1, N, i, j, q);
        }
        ret = 0;
        memset(used, false, sizeof(used));
        sum(1, 1, N);
        printf("%d\n", ret);

    }

    return 0;
}