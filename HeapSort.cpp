#include<bits/stdc++.h>
#include<time.h>
using namespace std;

int sorted[10000];
void Heapifing(int arr[],int n)
{
   int v,j,k;
   int heap;
   for(int i=floorf(n/2);i>=1;i--)
   {
       v = arr[i];
       k = i;
       heap=0;
       while(heap==0 && 2*k<=n)
       {
           j = 2*k;
           if(j<n)
           {
               if(arr[j+1]>arr[j])
                  j = j+1;
           }
           if(v>=arr[j])
            heap =1;
           else{
                arr[k] = arr[j];
                k=j;
           }
           arr[k]=v;
       }
   }
}

void Root_deletion(int arr[],int n)
{
    if(n>=1)
    {
        Heapifing(arr,n);
        sorted[n] = arr[1];
        arr[1] = arr[n];
        Heapifing(arr,n-1);
        return(Root_deletion(arr,n-1));
    }
    return;
}

int main()
{
    srand(time(NULL));
    int n,arr[10000];
    cout << "read the size of array : ";
    cin >> n;
    cout << "Reading the array elements............ " << endl;
    for(int i=1;i<=n;i++)
    {
         arr[i] = rand()%100;
         cout << arr[i] << "  \n" << endl;
    }
    cout << "Done ..!" << endl ;
    Heapifing(arr,n);
    Root_deletion(arr,n);
    cout << "Printing heap sorted elements : ";
    for(int i=1;i<=n;i++)
        cout << sorted[i] << "\t" ;
    cout << endl;
  return 0;
}
