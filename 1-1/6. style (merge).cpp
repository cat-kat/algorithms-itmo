#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
 
int main() {
    int n,m;
     ifstream fin("style.in"); 
     ofstream fout("style.out"); 
    fin>>n;
    int *a=new int[n];
    for (int i=0; i<n; i++) {
        fin>>a[i];
    }
    fin>>m;
    int *b=new int[m];
    for (int i=0; i<m; i++){
        fin>>b[i];
 
    }
     
    int i=0;
    int j=0;
    int imin=100001;
    int jmin=100001;
    long int min=10000001;
    while (i<=n-1 && j<=m-1) {
        if (abs(a[i]-b[j])<min) {
         
            min=abs(a[i]-b[j]);
            imin=i;
            jmin=j;
            if (i<n && j<m) {
                if (a[i]>b[j]) {
                    j++;
                } else {
                 
                i++;
            } 
        } else
        if (j!=m-1 && i==n-1) {
                j++;
             
            } else
              
            if (j==m-1 && i!=n-1) {
                i++;
                 
            }
         
        }
        else if (i<n && j<m) {
                if (a[i]>b[j]) {
                    j++;
                } else {
                 
                i++;
            } 
        } else
        if (j!=m-1 && i==n-1) {
                j++;
             
            } else
              
            if (j==m-1 && i!=n-1) {
                i++;
                 
            }
        }
      
    fout<<a[imin]<<" "<<b[jmin];
fin.close();
fout.close();
 
 
}