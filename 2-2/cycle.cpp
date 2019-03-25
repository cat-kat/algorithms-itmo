#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct ed {
    long long int start, end,w;
};

vector<ed> dist;
long long int n;
vector<long long int> path;
vector<long long int> parent;
vector<long long int> ans;


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            ed v;
            cin >>a;
            if (a!= 100000) {
                v.start = i;
                v.end = j;
                v.w = a;
                dist.push_back(v);
            }
        }
    }
    path.assign(n, 0);
    parent.assign(n, -1);
    long long int x;
    for (int i = 0; i < n; i++) {
        x = -1;
        for (long long int j = 0; j <dist.size(); j++) {
            if (path[dist[j].start] + dist[j].w < path[dist[j].end]) {
                x = dist[j].end;
                parent[dist[j].end] =dist[j].start;
                path[dist[j].end] = path[dist[j].start] + dist[j].w;
            }
        }
    }
    if (x == -1) {
        cout << "NO";
    } else {
        cout << "YES"<<endl;
        for (int i = 0; i < n; i++) {
            x = parent[x]; }
       long long int v = x;
        while (true) {
            ans.push_back(x + 1);
            x = parent[x];
            if (x == v) break;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (long long int i=0; i<ans.size(); i++) {
            cout << ans[i] << " ";
        }
    }
}
