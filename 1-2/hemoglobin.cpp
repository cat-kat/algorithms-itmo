include <fstream>
using namespace std;
int main() {
ifstream fin("hemoglobin.in"); 
ofstream fout("hemoglobin.out");
    pair<int,int> mas[50000];
int n,sum,j;
j=-1;
sum=0;
fin>>n;
char s;
for (int i=0; i<n; i++) {
    fin>>s;
    if (s=='+') {
        j++;
        int a;
        fin>>a;
        mas[j].first=a;
        if (j==0) {
            mas[j].second=a;
        } else {
            mas[j].second=mas[j-1].second+a;
        }
        sum+=a;
         
            } else
    if (s=='?') {
        int a;
        fin>>a;
        if ((j-a)<0) {
            fout<<mas[j].second-0<<endl;
        } else {
         
        fout<<sum-mas[j-a].second<<endl;}
         
     
    } else
    if (s=='-') {
        fout<<mas[j].first<<endl;
        sum-=mas[j].first;
        j--;
         
         
    }
}
     
}
     
    
  
