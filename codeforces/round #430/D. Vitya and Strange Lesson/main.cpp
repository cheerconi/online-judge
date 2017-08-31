#include <iostream>
const int POS = 21;
int tree[(1<<(POS+2)) + 10];
int bias[POS];
inline int get(int num, int i) {
    if((num&(1<<i)) == 0) return 0;
    return 1;
}
void add(int num) {
    int cur = 1;
    for (int i = POS-1; i >= 0; i--) {
        int tmp = get(num, i);
        if (tmp == 1) cur = cur*2 + 1;
        else cur = cur * 2;
        tree[cur]++;
    }

}
void modify(int num){
    for (int i = POS-1; i >= 0; i--) {
        int tmp = get(num, i);
        if (tmp == 1) bias[i] = 1 - bias[i];
    }
}
int find() {
    int cur = 1;
    int ret = 0;
    for (int i = POS-1; i >= 0; i--) {
        if (tree[cur*2+bias[i]] < (1<<i)) {
            cur = cur*2+bias[i];
        }
        else {
            cur = cur*2 + 1 - bias[i];
            ret = ret | (1<<i);
        }
    }
    return ret;
}


int main() {
    freopen("test.txt", "r", stdin);
    int n, m, num;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        add(num);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &num);
        modify(num);
        printf("%d\n", find());

    }

    return 0;
}