#include <iostream>

int main() {
    int n,b;
    cin>>n;
    int *a=new int[2^n];
    int *b=new int[2^n];
    int *k=new int[2^n];
    for (int i=0; i<n;i++) {
        cin>>k[i];
        cin>>a[i];
    }
for (int i=0; i<n;i++) {
    b[j]=a[i];
    j++;
    for (int i=0; i<n-1;i++) {
        a[i]=(a[i]+a[i+1])%2;
    }

}
for (int i=0; i<n;i++) {
    cout<<k[i]<<" "<<b[i]<<endl;
}
}