#include<bits/stdc++.h>

using namespace std;

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b =temp;
}

int Partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[j],&arr[i]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void QuickSort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi = Partition(arr,low,high);
        QuickSort(arr,low,pi-1);
        QuickSort(arr,pi+1,high);
    }
}

void printArr(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[]={10,4,5,67,-1};
    int n=sizeof(arr)/sizeof(arr[0]);
    QuickSort(arr,0,n-1);
    cout << "\nSorted array ...\n";
    printArr(arr,n);
    return 0;
}
