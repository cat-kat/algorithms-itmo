#include <iostream>
#include <vector>
#include <limits>
#include <set>
using namespace std;

vector <vector<pair<long long int,long long int>>> graf;
vector <long long int> dist_c;
vector <long long int> dist_a;
vector <long long int> dist_b;
vector <int> used;
set < pair<long long int,long long int> > fast_a;
set < pair<long long int,long long int> > fast_b;
set < pair<long long int,long long int> > fast_c;
int n,m;

int main() {
  long long   int a,b,c;

    ios_base::sync_with_stdio(false);
    cin>>n>>m;
   long long int inf = std::numeric_limits< long long int>::max();
    used.assign(n,0);
    graf.resize(n);

    dist_a.assign(n,inf);
    dist_b.assign(n,inf);
    dist_c.assign(n,inf);


    for (int i = 0; i < m; i++) {
        int k, l, w;
        cin >> k >> l>> w;
        k--;
        l--;
        graf[k].push_back(make_pair(l,w));
        graf[l].push_back(make_pair(k,w));
    }
    cin>>a>>b>>c;
    a--; b--; c--;
    dist_a[a] = 0;
    dist_b[b] = 0;
    dist_c[c] = 0;
    fast_a.insert(make_pair (dist_a[a], a));
    while (!fast_a.empty()) {
       long long int v = fast_a.begin()->second;
        fast_a.erase (fast_a.begin());
        for (int j=0; j<graf[v].size(); ++j) {
            if (dist_a[v] + graf[v][j].second< dist_a[graf[v][j].first]) {
                fast_a.erase(make_pair(dist_a[graf[v][j].first], graf[v][j].first));
                dist_a[graf[v][j].first] = dist_a[v] + graf[v][j].second;
                fast_a.insert(make_pair(dist_a[graf[v][j].first], graf[v][j].first));
            }}}
    fast_b.insert(make_pair (dist_b[b], b));
    while (!fast_b.empty()) {
     long long   int v = fast_b.begin()->second;
        fast_b.erase (fast_b.begin());
        for (int j=0; j<graf[v].size(); ++j) {
            if (dist_b[v] + graf[v][j].second< dist_b[graf[v][j].first]) {
                fast_b.erase(make_pair(dist_b[graf[v][j].first], graf[v][j].first));
                dist_b[graf[v][j].first] = dist_b[v] + graf[v][j].second;
                fast_b.insert(make_pair(dist_b[graf[v][j].first], graf[v][j].first));
            }}}
    fast_c.insert(make_pair (dist_c[c], c));
    while (!fast_c.empty()) {
      long long  int v = fast_c.begin()->second;
        fast_c.erase (fast_c.begin());
        for (int j=0; j<graf[v].size(); ++j) {
            if (dist_c[v] + graf[v][j].second< dist_c[graf[v][j].first]) {
                fast_c.erase(make_pair(dist_c[graf[v][j].first], graf[v][j].first));
                dist_c[graf[v][j].first] = dist_c[v] + graf[v][j].second;
                fast_c.insert(make_pair(dist_c[graf[v][j].first], graf[v][j].first));
            }}}
if ((((dist_a[b] + dist_a[c])>0)&&((dist_a[b] + dist_a[c])<inf/2)) || (((dist_b[a] + dist_b[c])>0)&&((dist_b[a] + dist_b[c])<inf/2)) || (((dist_c[a] + dist_c[b])>0)&&((dist_c[a] + dist_c[b])<inf/2))) {
cout<<min(dist_a[b] + dist_a[c], min( dist_b[a] + dist_b[c], dist_c[a] + dist_c[b]) );} else {
            cout<<"-1";}

}

