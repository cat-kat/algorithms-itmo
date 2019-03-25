#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
vector<vector<int> > graf;
vector<vector<int>> inv_graf;
vector<int> order;
vector<int> component;
vector<int> used;
set<pair<int, int> > s;

void dfs1(int i) {
    used[i] = 1;
    for (int j = 0; j < graf[i].size(); j++) {

        if (used[graf[i][j]] == 0) {
            dfs1(graf[i][j]);
        }
    }
    order.push_back(i);
}

void dfs2(int i) {
    used[i] = 1;
    component.push_back(i);
    for (int j = 0; j < inv_graf[i].size(); j++) {
        if (used[inv_graf[i][j]] == 0) {
            dfs2(inv_graf[i][j]);
        }
    }

}

pair<int, int> ppair(int a, int b) {
    return make_pair(a, b);
};

int main() {
    cin >> n >> m;
    used.assign(n, 0);
    graf.resize(n);
    inv_graf.resize(n);
    vector<int> color;
    color.resize(n);

    int k = m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a;
        a--;
        cin >> b;
        b--;
        graf[a].push_back(b);
        inv_graf[b].push_back(a);
    }

    int col = 0;

    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            dfs1(i);
        }
    }
    used.assign(n, 0);
    int size = order.size();
    for (int i = 0; i < size; i++) {
        int v = order[size - 1 - i];
        if (used[v] == 0) {
            dfs2(v);
            for (int j = 0; j < component.size(); j++) {
                color[component[j]] = col;
            }
            col++;
            component.clear();
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < graf[i].size(); ++j) {
            int to = graf[i][j];
            if (color[i] != color[to])
                s.insert({color[i], color[to]});
        }
    }
    cout << s.size();
}

