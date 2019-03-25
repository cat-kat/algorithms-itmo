#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<bool> used;
int n, m, t;
vector<vector<int> > graf;
vector<int> enter;
vector<int> ret;
vector<int> cutVertex;
set<int> cutVer;

void dfs (int i, int p = -1)
{
    int child;
    used[i] = true;
    ret[i] =t++;
    enter[i] = t++;
    child=0;
    for (int j = 0; j < graf[i].size(); j++)
    {
        if (graf[i][j] == p)
            continue;
        if (used[graf[i][j]]==true)
            enter[i] = min (enter[i], ret[graf[i][j]]);
        if (used[graf[i][j]]==false)
        {
            dfs (graf[i][j], i);
            enter[i] = min (enter[i], enter[graf[i][j]]);
            if ((enter[graf[i][j]] >= ret[i]) && (p != -1)) {
                if(cutVer.find(i)==cutVer.end()) {
                cutVertex.push_back(i);
                cutVer.insert(i);
                }
           }
child++;
        }
    }
    if ((p == -1) && (child > 1)){if(cutVer.find(i)==cutVer.end()) {cutVer.insert(i); cutVertex.push_back(i);}}
}

int main() {
cin>>n>>m;
    used.assign(n,0);
    enter.assign(n,0);
    ret.assign(n,0);
    graf.resize(n);
    t=1;
    for (int i=0; i<m; i++) {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
for (int i=0; i<n; i++) {
    if (used[i]==0) {
        dfs(i);
    }
}

    cout<<cutVertex.size()<<endl;
    sort(cutVertex.begin(), cutVertex.end());
    for (int i=0; i<cutVertex.size(); i++) {
        cout<<cutVertex[i]+1<<" ";
    }

}
