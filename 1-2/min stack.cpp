#include <stack>
#include <utility>
#include <iostream>
#include <fstream>
using namespace std;
int main() {
ifstream fin("stack-min.in"); 
ofstream fout("stack-min.out");
stack<pair<int,int> > st;
int n,a,b;
fin>>n;
for (int i=0; i<n; i++) {
    fin>>a;
    if (a==1) {
        fin>>b;
        if (st.empty()) {
        st.push(make_pair(b,b));
        } else
        if (b<=st.top().second) {
            st.push(make_pair(b,b));
             
        } else st.push(make_pair(b,st.top().second));
    } 
    if (a==2) {
        st.pop();
    }
    if (a==3) {
        fout<<st.top().second<<endl;
    }
    }
    fin.close();
    fout.close();
    }
  
