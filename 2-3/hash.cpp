#include <iostream>
#include <vector>
using namespace std;

const int p = 53;
long long myHash[100002],  d[100002];

long long get_myHash ( int l, int r ) {
    return myHash[r + 1] - myHash[l] * d[r - l + 1];
};

bool myHash_equal (int a, int b, int c, int d) {
    if (get_myHash(c, d) == get_myHash(a, b)) {
        return true;
    } else return false;
}

int main() {
    string s;
    long long m;
    cin>>s>>m;
    myHash[0]=0;
    d[0]=1;
    vector <string> ans;
    for (int i = 0; i < s.length(); i++) {
        myHash[i + 1] = myHash[i] * p + s[i];
        d[i + 1] = d[i] * p;
    }

    for (int i=0; i<m; i++) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        a--; b--; c--; d--;
        if (myHash_equal(a,b,c,d)) {
            ans.push_back("Yes");
        } else {ans.push_back("No");}
    }
    for (int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<endl;
    }
}
