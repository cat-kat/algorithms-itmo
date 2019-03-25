#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
  
int main (int argc, char **argv) {

char d;
stack <int> st;
for (int i=1; i<=argc; i++) {

 
     
       if (argv[i]=="+"|| argv[i]=="-" || argv[i]=="*") {
              int  a=st.top();
               st.pop();
               int b=st.top();
               st.pop();
               if (d=='+') {
               st.push(a+b);
               } else
                
                
            if (d=='-') {
             st.push(b-a);
             
               } else
            if (d=='*') {
             st.push(a*b);
              
               }
        } else {
		
       int arg = atof(argv[i]);  
         st.push(arg);
       
        }
   }
      

 
    cout<<st.top()+0;
 
}
  
