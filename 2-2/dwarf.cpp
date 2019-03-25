#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
vector<vector<pair<long long, long long>>> gr;
vector<long long> money;


int main() {
    ios_base::sync_with_stdio(false);
      ifstream fin("dwarf.in");
     ofstream fout("dwarf.out");
    long long n, m;
    fin >> n >> m;
    money.resize(n + 1);
    for (long long i = 0; i < n; i++) {
        long long c;
        fin >> c;
        money[i] = c;
    }
    gr.resize(n + 1);
    for (long long i = 0; i < m; i++) {
        long long j, a, b;
        fin>>j>>a>>b;
        j--;
        a--;
        b--;
        gr[a].push_back(make_pair(j, b));
        gr[b].push_back(make_pair(j, a));
    }

    for (long long k = 0; k < n; k++) {
        set<pair<long long, long long>> r;
        r.insert(make_pair(money[k], k));
        while (!r.empty()) {
            long long i= (r.begin())->second;
            r.erase(r.begin());
            for (long long j = 0; j < gr[i].size(); j++) {
                if (money[i] + money[gr[i][j].second] < money[gr[i][j].first]) {
                    r.erase({money[gr[i][j].first], gr[i][j].first});
                    money[gr[i][j].first] = money[i] + money[gr[i][j].second];
                    r.insert({money[gr[i][j].first], gr[i][j].first});
                }
            }

        }
    }
    fout << money[0];
}
