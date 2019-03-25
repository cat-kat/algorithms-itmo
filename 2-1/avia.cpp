#include <fstream>
#include <vector>
using namespace std;


vector<vector<int>> g;
vector<vector<int>> gr;
vector<int> used;
int n;

void dfs(int v, int fl_inv) {
    int i;
    used[v] = 1;
    for (i = 0; i < n; i++)
        if ((fl_inv ? g[i][v] : g[v][i]) && !used[i]) dfs(i, fl_inv);
}

bool used_all() {
    int i;
    for (i = 0; i < n; i++)
        if (!used[i]) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream fin("avia.in");
    ofstream fout("avia.out");
    fin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> t;
        t.resize(n);
        g.push_back(t);
        gr.push_back(t);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int top;
            fin >> top;
            gr[i][j] = top;

        }

    long long l = 0;
    long long r = 1000000000;
    while (l < r) {
        long long m = (l + r) / 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (gr[i][j] <= m) {
                    g[i][j] = 1;
                } else g[i][j] = 0;
            }
        }
        used.assign(n, 0);
        dfs(0, 0);
        int fl = 0;
        if (used_all()) {
            used.assign(n, 0);
            dfs(0, 1);
            if (!used_all())
                fl = 1;
        } else fl = 1;
        if (!fl) r = m;
        else l = m  + 1;
    }
    fout << l;
}
