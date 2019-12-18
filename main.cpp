#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>

using namespace std;
int comp;
int Linear_Search_Asending(int arr[],int key,int n)
{   comp =0;
    for(int i=0;i<n;i++)
    {
        comp++;
        if(key == arr[i])
            return i+1;
    }
    return -1;
}

void Reading_Elements(int arr[],int n)
{
    for(int i=0;i<n;i++)
      arr[i] = rand()%100000;
}

void Sorting_Desending(int arr[],int n)
{
    int key,j;
    for(int i=1;i<n;i++)
    {
        key = arr[i];
        j = i-1;
        while(j>=0&&arr[j]<key)
        {
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1] = key;
    }
}

void Sorting_Asending(int arr[],int n)
{
    for(int key,j,i=1;i<n;i++)
    {
         key = arr[i];
        j = i-1;
        while(j>=0&&arr[j]>key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
          arr[j+1] = key;
    }

}

int Binary_Search_asending(int arr[],int key,int low,int high)
{

    if(high >=1 )
    {   comp++;
        int mid = floorf( (high - low)/2);
        if(key==arr[mid])
        {
            return mid+1;
        }else if(key > arr[mid])
        {
            return(Binary_Search_asending(arr,key,mid+1,high));
        }else
            return(Binary_Search_asending(arr,key,low,mid-1));
    }

    return -1;
}

void Display(int arra[],int n)
{
    cout << "The elements are : ";
    for(int i=0;i<n;i++)
        cout << arra[i] << "\t";
    cout << endl;
}

int main()
{
    srand(time(NULL));
    int arr[100000],n;
    cout << endl << "enter the size of the array : ";
    cin >> n;
    char ch;
    int op,key,rt;
    do{
        cout << "1.Binary search in asending order \n2.Linear Search in asending order\n3.Binary search in desending order \n";
        cout << "4.linear search in desending order \n 5.Exit \n \n Enter the option : ";
        cin >>op;
        switch(op)
        {
            case 1 :  cout << endl << "Reading the array elements .....";
                      Reading_Elements(arr,n);
                      Sorting_Asending(arr,n);
                      cout <<"Printing the elements are ........ " << endl ;
                      Display(arr,n);
                      cout << endl<<  "Enter the key value : ";
                      cin >> key ;
                      rt = Binary_Search_asending(arr,key,0,n);
                      if(rt>-1)
                         cout << "The Key is found at index  : " << rt << endl ;
                      else
                         cout << "The is not found " << endl ;
                      break;
            case 2 :  cout << endl << "Reading the array elements .....";
                      Reading_Elements(arr,n);
                      cout <<"Printing the elements are ........ " << endl ;
                      Display(arr,n);
                      cout << endl<<  "Enter the key value : ";
                      cin >> key ;
                      rt = Linear_Search_Asending(arr,key,n);
                      if(rt>-1)
                         cout << "The Key is found at index  : " << rt << endl ;
                      else
                         cout << "The is not found " << endl ;
                      break;
            case 3 :  cout << endl << "Reading the array elements .....";
                      Reading_Elements(arr,n);
                      Sorting_Desending(arr,n);
                      cout <<"Printing the elements are ........ " << endl ;
                      Display(arr,n);
                      cout << endl<<  "Enter the key value : ";
                      cin >> key ;
                      rt = Binary_Search_asending(arr,key,0,n);
                      if(rt>-1)
                         cout << "The Key is found at index  : " << rt << endl ;
                      else
                         cout << "The is not found " << endl ;
                      break;
            case 4 :   return 0;
        }
        cout << "Do u want to continue : ";
        cin >>ch;
    }while(ch=='Y'||ch=='y');
    return 0;
}
