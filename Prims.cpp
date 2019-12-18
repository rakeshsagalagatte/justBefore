#include<bits/stdc++.h>
#define V 5
using namespace std;

int minKey(int key[],bool merSet[])
{
    int ming=INT_MAX,min_index;
    for(int v=0;v<V;v++)
    {
        if(merSet[v]==false&&key[v]<ming)
        {
            ming=key[v];
            min_index=v;
        }
    }
    return min_index;
}

void printGraph(int graph[][V],int parent[])
{
    cout << "Edges \tWeight\n" ;
    for(int i=1;i<V;i++)
    {
        cout<< parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}


void Prims(int graph[][V])
{
    int key[V],parent[V];
    bool merSet[V];
    for(int i=0;i<V;i++)
    {
        key[i]=INT_MAX;
        merSet[i] = false;
    }
    key[0]=0;
    parent[0]=-1;
    for(int countu=0;countu<V-1;countu++)
    {
        int u = minKey(key,merSet);
        merSet[countu]=true;
        for(int v=0;v<V-1;v++)
        {
            if(graph[u][v] &&graph[u][v] < key[v] && merSet[v]==false)
            {
                key[v] =graph[u][v];
                parent[v]=u;
            }
        }
    }

    printGraph(graph,parent);
}


int main()
{
    int graph[5][5]= {
                         { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 }
                     };
                     Prims(graph);
                     return 0;
}
