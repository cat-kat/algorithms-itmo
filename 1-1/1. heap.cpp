#include <iostream>
#include <fstream>
using namespace std;
 
int main() {
    int n,c;
    c = -1;
 
ifstream fin("isheap.in"); 
  
    fin >> n; 
        int *a = new int[n];
        for (int j = 0; j <n; j++) {
            fin>>a[j];
             
        }
        fin.close();
        for (int i = 0; i <n; i++) {
            if (((2 * i + 1) < n) && (a[i] <= a[2*i + 1])) {
                c++;
            }
            if (((2 * i + 2) < n) && (a[i] <= a[2*i + 2])) {
                c++;
            }
        }
        ofstream fout("isheap.out"); 
        if (c == n-2) {
            fout << "YES";
        }
        else {
            fout << "NO";
        }
          
    
    fout.close();
}