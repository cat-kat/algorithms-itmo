#include <iostream>
#include <string>
#include <fstream>
  
using namespace std;
  
int main() {
ifstream fin("decode.in"); 
ofstream fout("decode.out");
    string s;
    fin>>s;
    int n=s.length();
s="k"+s;
int i=0;
while (i<n) {
if (s[i]==s[i+1]) {
 s.erase(i, 2);
i--;
} else {
    i++;
}
}
s.erase(0,1);
 
fout << s;
fin.close();
fout.close();
}
  
