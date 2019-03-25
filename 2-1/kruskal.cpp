#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<pair<long long, pair<long long, long long>>> gr;
vector<long long> par;
vector <long long> size;

int find(int v) {
    if (v == par[v])
        return v;
    return par[v] = find (par[v]);
}

void unite(long long a, long long b) {
    a = find (a);
    b = find (b);
    if (a != b) {
        if (size[a] < size[b])
            swap (a, b);
        par[b] = a;
        size[a] += size[b];
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    gr.resize(m);
    for (long long i = 0; i < m; i++) {
        long long v, u, w;
        cin >> v >> u >> w;
        v--;
        u--;
        gr[i].first = w;
        gr[i].second.first = v;
        gr[i].second.second = u;
    }
    for (int i = 0; i < n; i++) {
        par.push_back(i);
        size.push_back(1);
    }
    sort(gr.begin(), gr.end());
    long long ans = 0;
    for (long long i = 0; i < m; i++) {
        if (find(gr[i].second.first) != find(gr[i].second.second)) {
            unite(gr[i].second.first, gr[i].second.second);
            ans += gr[i].first;
        }
    }
    cout << ans;
}
