#include<bits/stdc++.h>

using namespace std;

class Queue{
 public :
     int fron,rear,arr[10000];
     bool emptyQ()
     {
         if(rear==fron)
            return true;
         else
            return false;
     }
     void push(int i)
     {
         rear = rear +1;
         arr[rear]=i;
     }
     void init()
     {
         rear = fron =-1;
     }
     int pop()
     {
         fron = fron +1;
         return arr[fron];
     }
};

void BFS(int **Edges,int n,int sr)
{
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
        visited[i]=false;
    Queue que ;
    que.init();
    visited[sr] =true;
    que.push(sr);
    while(!que.emptyQ())
    {
        int s = que.pop();
        cout << s << endl;
        for(int i=0;i<n;i++)
        {
            if(s==i)
                continue;
            if(Edges[s][i]==1)
            {
                if(visited[i])
                    continue;
                visited[i]=true;
                que.push(i);
            }
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
    for(int i=0;i<e;i++)
    {
        int s,d;
       cin >> s >> d;
       Edges[s][d]=1;
       Edges[d][s] =1;
    }
    cout << "Enter the source vertex : ";
    int sr;
    cin >> sr;
    BFS(Edges,n,sr);

    return 0;
}
