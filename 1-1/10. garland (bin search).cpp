#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdio>
using namespace std;
  
  
int main() {
  ifstream fin("garland.in"); 
    ofstream fout("garland.out");
int n;
double a;
fin>>n>>a;
double r=a;
double l=0;
double b=-1;
while ((r-l)>0.0000000001*(n-1)) {
    double h2=(l+r)/2;
    double h1 = a;
    double h3= h2;
    bool prod = h3>0;
    for (int i=3; i<=n; i++) {
        double next = 2*h3-h1+2;
        prod &= next>0;
        h1=h3;
        h3=next;
    }
    if (prod) {
    r=h2;
    b=h3;
    } else
    {
        l=h2;
    }
}
    fout << fixed; 
fout.precision(2); 
fout << b;
 fout.close();
 fin.close();
}