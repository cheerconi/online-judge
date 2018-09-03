#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

static const int MAXN = 30;
int graph[MAXN][MAXN][MAXN];

struct Pos{
    int x;
    int y;
    int h;
    Pos(int _h, int _x, int _y) {
        x = _x;
        y = _y;
        h = _h;
    }
    bool operator== (Pos const & p) const {
        if (p.x != x) return false;
        if (p.y != y) return false;
        if (p.h != h) return false;
        return true;
    }
    vector<Pos> move()  const{
        vector<Pos> ret;
        ret.push_back(Pos(h+1,x,y));
        ret.push_back(Pos(h-1,x,y));
        ret.push_back(Pos(h,x+1,y));
        ret.push_back(Pos(h,x-1,y));
        ret.push_back(Pos(h,x,y+1));
        ret.push_back(Pos(h,x,y-1));
        return ret;
    }
    void print() const {
        printf("Pos(%d, %d, %d)\n", h, x, y);
    }
};

struct Cmp{
    bool operator() (Pos const & p1, Pos const & p2) const {
        if (p1.h != p2.h) return p1.h < p2.h;
        if (p1.x != p2.x) return p1.x < p2.x;
        return p1.y  < p2.y;
    }

};

int bfs(queue<Pos> & q, set<Pos, Cmp> & can, Pos const & goal) {
    int cnt = 0;
    while (q.size() != 0) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Pos now = q.front();
            q.pop();
            vector<Pos> next = now.move();
            for (int j = 0; j < next.size(); j++) {
                set<Pos, Cmp>::iterator it;
                it = can.find(next[j]);
                if (it != can.end()) {
                    if (goal == next[j]) {
                        return cnt+1;
                    }
                    can.erase(it);
                    q.push(next[j]);
                }
            }
        }
        cnt++;
    }
    return -1;

}

int main() {
//    freopen("test.txt", "r", stdin);
    int L, R, C;
    while (scanf("%d%d%d", &L, &R, &C) && L != 0) {
        queue<Pos> q;
        char c;
        Pos goal = Pos(0, 0, 0);
        set<Pos, Cmp> can;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                getchar();
                for (int k = 0; k < C; k++) {
                    scanf("%c", &c);
                    if (c == 'S') q.push(Pos(i, j, k));
                    else if (c == 'E') goal = Pos(i, j, k);
                    else if (c == '.') can.insert(Pos(i, j, k));
                }
            }
            getchar();
        }
        can.insert(goal);
        int cnt = bfs(q, can, goal);
        if (cnt == -1) cout << "Trapped!\n";
        else printf("Escaped in %d minute(s).\n", cnt);

    }





    return 0;
}