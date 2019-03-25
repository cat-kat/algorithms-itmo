#include <iostream>
#include <string>
#include <fstream>
#include <stack>
 
using namespace std;
 
int main() {
ifstream fin("brackets.in"); 
ofstream fout("brackets.out");
string a;
fin>>a;
int n=a.length();
stack <char> st;
 
for (int i=0; i<n; i++) {
if(st.empty())
        {
            st.push(a[i]);
            continue;
        } else
if (a[i]==')' && st.top() == '(') {
    st.pop();
     
} else
if (a[i]==']' && st.top() == '[') {
    st.pop();
} else
if (a[i]=='}' && st.top() == '{') {
    st.pop();
} else st.push(a[i]);
 
}
if (st.empty()) {
    fout<<"YES";
} else fout<<"NO";
fin.close();
fout.close();
}
  
