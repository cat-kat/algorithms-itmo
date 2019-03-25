#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> graf;
vector<bool> used;
vector<int> enter;
int t;
vector<int> ret;
map<pair<int, int>, int> mp;
set<int> brige;

pair<int, int> ppair(int a, int b) {
   if (a>b) {
       swap(a,b);
   }
    return make_pair(a, b);
};

void dfs(int i, int pr) {
    used[i] = true;
    enter[i] = t++;
    ret[i] = t++;
    for (int j = 0; j < graf[i].size(); j++) {
        if (pr == graf[i][j]) {
            continue;
        }
        if (used[graf[i][j]] == true) {
            ret[i] = min(ret[i], enter[graf[i][j]]);
        } else {
            dfs(graf[i][j], i);
            ret[i] = min(ret[i], ret[graf[i][j]]);
            if (ret[graf[i][j]] > enter[i]) {
                brige.insert(mp[ppair(i, graf[i][j])]);
            }
        }
    }
}

int main() {

    cin >> n >> m;
    enter.resize(n);
    ret.resize(n);
    graf.resize(n);
    used.assign(n, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graf[a].push_back(b);
        graf[b].push_back(a);
        mp[ppair(a, b)] = i;
    }
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            dfs(i, -1);
        }
    }
    cout << brige.size()<<endl;


    vector<int> ans;
    for (auto i : brige) {
        ans.push_back(i+1);
    }
    std::sort (ans.begin(), ans.end());
    for (int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
}
close
