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
    
    long long l = s.length() - p[s.length()-1];
    if (s.length()%l==0) {
cout<<l;
    } else {
        cout<<s.length();
    }
}
