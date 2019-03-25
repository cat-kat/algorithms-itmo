#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s, p, t;
    cin >> p >> t;
    s = p + "#" + t;
    vector<int> z(s.length());
    int left = 0, right = 0;
    for (int i = 1; i < s.length(); i++) {
        z[i] = max(0, min(right - i, z[i - left]));
        while ((i + z[i] < s.length()) && (s[z[i]] == s[i + z[i]])) {
            z[i]++;
        }
        if (i + z[i] > right) {
            left = i;
            right = i + z[i];
        }
    }
    int ans=0;
    vector <int> answ;
    for (int i=0; i<t.length()-1; i++) {
        if (z[i+p.length()+1]==p.length()) {
            ans++;
            answ.push_back(i);
        }
    }
    cout<<ans<<endl;
    sort(answ.begin(), answ.end());
    for (int i=0; i<answ.size(); i++) {
        cout<<answ[i]+1<<" ";
    }
}
