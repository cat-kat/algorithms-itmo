
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> used;
vector<long long> d;
vector<vector<pair<long long, long long>>> g;

void dfs(long long v) {
    used[v] = 1;
    for (long long i = 0; i < g[v].size(); i++) {
        if (!used[g[v][i].first]) dfs(g[v][i].first);
    }
}


int main() {
    int n, m, b;
    long long max = numeric_limits<long long int>::max();
    cin >> n >> m >> b;
    b--;
    g.resize(m+1);
    for (long long i = 0; i < m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        g[u].push_back(make_pair(v, w));

    }
    d.assign(n+1, max);
    d[b] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < g[j].size(); k++) {
                if ((d[j] < max) && (d[g[j][k].first] > d[j] + g[j][k].second))
                    d[g[j][k].first] = d[j] + g[j][k].second;
            }

    used.assign(n + 1, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < g[i].size(); j++) {
            if ((d[i] < max) && (d[g[i][j].first] > d[i] + g[i][j].second) && !used[g[i][j].first])
                dfs(g[i][j].first);
        }

    for (int i = 0; i < n; i++) {
        if (d[i] == max) {
            cout << "*" << endl;
        } else if (used[i]) {
            cout << "-" << endl;
        } else cout << d[i] << endl;
    }

}
