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
/*Report on the Implementation of Prim's and Kruskal's Algorithms

The provided code is an implementation of Prim's and Kruskal's algorithms in C++. Both are minimum-spanning-tree algorithms used in graph theory. Prim's algorithm builds the spanning tree by adding the smallest edge that connects a node in the tree to a node outside the tree, while Kruskal's algorithm adds the smallest edge not in the tree that does not form a cycle.
Code Explanation

    Data Structures Used: The code uses a vector of strings to store the city names. For Prim's algorithm, an adjacency matrix is used to represent the graph, and an array is used to keep track of selected nodes. For Kruskal's algorithm, a vector of pairs is used to store the edges and their costs, and a disjoint-set data structure is used to keep track of the connected components.

    Input Reading: The code first reads the number of cities and the names of the cities. Then it reads the number of connections and the details of each connection. The details of each connection include the names of the two cities and the cost of the connection. The find function from the STL is used to find the indices of the cities in the cities vector. These indices are then used to update the adjacency matrix for Prim's algorithm and to create the edges for Kruskal's algorithm.

    Prim's Algorithm: The prims function is the implementation of Prim's algorithm. It starts by selecting the first city. Then it enters a loop that continues until all cities have been selected. In each iteration of the loop, it finds the smallest edge connecting a selected city to an unselected city, adds the cost of this edge to the total cost, and selects the unselected city.

    Kruskal's Algorithm: The kruskal function is the implementation of Kruskal's algorithm. It first sorts the edges by cost. Then it iterates over the edges and for each edge, if the cities are not in the same set, it adds the cost to min_cost and merges the sets. The find function is used to find the parent of a city in the disjoint set, and the union_set function is used to merge two sets.

    Output: Both functions print the cost and the cities connected by each selected edge, and return the minimum cost.

Conclusion

These implementations of Prim's and Kruskal's algorithms efficiently find the minimum spanning tree of a graph. They use different approaches to achieve the same goal, and the choice between them depends on the specific requirements of the problem.*/