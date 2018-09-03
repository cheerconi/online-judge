#include <iostream>
#include <string>
#include <memory.h>

using namespace std;
const int MAXN = 50000 + 10;
int tree[MAXN*4];

void change(int node, int start, int end, int pos, int val) {
    if (pos > end || pos < start ) return;
    tree[node] += val;
    if (start == end) return;
    int mid = (start+end) >> 1;
    change(node*2, start, mid, pos, val);
    change(node*2+1, mid+1, end, pos, val);
}

int get(int node, int start, int end, int i, int j) {
    if (j < start || i > end) return 0;
    if (i <= start && end <= j) return tree[node];
    int mid = (start + end) >> 1;
    int cnt = 0;
    cnt += get(node*2, start, mid, i, j);
    cnt += get(node*2+1, mid+1, end, i, j);
    return cnt;
}

void build(int node, int start, int end) {
    if (start == end) {
        scanf("%d", &tree[node]);
        return;
    }
    int mid = (start+end) >> 1;
    build(node*2, start, mid);
    build(node*2+1, mid+1, end);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int main() {
//    freopen("test.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        printf("Case %d:\n", t+1);
        int N, tmp;
        cin >> N;
        build(1, 1, N);
        while (true){
            char cmd[10];
            scanf("%s", cmd);
            if (cmd[0] == 'E') break;
            int i, j;
            scanf("%d%d",&i, &j);
            if (cmd[0] == 'Q') {
                printf("%d\n", get(1, 1, N, i, j));
            }
            else if (cmd[0] == 'A') {
                change(1, 1, N, i, j);
            }
            else change(1, 1, N, i, -j);

        }


    }
}

