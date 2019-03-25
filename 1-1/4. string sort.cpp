#include<fstream>
#include <string>
 
using namespace std;
 
void radix(string a[], int n, int m, int k)
{
    string *c = new string[n];
 
    for(int i = m - 1; i >= m-k; i--)
    {
        int count[27] = {0};
 
        for(int j = 0; j < n; j++)
            count[static_cast<int>(a[j][i]) - 96]++;
 
        for(int j = 2; j < 26; j++)
            count[j] += count[j - 1];
 
        for(int j = 0; j < n; j++)
            c[count[static_cast<int>(a[j][i]) - 97]++] = a[j];
 
        for(int j = 0; j < n; j++)
            a[j] = c[j];
    }
}
 
int main() {
    ifstream fin("radixsort.in"); 
    ofstream fout("radixsort.out");
int n,m,k;
fin>>n>>m>>k;
string *a=new string[n];
for (int i=0; i<n; i++) {
    fin>>a[i];
}
radix(a,n,m,k);
for (int i=0; i<n; i++) {
    fout<<a[i]<<endl;
}
fout.close();
fin.close();
}