#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
void siftDown(int mas[], int n, int i)
{
    int max = i;  
    int l = 2*i + 1;  
    int r = 2*i + 2;  
 if (l < n && mas[l] > mas[max])
        max = l;
 if (r < n && mas[r] > mas[max])
        max = r;
 if (max != i)
    {
        swap(mas[i], mas[max]);
        siftDown(mas, n, max);
    }
}
 
void heapSort(int mas[], int n)
{
     
    for (int i = n / 2 - 1; i >= 0; i--)
        siftDown(mas, n, i);
 for (int i=n-1; i>=0; i--)
    {
        swap(mas[0], mas[i]);
        siftDown(mas, i, 0);
    }
}
  
  
 
 
int main() {
    ifstream fin("style.in"); 
    ofstream fout("style.out"); 
    int n1,n2,n3,n4;
    fin >>n1;
    int *a1=new int[n1];
    for (int i=0; i<n1; i++) {
        fin>>a1[i];
    }
    fin>>n2;
    int *a2=new int[n2];    
        for (int i=0; i<n2; i++) {
        fin>>a2[i];
    }
    fin>>n3;
    int *a3=new int[n3];
        for (int i=0; i<n3; i++) {
        fin>>a3[i];
    }
    fin>>n4;
    int *a4=new int[n4];
        for (int i=0; i<n4; i++) {
        fin>>a4[i];
    }
    heapSort(a1,n1);
    heapSort(a2,n2);
    heapSort(a3,n3);
    heapSort(a4,n4);
    int i=0;
    int j=0;
    int k=0;
    int m=0;
    int imin=100001;
    int jmin=100001;
    int kmin=100001;
    int mmin=100001;
    long int min=10000001;
     
    while (i<=n1-1 && j<=n2-1 && k<=n3-1 && m<=n4-1) {
    if (abs(abs(a1[i]-a2[j])+abs(a2[j]-a3[k])+abs(a3[k]-a4[m])+abs(a2[j]-a4[m])+abs(a1[i]-a3[k])+abs(a1[i]-a4[m]))<min)
    {
        imin=i;
     jmin=j;
     kmin=k;
    mmin=m;
    min=abs(abs(a1[i]-a2[j])+abs(a2[j]-a3[k])+abs(a3[k]-a4[m])+abs(a2[j]-a4[m])+abs(a1[i]-a3[k])+abs(a1[i]-a4[m]));
    if (i<n1 && j<n2 && k<n3 && m<n4) {
                if (a1[i]<=a2[j] && a1[i]<=a3[k] && a1[i]<=a4[m]) {
            i++;    
        } else
    if (a2[j]<=a1[i] && a2[j]<=a3[k] && a2[j]<=a4[m]) {
         
            j++;
        } else
    if (a3[k]<=a1[i] && a3[k]<=a2[j] && a3[k]<=a4[m]) {
        k++;
        } else
         
    if (a4[m]<=a1[i] && a4[m]<=a2[j] && a4[m]<=a3[k]) {
        m++;
}
        } else
        if (i==n1-1 && j!=n2-1 && k!=n3-1 && m!=n4-1) {
                if (a2[j]<=a3[k] && a2[j]<=a4[m]) {
        j++;
        } else if (a3[k]<=a4[m] && a3[k]<=a2[j]) {
            k++;
        } else
        if (a4[m]<=a3[k] && a4[m]<=a2[j]) {
            m++;
        }
    } else if (i!=n1-1 && j==n2-1 && k!=n3-1 && m!=n4-1) {
         
                if (a1[i]<=a3[k] && a1[i]<=a4[m]) {
        i++;
        } else if (a3[k]<=a4[m] && a3[k]<=a1[i]) {
            k++;
        } else
        if (a4[m]<=a3[k] && a4[m]<=a1[i]) {
            m++;
        }
    } else if (i!=n1-1 && j!=n2-1 && k==n3-1 && m!=n4-1) {
         
                if (a1[i]<=a2[j] && a1[i]<=a4[m]) {
        i++;
        } else if (a2[j]<=a4[m] && a2[j]<=a1[i]) {
            j++;
        } else
        if (a4[m]<=a2[j] && a4[m]<=a1[i]) {
            m++;
        }
    } else if (i!=n1-1 && j!=n2-1 && k!=n3-1 && m==n4-1) {
         
                if (a1[i]<=a3[k] && a1[i]<=a2[j]) {
        i++;
        } else if (a3[k]<=a2[j] && a3[k]<=a1[i]) {
            k++;
        } else
        if (a2[j]<=a3[k] && a2[j]<=a1[i]) {
            j++;
        }} else if (i==n1-1 && j==n2-1 && k!=n3-1 && m!=n4-1) {
            if (a3[k]<=a4[m]) {
                k++;
            } else m++;
        } else if (i!=n1-1 && j==n2-1 && k==n3-1 && m!=n4-1) {
            if (a1[k]<=a4[m]) {
                i++;
            } else m++;
        } else if (i!=n1-1 && j==n2-1 && k!=n3-1 && m==n4-1) {
            if (a1[i]<=a3[k]) {
                i++;
            } else k++;
        } else if (i==n1-1 && j!=n2-1 && k==n3-1 && m!=n4-1) {
            if (a2[j]<=a4[m]) {
                j++;
            } else m++;
        } else if (i==n1-1 && j!=n2-1 && k!=n3-1 && m==n4-1) {
            if (a2[j]<=a3[k]) {
                j++;
            } else k++;
        } else if (i!=n1-1 && j!=n2-1 && k==n3-1 && m==n4-1) {
            if (a1[i]<=a2[j]) {
                i++;
            } else j++;
        } else if (i!=n1-1 && j==n2-1 && k==n3-1 && m==n4-1) {
            i++;
        } else if (i==n1-1 && j!=n2-1 && k==n3-1 && m==n4-1) {
            j++;
        }else if (i==n1-1 && j==n2-1 && k!=n3-1 && m==n4-1) {
            k++;
    } else
    if (i==n1-1 && j==n2-1 && k==n3-1 && m!=n4-1) {
            m++;
    }
}
     else   if (i<n1 && j<n2 && k<n3 && m<n4) {
                if (a1[i]<=a2[j] && a1[i]<=a3[k] && a1[i]<=a4[m]) {
            i++;    
        } else
    if (a2[j]<=a1[i] && a2[j]<=a3[k] && a2[j]<=a4[m]) {
         
            j++;
        } else
    if (a3[k]<=a1[i] && a3[k]<=a2[j] && a3[k]<=a4[m]) {
        k++;
        } else
         
    if (a4[m]<=a1[i] && a4[m]<=a2[j] && a4[m]<=a3[k]) {
        m++;
}
        } else
        if (i==n1-1 && j!=n2-1 && k!=n3-1 && m!=n4-1) {
                if (a2[j]<=a3[k] && a2[j]<=a4[m]) {
        j++;
        } else if (a3[k]<=a4[m] && a3[k]<=a2[j]) {
            k++;
        } else
        if (a4[m]<=a3[k] && a4[m]<=a2[j]) {
            m++;
        }
    } else if (i!=n1-1 && j==n2-1 && k!=n3-1 && m!=n4-1) {
         
                if (a1[i]<=a3[k] && a1[i]<=a4[m]) {
        i++;
        } else if (a3[k]<=a4[m] && a3[k]<=a1[i]) {
            k++;
        } else
        if (a4[m]<=a3[k] && a4[m]<=a1[i]) {
            m++;
        }
    } else if (i!=n1-1 && j!=n2-1 && k==n3-1 && m!=n4-1) {
         
                if (a1[i]<=a2[j] && a1[i]<=a4[m]) {
        i++;
        } else if (a2[j]<=a4[m] && a2[j]<=a1[i]) {
            j++;
        } else
        if (a4[m]<=a2[j] && a4[m]<=a1[i]) {
            m++;
        }
    } else if (i!=n1-1 && j!=n2-1 && k!=n3-1 && m==n4-1) {
         
                if (a1[i]<=a3[k] && a1[i]<=a2[j]) {
        i++;
        } else if (a3[k]<=a2[j] && a3[k]<=a1[i]) {
            k++;
        } else
        if (a2[j]<=a3[k] && a2[j]<=a1[i]) {
            j++;
        }} else if (i==n1-1 && j==n2-1 && k!=n3-1 && m!=n4-1) {
            if (a3[k]<=a4[m]) {
                k++;
            } else m++;
        } else if (i!=n1-1 && j==n2-1 && k==n3-1 && m!=n4-1) {
            if (a1[k]<=a4[m]) {
                i++;
            } else m++;
        } else if (i!=n1-1 && j==n2-1 && k!=n3-1 && m==n4-1) {
            if (a1[i]<=a3[k]) {
                i++;
            } else k++;
        } else if (i==n1-1 && j!=n2-1 && k==n3-1 && m!=n4-1) {
            if (a2[j]<=a4[m]) {
                j++;
            } else m++;
        } else if (i==n1-1 && j!=n2-1 && k!=n3-1 && m==n4-1) {
            if (a2[j]<=a3[k]) {
                j++;
            } else k++;
        } else if (i!=n1-1 && j!=n2-1 && k==n3-1 && m==n4-1) {
            if (a1[i]<=a2[j]) {
                i++;
            } else j++;
        } else if (i!=n1-1 && j==n2-1 && k==n3-1 && m==n4-1) {
            i++;
        } else if (i==n1-1 && j!=n2-1 && k==n3-1 && m==n4-1) {
            j++;
        }else if (i==n1-1 && j==n2-1 && k!=n3-1 && m==n4-1) {
            k++;
    } else
    if (i==n1-1 && j==n2-1 && k==n3-1 && m!=n4-1) {
            m++;
    }
 
}
 
fout<<a1[imin]<<" "<<a2[jmin]<<" "<<a3[kmin]<<" "<<a4[mmin];
fout.close();
fin.close();
}