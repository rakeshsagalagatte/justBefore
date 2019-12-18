#include<bits/stdc++.h>

using namespace std;

int max(int a,int b)
{
    return ((a>b)?a:b);
}

int kanpSack(int W,int *wt,int *val,int n)
{
    if(n==0||W==0)
        return 0;

    if(wt[n-1]>W)
        return(kanpSack(W,wt,val,n-1));
    else
        return(max(val[n-1] + kanpSack(W-wt[n-1],wt,val,n-1),kanpSack(W,wt,val,n-1)));

}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W=100;
    int n = sizeof(val)/sizeof(val[0]);
    cout << "Knapsack value : " << kanpSack(W,wt,val,n) << endl ;
    return 0;
}
