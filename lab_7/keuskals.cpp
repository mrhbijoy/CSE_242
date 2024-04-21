#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3;
vector<pair<int, pair<int, int>>> edges;
int parent[MAX];
int n;

int find(int x) {
    if(parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void union_set(int x, int y) {
    parent[find(x)] = find(y);
}

int kruskal(vector<string> cities) {
    sort(edges.begin(), edges.end());
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
    int min_cost = 0;
    cout << "cost: ";
    for(auto e : edges) {
        int w = e.first;
        int x = e.second.first;
        int y = e.second.second;
        if(find(x) != find(y)) {
            cout << cities[x] << " " << cities[y] << " " << w << endl;
            min_cost += w;
            union_set(x, y);
        }
    }
    return min_cost;
}

int main() {
    cout << "Enter the number of cities: ";
    cin >> n;
    cout << "Enter the names of the cities: " << endl;
    vector<string> cities(n);
    for(int i = 0; i < n; i++) {
        cin >> cities[i];
    }
    cout << "Enter the no of the edges: " << endl;
    int m;
    cin >> m;
       cout<<"Enter the cost of the edges: (city1 city2 cost) "<<endl;
    for(int i = 0; i < m; i++) {
        string city1, city2;
        int cost;
        cin >> city1 >> city2 >> cost;
        int index1 = find(cities.begin(), cities.end(), city1) - cities.begin();
        int index2 = find(cities.begin(), cities.end(), city2) - cities.begin();
        edges.push_back({cost, {index1, index2}});
    }
    cout << kruskal(cities) << endl;
    return 0;
}

/*
Report on the Implementation of Kruskal's Algorithm

The provided code is an implementation of Kruskal's algorithm in C++. Kruskal's algorithm is a minimum-spanning-tree algorithm which finds an edge of the least possible weight that connects any two trees in the forest. It is a greedy algorithm in graph theory as it finds a minimum spanning tree for a connected weighted graph adding increasing cost arcs at each step.
Code Explanation

    Data Structures Used: The code uses a vector of strings to store the city names and a vector of pairs to store the edges and their costs. Each pair in the vector edges contains the cost of the connection and a pair of the indices of the cities.

    Input Reading: The code first reads the number of cities and the names of the cities. Then it reads the number of connections and the details of each connection. The details of each connection include the names of the two cities and the cost of the connection. The find function from the STL is used to find the indices of the cities in the cities vector. These indices are then used to create the edges.

    Kruskal's Algorithm: The kruskal function is the implementation of Kruskal's algorithm. It first sorts the edges by cost. Then it iterates over the edges and for each edge, if the cities are not in the same set, it adds the cost to min_cost and merges the sets. The find function is used to find the parent of a city in the disjoint set, and the union_set function is used to merge two sets.

    Output: The function prints the cost and the cities connected by each selected edge, and returns the minimum cost.

Conclusion

This implementation of Kruskal's algorithm efficiently finds the minimum spanning tree of a graph. It uses the disjoint-set data structure to keep track of which vertices are in which connected components, and it uses a priority queue to sort the edges by cost to quickly find the next cheapest edge to add to the minimum spanning tree.

*/