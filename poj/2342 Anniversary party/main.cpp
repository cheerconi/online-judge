#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

static const int MAXN = 6000 + 10;


struct TreeNode {
    int dad = 0;
    int sum1;
    int sum0 = 0;
    int val;
    TreeNode(int val_) {
        val = val_;
        sum1 = val_;
    }
};

TreeNode *nodes[MAXN];

int ret = 0;

void recur(queue<int> &q) {
    if (q.size() == 0) return;
    int son, dad;
    unordered_set<int> tmp;
    while (q.size() > 0) {
        son = q.front();
        dad = nodes[son]->dad;
        if (dad == 0) {
            ret += max(nodes[son]->sum0, nodes[son]->sum1);
        }
        else {
            int tmp_sum0 = max(nodes[son]->sum1, nodes[son]->sum0);
            int tmp_sum1 = nodes[son]->sum0 + (nodes[dad]->val>0 ? nodes[dad]->val : 0);
            nodes[dad]->sum0 = max(nodes[dad]->sum0, tmp_sum0);
            nodes[dad]->sum1 = max(nodes[dad]->sum1, tmp_sum1);
            tmp.insert(dad);
        }
        q.pop();
    }
    for (int item : tmp) {
        q.push(item);
    }

    recur(q);
}



int main() {
    freopen("test.txt", "r", stdin);
    int N, val;
    scanf("%d", &N);
    for (int n = 1; n <= N; n++) {
        scanf("%d", &val);
        nodes[n] = new TreeNode(val);
    }
    unordered_set<int> leaves;
    for (int n = 1; n <= N; n++) leaves.insert(n);
    int son, dad;
    scanf("%d%d", &son, &dad);

    while (son != 0) {
        nodes[son]->dad = dad;
        auto it = leaves.find(dad);
        if (it != leaves.end()) leaves.erase(it);
        scanf("%d%d", &son, &dad);
    }
    queue<int> q;
    for (int leaf : leaves) q.push(leaf);

    recur(q);

    cout << ret << endl;






    return 0;
}