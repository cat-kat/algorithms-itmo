#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> graf;
vector<vector<int>> d;

int main() {
    int n, m, k, b;
    int max = numeric_limits<int>::max();
    cin >> n >> m >> k >> b;
    b--;
    graf.resize(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        graf[i].first = w;
        graf[i].second.first = u;
        graf[i].second.second = v;
    }
    d.resize(k + 1);
    for (int i = 0; i <= k; i++) {
        d[i].assign(n, max);
    }

    d[0][b] = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            if (d[i][graf[j].second.first] < max) {
                if (d[i+1][graf[j].second.second] > d[i][graf[j].second.first] + graf[j].first) {
                    d[i+1][graf[j].second.second] = d[i][graf[j].second.first] + graf[j].first;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (d[k][i] == max) {
            cout << "-1" << endl;
        } else
            cout << d[k][i] << endl;
    }
}
