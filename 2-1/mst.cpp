#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector <pair<int, int>> gr;
vector <int> used;
vector <float> d;

int main () {
    int n;
    cin >> n;
    used.assign(n, 0);
    d.assign(n, numeric_limits<long long>::max());
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        gr.push_back(make_pair(x, y));
    }

    float ans = 0;
    d[0] = 0;
    for (int i = 0; i < n; i++) {
        int a = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j]) {
                if (a == -1 || d[j] < d[a]) {
                    a = j;
                }
            }
        }
        if (!used[a]) {
            ans += d[a];
            used[a] = 1;
        }
        for (int b = 0; b < n; ++b) {
            float local_lenght = (sqrt((gr[b].first - gr[a].first) * (gr[b].first - gr[a].first) +
                                           (gr[b].second - gr[a].second) * (gr[b].second - gr[a].second)));
            if (local_lenght < d[b]) {
                d[b] = local_lenght;
            }
        }
    }

    cout << ans;
}
