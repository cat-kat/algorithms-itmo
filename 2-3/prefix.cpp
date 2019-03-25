#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> p(s.length());
    p[0] = 0;
    for (int i = 1; i < s.length(); i++) {
        int k = p[i - 1];
        while ((k > 0) && (s[i] != s[k])) {
            k = p[k - 1];
        }
        if (s[i] == s[k]) {
            k++;
        }
        p[i] = k;
    }
    for (int i=0; i<p.size(); i++) {
        cout<<p[i]<<" ";
    }
}
