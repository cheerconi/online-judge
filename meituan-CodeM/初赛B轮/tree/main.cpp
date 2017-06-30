#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int k = 0;
    int parents = 0;
    int childs = 0;
    bool white = true;
    TreeNode(int _k) {
        k = _k;
    }

};

int cnt = 0;

void dye(vector<TreeNode *> &nodes, int i) {
    int dis = 0;
    while (i != 0) {
        if (nodes[i]->k > dis) nodes[i]->white = false;
        dis++;
        i = nodes[i]->parents;
    }
}


void recur(unordered_set<int> &leaves, vector<TreeNode *> &nodes) {
    if (leaves.size() == 0) return;
    auto it = leaves.begin();

    if (nodes[*it]->white) {
        dye(nodes, *it);
        cnt++;
    }


    leaves.erase(it);
    if(*it != 1) nodes[nodes[*it]->parents]->childs--;
    if (*it != 1 && nodes[nodes[*it]->parents]->childs == 0) { // is not root
        leaves.insert(nodes[*it]->parents);
    }
    recur(leaves, nodes);
    return;


}

int main() {
//    freopen("test.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    vector<TreeNode *> nodes(N+1, NULL);
    for (int n = 1; n <= N; n++) {
        nodes[n] = new TreeNode(0);
    }
    int tmp;
    unordered_set<int> leaves;
    for (int n = 1; n <= N; n++) {
        leaves.insert(n);
    }
    for (int n = 2; n <= N; n++) {
        scanf("%d", &tmp);
        nodes[n]->parents = tmp;
        nodes[tmp]->childs++;
        auto it = leaves.find(tmp);
        if (it != leaves.end()) leaves.erase(it);
    }
    for (int n =1; n <= N; n++) {
        scanf("%d", &nodes[n]->k);
    }
    recur(leaves, nodes);
    cout << cnt << endl;





    return 0;
}