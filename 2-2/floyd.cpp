#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> graf[100];



int main () {
  cin>>n;
    for( int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
        int a; cin>>a;
        graf[i].push_back(a);
    }
}
for (int k=0; k<n; k++) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            graf[i][j] = min(graf[i][j], graf[i][k] + graf[k][j]);
        }
    }
}

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout<<graf[i][j]<<" ";
        }
        cout<<endl;
    }
}
