#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of vertices in the graph\n";
    cin>>n;
    int m;
    cout<<"Enter the number of edges in the graph\n";
    cin>>m;
    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout<<"Enter the edges of the graph\n";
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }
    cout<<"The adjacency matrix of the graph is\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}