#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
bool fll_cycle;
vector<vector<int> > graf;
vector<int> top_sort;
vector<int> color;



void dfs(int i) {
    color[i]=1;
    for (int j = 0; j < graf[i].size(); j++) {
        if (color[graf[i][j]] == 0) {
            dfs(graf[i][j]);
        }
        if (color[graf[i][j]]==1) {
            fll_cycle=true;
        }
    }
    color[i] = 2;
    int v = i + 1;
    top_sort.push_back(v);
}

void topological_sort() {
    for (int i = 0; i < n; i++) {

        color[i] = 0;
    }
    top_sort.clear();
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            dfs(i);
        }
    }
    reverse(top_sort.begin(), top_sort.end());
}


int main() {
    fll_cycle = false;
    cin >> n >> m;
color.assign(n,0);
    graf.resize(n);
   vector <bool> p;
    p.assign(n,1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graf[a].push_back(b);
    }
    topological_sort();
    if (top_sort.size()!=n || fll_cycle == true) {
        cout<<"-1";
    }
     else {
        for (int i = 0; i < n; i++) {
            cout << top_sort[i] << " ";
        }
    }
}
