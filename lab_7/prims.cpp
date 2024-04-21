#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX = 1e3;
int graph[MAX][MAX];
int n;

int prims(vector<string> cities)
{
    int selected[n];
    memset(selected, false, sizeof(selected));
    selected[0] = true;
    int no_edge = 0;
    int x;
    int y;
    int min_cost = 0;
    cout << "cost: ";
    while (no_edge < n - 1)
    {
        int min = INF;
        x = 0;
        y = 0;
        for (int i = 0; i < n; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!selected[j] && graph[i][j])
                    {
                        if (min > graph[i][j])
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << cities[x] << " " << cities[y] << " " << min << endl;
        min_cost += min;
        selected[y] = true;
        no_edge++;
    }
    return min_cost;
}

int main() {
   cout << "Enter the number of cities: ";
    cin >> n;
   cout<<"Enter the names of the cities: "<<endl;
    vector<string> cities(n);
    for(int i = 0; i < n; i++) {
        cin >> cities[i];
    }
    cout<<"Enter the no of the edges: "<<endl;
    int m;
    cin >> m;
    cout<<"Enter the cost of the edges: (city1 city2 cost) "<<endl;
    for(int i = 0; i < m; i++) {
        string city1, city2;
        int cost;
        cin >> city1 >> city2 >> cost;
        int index1 = find(cities.begin(), cities.end(), city1) - cities.begin();
        int index2 = find(cities.begin(), cities.end(), city2) - cities.begin();
        graph[index1][index2] = cost;
        graph[index2][index1] = cost;
    }
    cout << prims(cities) << endl;
    return 0;
}
/*Rationale for Choosing Prim's or Kruskal's Algorithm

Both Prim's and Kruskal's algorithms are used to find the minimum spanning tree in a graph. The choice between the two depends on the specific characteristics of the problem and the graph.

    Prim's Algorithm: This algorithm is efficient when dealing with dense graphs, where the number of edges is significantly larger than the number of vertices. Prim's algorithm adds the smallest edge that connects a node in the tree to a node outside the tree, making it a good choice when the graph is already connected.

    Kruskal's Algorithm: This algorithm is efficient when dealing with sparse graphs, where the number of edges is close to the number of vertices. Kruskal's algorithm adds the smallest edge not in the tree that does not form a cycle, making it a good choice when the graph is disconnected.

Time Complexity Analysis

    Prim's Algorithm: The time complexity of Prim's algorithm is O(V^2) for an adjacency matrix representation of the graph, where V is the number of vertices. If a binary heap and adjacency list representation is used, the time complexity can be reduced to O(E log V), where E is the number of edges.

    Kruskal's Algorithm: The time complexity of Kruskal's algorithm is O(E log E) or O(E log V), as sorting of edges is the most expensive operation. Here, E is the number of edges and V is the number of vertices.

In conclusion, the choice between Prim's and Kruskal's algorithm depends on the specific characteristics of the graph and the problem. If the graph is dense, Prim's algorithm may be more efficient, while if the graph is sparse, Kruskal's algorithm may be more efficient.*/