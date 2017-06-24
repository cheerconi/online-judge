#include <iostream>
#include <stdio.h>
#include<vector>
#include <string>
#include <memory.h>
#include <algorithm>
#include <string>
#include <limits.h>

using namespace std;

bool graph[26][26];
bool has[26];
vector<char> nodes;

string ret;
string real_ret;
int val = 0;
int cnt = 0;

void backtrack(int i, vector<int> &pos) {
    if (i == nodes.size()) {
        cnt = min(cnt, val);
        real_ret = ret;
        return;
    }
    int tmp = val;
    for(int k = 0; k < nodes.size(); k++) {
        if (pos[k] != -1) continue;
        for (int j = 0; j < nodes.size(); j++) {
            if (pos[j]==-1 || !graph[nodes[j]-'A'][nodes[k]-'A']) continue;
            val = max(val, i - pos[j]);
            if (val >= cnt) return;
        }
        pos[k] = i;
        ret.push_back(' ');
        ret.push_back(nodes[k]);

        backtrack(i+1, pos);

        pos[k] = -1;
        ret.pop_back();
        ret.pop_back();
        val = tmp;
    }

}

int main() {
//    freopen("test.txt", "r", stdin);
    char c, neighbor;
    while (true) {
        memset(graph, 0, sizeof(graph));
        memset(has, 0, sizeof(has));
        nodes.clear();
        ret.clear();
        cnt = INT_MAX;
        val = 0;
        bool done = false;
        while (true) {
            if (done) break;
            scanf("%c", &c);
            if (c == '#') return 0;
            has[c-'A'] = true;
            getchar(); //':'
            while (true) {
                scanf("%c", &neighbor);
                if (neighbor == '\n') {
                    for (int i = 0; i < 26; i++) {
                        if (has[i]) nodes.push_back(i+'A');
                    }
                    vector<int> pos(nodes.size(), -1);
                    backtrack(0, pos);
                    cout << real_ret.substr(1) << " -> " << cnt << endl;
                    done = true;
                    break;
                }
                if (neighbor != ';') {
                    has[neighbor-'A'] = true;
                    graph[c-'A'][neighbor-'A'] = true;
                    graph[neighbor-'A'][c-'A'] = true;
                }
                else break;
            }
        }


    }

    return 0;
}