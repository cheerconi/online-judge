#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>

typedef long long LL;

using namespace std;

struct town{
    int x;
    int y;
    int id;

    town(int _x, int _y, int _id) {
        x = _x;
        y = _y;
        id = _id;
    }
};

int find(vector<int> &pre, int i);
void add(vector<int> &pre, int i, int j);
vector<int> init(int n);


//初始化并查集, 每个祖先节点满足 pre[i] = i
// 输入 n 为节点个数
// 返回 pre， 每个节点都是自己的祖先
vector<int> init(int n) {
    vector<int> pre(n, 0);
    for (int i = 1; i < n; i++) pre[i] = i;
    return pre;
}

// 插入 (i,j) 的边， 即改变 pre，使得 i, j 有相同的祖先
// 输入 i,j
// 改变 pre， 无返回
void add(vector<int> &pre, int i, int j) {
    int tmpi = find(pre, i);
    int tmpj = find(pre, j);
    pre[tmpi] = tmpj;
    return;

}

// 寻找 i 的祖先， 中途会递归优化， 使得下次能够更快地查询
// 输入 pre, 需要查询的节点 i
// 返回 i 的祖先, 并会改变 pre
int find(vector<int> &pre, int i) {
    if (pre[i] == i) return i;
    int tmp = find(pre, pre[i]);
    pre[i] = tmp;
    return tmp;

}

static bool cmpx(town a, town b) {
    return a.x < b.x;
}
static bool cmpy(town a, town b) {
    return a.y < b.y;
}

int main() {
    int N;
    scanf("%d", &N);
    vector<int> pre = init(N);

    vector<town> towns(N, town(0, 0, -1));
    for (int n = 0; n < N; n++) {
        scanf("%d%d", &towns[n].x, &towns[n].y);
        towns[n].id = n;
    }
    sort(towns.begin(), towns.end(), cmpx);
    multimap<int, pair<int, int> > mapx;
    for (int n = 1; n < N; n++) {
        if (towns[n].x - towns[n-1].x == 0) {
            add(pre, n, n-1);
            continue;
        }
        mapx.insert({towns[n].x-towns[n-1].x, {towns[n].id, towns[n-1].id}});
    }

    sort(towns.begin(), towns.end(), cmpy);
    multimap<int, pair<int, int> > mapy;
    for (int n = 1; n < N; n++) {
        if (towns[n].y - towns[n-1].y == 0) {
            add(pre, n, n-1);
            continue;
        }
        mapy.insert({towns[n].y-towns[n-1].y, {towns[n].id, towns[n-1].id}});
    }
    LL cost = 0;
    int dx, dy, id1,id2;
    while (mapy.size()>0 && mapx.size() > 0) {
        dx = (mapx.begin())->first;
        dy = (mapy.begin())->first;

        if (dx > dy) {
            id1 = mapy.begin()->second.first;
            id2 = mapy.begin()->second.second;
            if (find(pre, id1) != find(pre, id2)) {
                add(pre, id1, id2);
                cost += dy;
            }
            mapy.erase(mapy.begin());

            continue;
        }
        id1 = mapx.begin()->second.first;
        id2 = mapx.begin()->second.second;
        if (find(pre, id1) != find(pre, id2)) {
            cost +=  dx;
            add(pre, id1, id2);
        }
        mapx.erase(mapx.begin());
    }
    while (mapy.size() > 0) {
        dx = mapx.begin()->first;
        id1 = mapy.begin()->second.first;
        id2 = mapy.begin()->second.second;
        if (find(pre, id1) != find(pre, id2)) {
            add(pre, id1, id2);
            cost += dx;
        }
        mapy.erase(mapy.begin());
    }
    while (mapx.size() > 0) {
        dx = mapx.begin()->first;
        id1 = mapx.begin()->second.first;
        id2 = mapx.begin()->second.second;
        if (find(pre, id1) != find(pre, id2)) {
            add(pre, id1, id2);
            cost += dx;
        }
        mapx.erase(mapx.begin());
    }
    cout << cost << endl;




    return 0;
}