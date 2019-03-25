#include <iostream>
#include <fstream>
using namespace std;
 
 
int main() {
ifstream fin("hospital.in"); 
    ofstream fout("hospital.out");
    int mas[100001];
    for (int i=0; i<100001; i++) {
        mas[i]=111111;
    }
    int i,k;
    i=0; 
     
    k=0; 
    int n;
    fin>>n;
    for (int l=0; l<n; l++) {
        string s;
 
        fin>>s; 
        if (s=="+") {
            int a;
            fin>>a;
            mas[i]=a;
            i++;
        } else
        if (s=="-") {
        fout<<mas[k]<<endl;
            k++;
        } else
        if (s=="*") {
            int a;
            fin>>a;
         
         
        if ((i-k)==0) {
            mas[k]=a;
         
        } else {
 
     
     
    for (int m=i; m>=(i-k+1)/2+1+k; m--) {
                mas[m]=mas[m-1];
              
            }
           
            mas[(i-k+1)/2+k]=a;
        }
  
     i++;
      
    }}
 fin.close();
 fout.close();
 }
  
    
     
    
  
