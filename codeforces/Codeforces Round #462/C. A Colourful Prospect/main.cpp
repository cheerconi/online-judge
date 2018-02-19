#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef long double LD;
const LD eps = 1e-12;
struct Point{
    LD x, y;
    Point() = default;
    Point (LD _x, LD _y):x(_x), y(_y) {}
    Point operator+ (const Point & oth) const {
        return Point(x+oth.x, y+oth.y);
    }
    Point operator- (const Point & oth) const {
        return Point(x-oth.x, y-oth.y);
    }
    Point operator* (LD num) const {
        return Point(x*num, y*num);
    }
    Point operator/ (LD num) const {
        return Point(x/num, y/num);
    }
    bool operator< (const Point & oth) const {
        if (fabs(x - oth.x) > eps) return x < oth.x;
        return y < oth.y;
    }
    bool operator== (const Point & oth) const {
        return fabs(x-oth.x)<eps && fabs(y-oth.y)<eps;
    }
    LD len() const {
        return sqrt(x*x + y*y);
    }
    Point rot90() const {
        return Point(-y, x);
    }
};
struct Circle{
    Point o;
    LD r;
    Circle() = default;
    Circle(Point _o, LD _r): o(_o), r(_r) {}
    vector<Point> operator& (const Circle & oth) const {
        LD dis = (o - oth.o).len();
        if (dis>r+oth.r+eps || dis<fabs(r-oth.r)-eps) return vector<Point>();
        LD dt = (r*r - oth.r*oth.r) / dis;
        LD d1 = (dt + dis) / 2;
        Point dir = (oth.o - o) / dis;
        Point mid = o + dir * d1;
        dt = sqrt(max(0.0L, r*r - d1*d1));
        dir = dir.rot90();
        return vector<Point>{mid+dir*dt, mid-dir*dt};
    }
};
Circle items[5];
int par[5];
int find (int i) {
    if (par[i] == i) return i;
    return par[i]=find(par[i]);
}
void add (int i, int j) {
    int a = find(i);
    int b = find(j);
    par[a] = b;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, a, b, c;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        items[i] = Circle(Point(a, b), c);
        par[i] = i;
    }
    vector<Point> v;
    int e = 0;
    for (int i = 1; i <= n; i++) {
        vector<Point> split;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            auto tmp = items[i] & items[j];
            if (tmp.empty()) continue;
            add (i, j);
            for (auto p : tmp) {
                split.push_back(p);
                v.push_back(p);
            }
        }
        sort(split.begin(), split.end());
        e += unique(split.begin(), split.end()) - split.begin();
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    c = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) == i) c++;
    }
    int f = e - v.size() + c + 1;
    cout << f << endl;
}
