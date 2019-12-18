#include<bits/stdc++.h>

using namespace std;

int findMinvert(int *distance,bool *visited,int n)
{
    int minvert=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i]&&(minvert==-1||distance[i] < distance[minvert]))
            minvert = i;
    }
    return minvert;
}

void dijkstras(int **Edges,int n)
{
    int *distance = new int[n];
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        distance[i]=INT_MAX;
        visited[i]=false;
    }

    distance[0] = 0;

    for(int i=0;i<n-1;i++)
    {
        int minvet=findMinvert(distance,visited,n);
        visited[minvet] = true;
        for(int j=0;j<n;j++)
        {
            if(Edges[minvet][j]!=0&&!visited[j])
            {
                int dist = distance[minvet] + Edges[minvet][j];
                if(dist < distance[j])
                    distance[j] = dist;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout << i << "  " << distance[i] << endl;
    }
    delete [] distance;
    delete [] visited;
}

int main()
{
    int n,e;
    int** Edges = new int*[n];
    cout << "Enter the vertices and edges \n";
    cin >> n >> e;
    for(int i=0;i<n;i++)
    {
        Edges[i] = new int[n];
        for(int j=0;j<n;j++)
            Edges[i][j]=0;
    }

    cout << "Reading ...\n";
    for(int i=0;i<e;i++)
    {
        int s,d,w;
        cin >> s >> d >> w;
        Edges[s][d]=w;
        Edges[d][s] = w;
    }

    dijkstras(Edges,n);
    for(int i=0;i<n;i++)
        delete [] Edges[i];
    delete [] Edges;
    return 0;
}
