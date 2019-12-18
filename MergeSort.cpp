#include<bits/stdc++.h>

using namespace std;

void MergeSort(int A[],int B[],int p,int C[],int q)
{
    int i=0,j=0,k=0;
    while(i<p&&j<q)
    {
        if(B[i]<C[j])
        {
            A[k]=B[i];
            i++;
        }else{
            A[k]=C[j];
            j++;
        }
        k++;
    }

    if(p==i)
    {
        while(j<q)
            A[k++]= C[j++];
    }else if(q==j)
    {
        while(i<p)
            A[k++]=B[i++];
    }
}

void merg(int A[],int n)
{
    int B[10000],C[10000],p,q,i;
   if(n>1){
       for(i=0,p=0,q=0;i<n;i++)
       {
        if(i<(n/2))
        {
            B[p] = A[i];
            p++;
        }else{
            C[q] = A[i];
            q++;
        }
     }
    merg(B,p);
    merg(C,q);
    MergeSort(A,B,p,C,q);
  }


}



int main()
{
    srand(time(NULL));
    int n,A[10000];
    cout << "enter the size : ";
    cin >> n;
    cout << "Reading the array ........"<<endl ;
    for(int i=0;i<n;i++)
        A[i] = rand()%1000;
    cout << "Done ...!"<< endl ;
    merg(A,n);
    cout << "Printing the array ... " << endl;
    for(int i=0;i<n;i++)
        cout << A[i] << "\t" ;
    cout << endl;
    return 0;
}
