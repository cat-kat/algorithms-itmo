#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int max_z[100000000];
int min_z[100000000];
int parent[100000000];
int size[10000000];

int find (long long a) {
    if (a == p[a])
        return a;
    return p[a] = find (p[a]);
}
void makeunion (long long a,long long b) {
    if (p[a]!=p[b]) {
        a = find (a);
        b = find (b);
        if (size[a] < size[b])
            swap (a, b);
        p[b] = a;
        size[a] += size[b];
    }
}

 
  
int main() {
ifstream fin("dsu.in"); 
    ofstream fout("dsu.out");
int n;
fin>>n;
for (int i=1; i<n+1; i++)    {
    parent[i] = i;
    size[i] = 1;
    min_z[i]=i;
    max_z[i]=i;
}
string s;
if (fin) {
while (fin>>s) {
if (s=="union") {
    int a,b;
    fin>>a>>b;
    makeunion (a,b);
   } else
if (s=="get") {
    int c;
    fin>>c;
    int k = find(c);
     fout<<min_z[k]<<" "<<max_z[k]<<" "<<size[k]<<endl;
         
}
}
}
fin.close();
fout.close();
}
  
