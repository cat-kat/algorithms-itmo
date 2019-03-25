#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> p(s.length());
    int left = 0, right = 0;
    for (int i = 1; i < s.length(); i++) {
        p[i] = max(0, min(right-  i, p[i- left]));
        while ((i + p[i] < s.length()) && (s[p[i]] == s[i + p[i]])) {
            p[i]++;
        }
        if (i + p[i] > right) {
            left = i;
            right = i + p[i];
        }
    }
    for (int i = 1; i < p.size(); i++) {
        cout << p[i] << " ";
    }
}
