#include <iostream>
#include <vector>
#include <limits>
#include <set>
using namespace std;

vector <vector<pair<int, int>>> graf;
vector <long long int> dist;
vector <int> used;
set < pair<int,int> > fast;
int n,m;

int main() {
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
     int inf = std::numeric_limits< int>::max();

    used.assign(n,0);
    graf.resize(n);
    dist.assign(n,inf);
    dist[0] = 0;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b>> w;
        a--;
        b--;
        graf[a].push_back(make_pair(b,w));
        graf[b].push_back(make_pair(a,w));
    }

    fast.insert(make_pair (dist[0], 0));
    while (!fast.empty()) {
        int v = fast.begin()->second;
        fast.erase (fast.begin());
        for (int j=0; j<graf[v].size(); ++j) {
            if (dist[v] + graf[v][j].second< dist[graf[v][j].first]) {
                fast.erase(make_pair(dist[graf[v][j].first], graf[v][j].first));
                dist[graf[v][j].first] = dist[v] + graf[v][j].second;
                fast.insert(make_pair(dist[graf[v][j].first], graf[v][j].first));
            }}}
    for (int i=0; i <n ; i++) {
        cout<<dist[i]<<" ";
    }
}

