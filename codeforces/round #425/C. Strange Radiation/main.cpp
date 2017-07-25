#include <iostream>
#include <map>
#include <vector>
#include <math.h>
using namespace std;

const int MAXN = 1000000 + 10;
double leftdp[MAXN];
double rightdp[MAXN];


double compute(double pre_pos, double pre_speed, double ray, double p, double target, double init) {
    double pre_time = init;
    double tmp;
    if (pre_speed != INT_MIN) {
        double delta = fabs(p - pre_pos) / (ray - pre_speed);
        if (delta > fabs(pre_pos - target) / pre_speed) {
            tmp = fabs(pre_pos - target) / pre_speed;
        }
        else {
            tmp = delta + (fabs(pre_pos - target) - delta*pre_speed) / (pre_speed + ray);
        }
        if (tmp < pre_time) pre_time = tmp;
    }
    return pre_time;
}
int main() {
//    freopen("test.txt", "r", stdin);
    multimap<int, int> left;
    multimap<int, int> right;
    double initleft = INT_MAX;
    double initright = INT_MAX;
    int n, ray, pos, dir, speed;
    int maxright = 1000000;
    scanf("%d%d", &n, &ray);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &pos, &speed, &dir);
        if (dir == 1) {
            left.insert({pos, speed});
            initleft = min(initleft, (double)pos / speed);
        }
        else {
            right.insert({-pos, speed});
            initright = min(initright, (double)(maxright - pos) / speed);
        }
    }

    double pre_pos = 0;
    double pre_speed = INT_MIN;
    int i = 0;
    for (auto it = left.begin(); it != left.end(); it++) {
        double p = it->first;
        double s = it->second;
        while (i < p) {
            double pre_time = compute(pre_pos, pre_speed, ray, i, 0, initleft);
            leftdp[i++] = pre_time;
        }
        double time = p / (s + ray);
        double pre_time = compute(pre_pos, pre_speed, ray, i, 0, initleft);
        if (time < pre_time) {
            pre_pos = p;
            pre_speed = s;
            leftdp[i] = time;
        }
        else {
            leftdp[i] = pre_time;
        }
        i++;
    }
    while (i <= maxright) {
        leftdp[i] = compute(pre_pos, pre_speed, ray, i, 0, initleft);
        i++;
    }


    pre_pos = 0;
    pre_speed = INT_MIN;
    i = maxright;
    double ret = INT_MAX;
    for (auto it = right.begin(); it != right.end(); it++) {
        double p = -(it->first);
        double s = it->second;
        while (i > p) {
            double pre_time = compute(pre_pos, pre_speed, ray, i, maxright, initright);
            rightdp[i--] = pre_time;
            double tmpret = max(rightdp[i+1], leftdp[i+1]);
            ret = min(ret, tmpret);
        }
        double time = (maxright - p) / (s + ray);
        double pre_time = compute(pre_pos, pre_speed, ray, i, maxright, initright);
        if (time < pre_time) {
            pre_pos = p;
            pre_speed = s;
            rightdp[i] = time;
        }
        else {
            rightdp[i] = pre_time;
        }
        i--;
        double tmpret = max(rightdp[i+1], leftdp[i+1]);
        ret = min(ret, tmpret);
    }
    while (i >= 0) {
        rightdp[i] = compute(pre_pos, pre_speed, ray, i, maxright, initright);
        i--;
        double tmpret = max(rightdp[i+1], leftdp[i+1]);
        ret = min(ret, tmpret);
    }
    printf("%.20f\n", ret);




    return 0;
}