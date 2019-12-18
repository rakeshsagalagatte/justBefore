#include<bits/stdc++.h>

using namespace std;

void printDfs(int **Edges,int n,int sr,int *visited)
{
    cout << sr << endl;
    visited[sr] = true;
    for(int i=0;i<n;i++)
    {
        if(sr==i)
            continue;
        if(Edges[sr][i]==1)
        {
            if(visited[i])
                continue;
            printDfs(Edges,n,i,visited);
        }
    }
}

int main()
{
    int n,e;
    cout << "Enter vertices and edges \n";
    cin >> n >> e;
    int **Edges = new int*[n];
    cout << "Reading...!"<< endl;
    for(int i=0;i<n;i++)
    {
        Edges[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            Edges[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        int s,d;
       cin >> s >>d;
       Edges[s][d]=1;
       Edges[d][s] =1;
    }
    cout << "Enter the source vertex : ";
    int sr;
    cin >> sr;
    bool *visited = new int[n];
    for(int i=0;i<n;i++)
        visited[i]=false;
    printDfs(Edges,n,sr,visited);
    for(int i=0;i<n;i++)
        delete [] Edges[i];
    delete [] Edges;
    delete [] visited;
    return 0;
}
