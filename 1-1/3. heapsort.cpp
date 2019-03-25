#include <iostream>
#include <fstream>
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
  
 int main()
{
    int n;
     
    ifstream fin("sort.in");
    fin>>n;
    int *mas=new int[n];
    for (int i=0; i<n; i++) {
        fin>>mas[i];
    }
    fin.close();
    heapSort(mas, n);
      
     ofstream fout("sort.out");
     for (int i=0; i<n; ++i) {
     fout << mas[i] << " ";
}
fout.close();
    
}