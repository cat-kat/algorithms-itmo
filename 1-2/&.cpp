#include <iostream>
#include <string>
#include <fstream>
using namespace std;
 
int main() {
ifstream fin("formation.in"); 
    ofstream fout("formation.out");
int n,m;
int r=0;
fin>>n>>m;
pair<int,int> neigh[n];
for (int i=0; i<n; i++) {
    neigh[i].first=0;
    neigh[i].second=0;
}
string s;
    for (int i=0; i<m; i++) {
        fin>>s;
        if (s=="left") {
            int a,b;
            fin>>a>>b;
            if (r==0) {
                neigh[a].first=0;
                neigh[a].second=b;
                neigh[b].first=a;
                neigh[b].second=0;
                r++;
            } else {
            neigh[a].first=neigh[b].first;
        neigh[neigh[b].first].second=a;
            neigh[b].first=a;
            neigh[a].second=b;
             
              
            r++;}
            }
        if (s=="right") {
            int a,b;
            fin>>a>>b;
            if (r==0) {
                neigh[a].second=0;
                neigh[a].first=b;
                neigh[b].second=a;
                neigh[b].first=0;
                r++;
            } else {
             
        neigh[a].second=neigh[b].second;
        neigh[neigh[b].second].first=a;
            neigh[b].second=a;
            neigh[a].first=b;
             
            r++;
        }
        }
        if (s=="leave") {
            int a;
            fin>>a;
        neigh[neigh[a].first].second=neigh[a].second;
        neigh[neigh[a].second].first=neigh[a].first;
        r--;
        }
        if (s=="name") {
            int a;
            fin>>a;
            fout<<neigh[a].first<<" "<<neigh[a].second<<endl;
        }
     
     
}
fin.close();
fout.close();
}
  
